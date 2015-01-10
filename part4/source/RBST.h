#include <array>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <utility>
#include <algorithm>
#include "math.h"
#include <time.h>
#include <stack>

template<typename S, typename T>
class RBST {
	class Item {
	public:
		S key;
		T value;
		Item(S key, T value) {
			this->key = key;
			this->value = value;
		}
	};

	struct Node {
	public:
		Node() {
			height = 1;
			right = -1;
			left = -1;
			emptyNode = " ";
		}
		int left;
		int right;
		Item* data;
		int height;
		std::string emptyNode;
	};

private:
	std::size_t occupiedSize;
	std::size_t backingArraySize;
	Node* *backingArray;
	int rootIndex;
	int freeListHeadIndex;

	//////////////Key type specific functions/////////////////
	bool cstringsEqual(char const* s1, char const* s2) {
		for (; *s1 == *s2; ++s1, ++s2)
			if (*s1 == 0) {
				return true;
			}
		return false;
	}
	bool stdstringsEqual(std::string first, std::string second) {
		if (first.compare(second) == 0) {
			return true;
		}
		return false;
	}
	bool intsEqual(int first, int second) {
		if (first == second) {
			return true;
		}
		return false;
	}
	bool doublesEqual(double first, double second) {
		if (first == second) {
			return true;
		}
		return false;
	}

	bool cstringsLessThan(char const* s1, char const* s2) {
		for (; *s1 == *s2; ++s1, ++s2) {
			if (*s1 == 0) {
				return false;
			}
		}
		if(*s1 < *s2) {
			return true;
		}
		return false;
	}
	bool stdstringsLessThan(std::string first, std::string second) {
		if (first.compare(second) < 0) {
			return true;
		}
		return false;
	}
	bool intsLessThan(int first, int second) {
		if (first < second) {
			return true;
		}
		return false;
	}
	bool doublesLessThan(double first, double second) {
		if (first < second) {
			return true;
		}
		return false;
	}


	//COMPARE TYPES IN HASH AND EQUALITY FUNCTIONS, CHECKING WHAT TYPE IT IS
	inline bool forward_equals(double a, double b) {
		return doublesEqual(a, b);
	}
	inline bool forward_equals(char const* a, char const* b) {
		return cstringsEqual(a, b);
	}
	inline bool forward_equals(std::string a, std::string b) {
		return stdstringsEqual(a, b);
	}
	inline bool forward_equals(int a, int b) {
		return intsEqual(a, b);
	}

	inline bool forward_less_than(double a, double b) {
		return doublesLessThan(a, b);
	}
	inline bool forward_less_than(char const* a, char const* b) {
		return cstringsLessThan(a, b);
	}
	inline bool forward_less_than(std::string a, std::string b) {
		return stdstringsLessThan(a, b);
	}
	inline bool forward_less_than(int a, int b) {
		return intsLessThan(a, b);
	}

	int getHeight(Node* &n) {
		if (!n) {
			return 0;
		}
		return n->height;
	}
	void setHeight(Node* &n) {
		if (n->left == -1 && n->right == -1) {
			n->height = 1;
			;
		} else if (n->right > -1 && n->left > -1) {
			n->height = 1 + getHeight(backingArray[n->left])
					+ getHeight(backingArray[n->right]);
		} else if (n->right > -1 && n->left == -1) {
			n->height = 1 + getHeight(backingArray[n->right]);
		} else if (n->right == -1 && n->left > -1) {
			n->height = 1 + getHeight(backingArray[n->left]);
		}

	}

	void rotateLeft(int &root) {
		int temp =backingArray[root]->right;
		backingArray[root]->right = backingArray[temp]->left;
		backingArray[temp]->left = root;
		root = temp;

		backingArray[temp]->height = backingArray[root]->height;
		setHeight(backingArray[root]);
	}
	void rotateRight(int &root) {
		int temp = backingArray[root]->left;
		backingArray[root]->left = backingArray[temp]->right;
		backingArray[temp]->right = root;
		root = temp;

		backingArray[temp]->height = backingArray[root]->height;
		setHeight(backingArray[root]);
	}

	void insertAtRoot(int &n, Item* item, int &nodesVisited) {
		if (n == -1) {
			int tempIndex = backingArray[freeListHeadIndex]->left;
			backingArray[freeListHeadIndex]->data = item;
			backingArray[freeListHeadIndex]->left = -1;
			backingArray[freeListHeadIndex]->right = -1;
			n = freeListHeadIndex;
			freeListHeadIndex = tempIndex;
			return;
		}

		if (forward_equals(item->key, backingArray[n]->data->key)) {
			backingArray[n]->data->value = item->value;
			return;
		} else if (forward_less_than(item->key, backingArray[n]->data->key)) {
			++nodesVisited;

			insertAtRoot(backingArray[n]->left, item, nodesVisited);
			rotateRight(n);
		} else {
			++nodesVisited;
			insertAtRoot(backingArray[n]->right, item, nodesVisited);
			rotateLeft(n);
		}
	}

	int join(int a, int b) {
		if (a == -1) {
			return b;
		}
		if (b == -1) {
			return a;
		}
		if (rand() % (backingArray[a]->height + backingArray[b]->height)
				< (backingArray[a]->height)) {
			backingArray[a]->right = join(backingArray[a]->right, b);
			setHeight(backingArray[a]);
			return a;
		} else {
			backingArray[b]->left = join(a, backingArray[b]->left);
			setHeight(backingArray[b]);
			return b;
		}
	}

	int height(Node* t) {
		int left = 0;
		int right = 0;
		if (t == NULL) {
			return 1;
		}
		if (!(t->left == -1)) {
			left = height(backingArray[t->left]);
		}
		if(!(t->right == -1)) {
			right = height(backingArray[t->right]);
		}
		if(left > right){
			return 1 + left;
		}
		return 1 + right;
	}
	int bstHeight(Node *t) {
		if (!t)
			return 0;
		int left = 0;
		int right = 0;
		if (!t->left == -1) {
			left = bstHeight(backingArray[t->left]);
		}
		if (!t->right == -1) {
			right = bstHeight(backingArray[t->right]);
		}
		return (left > right) ? left + 1 : right + 1;
	}
	void printnode(S key, int h) {
		for (int i = 0; i < h; i++){
			if(i == h - 3){
				std::cout << "+";
			} else if(i > h - 3 && (h-3) > 0){
				std::cout << "-";
			} else {
				std::cout << " ";
			}

		}
		std::cout << "[" << key << "]"<< std::endl;
	}

	void printNodeString(std::string str, int h) {
		bool inserted = false;
		for (int i = 0; i < h; i++){

			if(i == h - 3 && !inserted) {
				std::cout << "|";
				inserted = true;
			} else {
				std::cout << " ";
			}
		}
		std::cout <<  std::endl;
	}

	void show(Node* t, int h) {
		std::string str = " ";
		if (t == NULL || !t->data) {
			printNodeString(str, h - 3);
			return;
		}
		if(t->right > -1) {
			show(backingArray[t->right], h + 3);
		} else if (t->right == -1) {
			show(0, h + 3);
		}
		printnode(t->data->key, h);
		if (t->left > -1) {
			show(backingArray[t->left], h + 3);
		} else if (t->left == -1) {
			show(0, h + 3);
		}
	}
public:

	RBST() {
		rootIndex = -1;
		freeListHeadIndex = 0;
		occupiedSize = 0;
		backingArraySize = 5;
		backingArray = new Node*[backingArraySize];
		for (int i = 0; i < backingArraySize; i++) {
			backingArray[i] = new Node();
		}
		for (int i = 0; i < backingArraySize - 1; i++) {
			backingArray[i]->left = i + 1;
			backingArray[i]->right = -1;
		}
		backingArray[backingArraySize - 1]->right = -1;
		backingArray[backingArraySize - 1]->left = -1;
	}

	RBST(int capacity) {
		rootIndex = -1;
		freeListHeadIndex = 0;
		occupiedSize = 0;
		backingArraySize = capacity;
		backingArray = new Node*[backingArraySize];
		for (int i = 0; i < backingArraySize; i++) {
			backingArray[i] = new Node();
		}
		for (int i = 0; i < backingArraySize - 1; i++) {
			backingArray[i]->left = i + 1;
			backingArray[i]->right = -1;
		}
		backingArray[backingArraySize - 1]->right = -1;
		backingArray[backingArraySize - 1]->left = -1;

	}

	int insert(S key, T value) {
		Item* itemToInsert = new Item(key, value);
		if (backingArraySize == 0 || occupiedSize == backingArraySize) {
			return 0;
		}
		if ((rootIndex == -1 && backingArraySize > 0)
				|| (occupiedSize == 0 && backingArraySize > 0)) {
			rootIndex = 0;
			backingArray[0]->data = itemToInsert;
			backingArray[0]->left = -1;
			backingArray[0]->right = -1;
			freeListHeadIndex = 1;
			occupiedSize++;
			return 1;
		}
		int nodesVisited = 1;
		int tempRootIndex = rootIndex;
		while (tempRootIndex > -1 && backingArray[tempRootIndex] && backingArray[tempRootIndex]->data) {
			if (forward_equals(key, backingArray[tempRootIndex]->data->key)) {
				backingArray[tempRootIndex]->data = itemToInsert;
				return nodesVisited;

			} else if ((rand() % (backingArray[tempRootIndex]->height + 1))
					== 0) {
				nodesVisited++;
				occupiedSize++;
				insertAtRoot(rootIndex, itemToInsert, nodesVisited);
				return nodesVisited;

			} else if (forward_less_than(key, backingArray[tempRootIndex]->data->key)) {
				nodesVisited++;
				if (backingArray[tempRootIndex]->left > -1) {
					tempRootIndex = backingArray[tempRootIndex]->left;
				} else {
					if (freeListHeadIndex == -1) {
						return -1 * nodesVisited;
					}
					int tempIndex = backingArray[freeListHeadIndex]->left;

					backingArray[tempRootIndex]->left = freeListHeadIndex;

					backingArray[freeListHeadIndex]->data = itemToInsert;
					backingArray[freeListHeadIndex]->left = -1;
					backingArray[freeListHeadIndex]->right = -1;

					setHeight(backingArray[freeListHeadIndex]);
					freeListHeadIndex = tempIndex;
					break;
				}
			} else {
				nodesVisited++;
				if (backingArray[tempRootIndex]->right > -1) {
					tempRootIndex = backingArray[tempRootIndex]->right;
				} else {
					if (freeListHeadIndex == -1) {
						return -1 * nodesVisited;
					}
					int tempIndex = backingArray[freeListHeadIndex]->left;

					backingArray[tempRootIndex]->right = freeListHeadIndex;

					backingArray[freeListHeadIndex]->data = itemToInsert;
					backingArray[freeListHeadIndex]->left = -1;
					backingArray[freeListHeadIndex]->right = -1;

					setHeight(backingArray[freeListHeadIndex]);
					freeListHeadIndex = tempIndex;
					break;
				}
			}
		}
		occupiedSize++;
		return nodesVisited;
	}

	int remove(S key, T &value) {
		int nodesVisited = 0;
		if (backingArraySize == 0 || rootIndex == -1) {
			return 0;
		}
		if (occupiedSize == 1 && forward_equals(key, backingArray[rootIndex]->data->key)) {
			value = backingArray[rootIndex]->data->value;
			rootIndex = -1;
			freeListHeadIndex = 0;
			occupiedSize = 0;
			for (int i = 0; i < backingArraySize - 1; i++) {
				backingArray[i]->left = i + 1;
				backingArray[i]->right = -1;
			}
			backingArray[backingArraySize - 1]->right = -1;
			backingArray[backingArraySize - 1]->left = -1;
			return 1;
		}
		if(occupiedSize == 1 && !forward_equals(key, backingArray[rootIndex]->data->key)){
			return -1;
		}
		bool leftTaken = false;
		int tempRootIndex = rootIndex;
		int parentIndex = -1;
		while (tempRootIndex != -1 && backingArray[tempRootIndex]
				&& backingArray[tempRootIndex]->data->key != key) {
			nodesVisited++;
			leftTaken = backingArray[tempRootIndex]->data->key > key;
			if (leftTaken) {
				parentIndex = tempRootIndex;
				tempRootIndex = backingArray[tempRootIndex]->left;
			} else {
				parentIndex = tempRootIndex;
				tempRootIndex = backingArray[tempRootIndex]->right;
			}
		}
		if (tempRootIndex == -1) {
			return nodesVisited * -1;
		} else if (parentIndex == -1) {
			rootIndex = join(backingArray[tempRootIndex]->left,
					backingArray[tempRootIndex]->right);
		} else {
			if (!leftTaken) {
				backingArray[parentIndex]->right = join(
						backingArray[tempRootIndex]->left,
						backingArray[tempRootIndex]->right);
			} else {
				backingArray[parentIndex]->left = join(
						backingArray[tempRootIndex]->left,
						backingArray[tempRootIndex]->right);
			}
		}
		value = backingArray[tempRootIndex]->data->value;
		backingArray[tempRootIndex]->right = -1;
		backingArray[tempRootIndex]->left = freeListHeadIndex;
		freeListHeadIndex = tempRootIndex;
		occupiedSize--;
		return nodesVisited;
	}

	int search(S key, T &value) {
		//MAKE LESS THAN FORWARD
		int nodesVisited = 0;
		if (backingArraySize == 0 || rootIndex == -1) {
			return -1 * nodesVisited;
		}

		int tempRootIndex = rootIndex;
		while (tempRootIndex > - 1 && backingArray[tempRootIndex] && backingArray[tempRootIndex]->data) {
			nodesVisited++;
			if (forward_equals(key, backingArray[tempRootIndex]->data->key)) {
				value = backingArray[tempRootIndex]->data->value;
				return nodesVisited;
			} else if (forward_less_than(key, backingArray[tempRootIndex]->data->key)) {
				tempRootIndex = backingArray[tempRootIndex]->left;
			} else {
				tempRootIndex = backingArray[tempRootIndex]->right;
			}
		}
		return nodesVisited * -1;
	}

	void clear() {
		rootIndex = -1;
		freeListHeadIndex = 0;
		backingArray = new Node*[backingArraySize];
		for (int i = 0; i < backingArraySize; i++) {
			backingArray[i] = new Node();
		}
		for (int i = 0; i < backingArraySize - 1; i++) {
			backingArray[i]->left = i + 1;
			backingArray[i]->right = -1;
		}
		backingArray[backingArraySize - 1]->right = -1;
		backingArray[backingArraySize - 1]->left = -1;
		occupiedSize = 0;
	}

	bool is_empty() {
		if (occupiedSize == 0) {
			return true;
		}
		return false;
	}

	std::size_t capacity() {
		return backingArraySize;
	}

	std::size_t size() {
		return occupiedSize;
	}

	double load() {
		if (capacity() == 0) {
			return 0;
		}
		return (double) size() / capacity();
	}


	std::ostream& print(std::ostream& out) {
		//FOR BONUS: ALMOST COMPELTELY IMPLEMENTED, UNCOMMENT TO SEE
//		Node* n = backingArray[rootIndex];
//		int x = height(backingArray[rootIndex]);
//		show(n, x);
//		std::cout << std::endl;
//		return std::cout;
		if (rootIndex == -1) {
			return std::cout;
		}
		std::queue<int>* queue = new std::queue<int>();
		int treeHeight = height(backingArray[rootIndex]);
		int elements = pow(2, treeHeight) - 1;
		int count = 0;
		int left;
		int right;
		int front;
		queue->push(rootIndex);
		while (queue->size() && count < elements) {
			front = queue->front();
			queue->pop();
			if(front == -1) {
				queue->push(-1);
				queue->push(-1);
				std::cout << "- ";
				count++;
			} else {
				left = backingArray[front]->left;
				right = backingArray[front]->right;
				queue->push(left);
				queue->push(right);
				count++;
				std::cout << backingArray[front]->data->key << " ";
			}
		}
		std::cout << std::endl;
		return std::cout;
	}

	//height of whole tree minus number of iterations to get to that node
	//level order traverse, if the one about to be pushed has no children, get height of it and push onto vector pair, then sort
	//using bottom level leaf nodes as height 0
	std::vector<std::pair<int, int>> cluster_distribution() {
		std::vector<std::pair<int, int>> vector;
		std::queue<Node*> queue;
		if (rootIndex == -1 || occupiedSize ==0) {
			vector.push_back(std::make_pair(-1, 1));
			return vector;
		}
		if(occupiedSize == 1) {
			vector.push_back(std::make_pair(0, 1));
			return vector;
		}
		queue.push(backingArray[rootIndex]);
		int treeHeight = height(backingArray[rootIndex]);
		T value;
		while (queue.size() > 0) {
			Node *n = queue.front();
			queue.pop();
			if (n->left > -1) {
				queue.push(backingArray[n->left]);
				//height, #
				if (backingArray[n->left]->left == -1
						&& backingArray[n->left]->right == -1) {
					int level = search(backingArray[n->left]->data->key, value);
					int nodeHeight = treeHeight - level;
					vector.push_back(std::make_pair(nodeHeight, 1));
				}
			}
			if (n->right > -1) {
				queue.push(backingArray[n->right]);
				if (backingArray[n->right]->left == -1
						&& backingArray[n->right]->right == -1) {
					int level = search(backingArray[n->right]->data->key, value);
					int nodeHeight = treeHeight - level;
					vector.push_back(std::make_pair(nodeHeight, 1));
				}
			}
		}
		//sort vector
		std::sort(vector.begin(), vector.end());
		//combine clusters of same size
		//height, #
		for (int i = 0; i < vector.size() - 1; i++) {
			if (i == vector.size() - 1) {
				break;
			}
			if (vector[i].first == vector[i + 1].first) {
				vector[i].second += 1;
				vector.erase(vector.begin() + (i + 1));
				--i;
			}
		}
		return vector;
	}

	S remove_random() {
		if (rootIndex == -1 || !(occupiedSize > 0)) {
			throw std::logic_error("can't remove from empty tree");
		}
		srand(time(NULL));
		int r = 1 + (rand() % (occupiedSize));

		std::stack<Node*> s;
		Node *n = backingArray[rootIndex];
		bool finished = false;
		int count = 0;
		S keyToReturn;
		while (!finished) {
			if (n) {
				s.push(n);
				if(n->left > -1) {
					n = backingArray[n->left];
				} else {
					n = NULL;
				}

			} else {
				if (s.empty()) {
					finished = true;
				} else {
					count++;
					n = s.top();
					s.pop();
					if (count == r) {
						keyToReturn = n->data->key;
						break;
					}
					if (n->right > -1) {
						n = backingArray[n->right];
					} else {
						n = NULL;
					}
				}
			}
		}
		T value;
		remove(keyToReturn, value);
		return keyToReturn;
	}
};
