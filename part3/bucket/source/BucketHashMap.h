/*
 * Main.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: Eric
 */

#include <array>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <tr1/functional>
#include <time.h>
#include <utility>
#include <stdlib.h>
#include <algorithm>

template<typename S, typename T>
class BucketHashMap {
	class Item{
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
		Node* next;
		Item* data;
	};

	class LinkedList {
	public:
		std::size_t size;
		Node* head;
		Node* tail;
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}
	};
private:
	std::size_t occupiedSize;
	static const std::size_t backingArraySize = 5;
	LinkedList *backingArray[backingArraySize] = {};

	//////////////Key type specific functions/////////////////
	int doubleHash(double key) {
		return (int) key % backingArraySize;
	}
	int intHash(int key) {
		return key % backingArraySize;
	}
	int cstringHash(char const*  key) {
		int i = 0;
		while (*key) {
			i ^= *key++;
		}
		return i % backingArraySize;
	}
	int stdstringHash(std::string key) {
		std::tr1::hash<std::string> l;
		int str_hash = l(key);
		return str_hash % backingArraySize;
	}

	bool cstringsEqual(char const* s1, char const* s2 ) {
		for (; *s1 == *s2; ++s1, ++s2)
			if (*s1 == 0){
				return true;
			}
		return false;
	}
	bool stdstringsEqual(std::string first, std::string second) {
		if(first.compare(second) == 0) {
			return true;
		}
		return false;
	}
	bool intsEqual(int first, int second) {
		if(first == second) {
			return true;
		}
		return false;
	}
	bool doublesEqual(double first, double second) {
		if(first == second) {
			return true;
		}
		return false;
	}

	//COMPARE TYPES IN HASH AND EQUALITY FUNCTIONS, CHECKING WHAT TYPE IT IS
	inline bool forward_equals(double a, double b) { return doublesEqual(a, b); }
	inline bool forward_equals(char const* a, char const* b) { return cstringsEqual(a, b); }
	inline bool forward_equals(std::string a, std::string b) { return stdstringsEqual(a, b); }
	inline bool forward_equals(int a, int b) { return intsEqual(a, b); }

	inline int forward_hash(int a) { return intHash(a); }
	inline int forward_hash(double a) { return doubleHash(a); }
	inline int forward_hash(std::string a) { return stdstringHash(a); }
	inline int forward_hash(char const* a) { return cstringHash(a); }

public:
	//initialize with array of Linked Lists
	BucketHashMap() {
		occupiedSize = 0;
		for(int i = 0; i < backingArraySize; i++) {
			backingArray[i] = new LinkedList();
		}
	}

	int insert(S key, T value) {
		Item* itemToInsert = new Item(key,value);
		int i = forward_hash(key);
		Node* newNode = new Node();
		newNode->data = itemToInsert;
		int probes = 1;
		if (!backingArray[i]->head) {
			backingArray[i]->head = newNode;
			newNode->next = NULL;
			backingArray[i]->size++;
			occupiedSize++;
		} else {
			Node* temp = backingArray[i]->head;
			if(forward_equals(backingArray[i]->head->data->key, key)) {
				newNode->next = temp->next;
				delete temp;
				backingArray[i]->head = newNode;
			} else {
				while (temp->next && !forward_equals(temp->next->data->key, key)) {
					temp = temp->next;
					probes++;
				}
				if(temp->next && forward_equals(temp->next->data->key, key)) {
					newNode->next = temp->next->next;
					temp->next = newNode;
				} else {
					temp->next = newNode;
					newNode->next = NULL;

					backingArray[i]->size++;
					occupiedSize++;
				}
				probes++;
			}
		}
		return probes;
	}

	int remove(S key, T &value) {
		int i = forward_hash(key);
		if (backingArray[i]->size == 0) {
			return 0;
		}
		Node* temp = backingArray[i]->head;
		if (backingArray[i]->size == 1) {
			if(!forward_equals(backingArray[i]->head->data->key, key)) {
				return -1;
			}
			value = backingArray[i]->head->data->value;
			backingArray[i]->head = NULL;
			backingArray[i]->size--;
			occupiedSize--;
			return 1;
		}
		if (forward_equals(backingArray[i]->head->data->key, key)) {
			value = backingArray[i]->head->data->value;
			Node* nodeToDelete = backingArray[i]->head;
			backingArray[i]->head = backingArray[i]->head->next;
			backingArray[i]->size--;
			occupiedSize--;
			delete nodeToDelete;
			return 1;
		}

		int probes = 1;
		while (temp->next && !forward_equals(temp->next->data->key, key)) {
			temp = temp->next; //advance to the position 1 less than the node to be removed
			probes++;
		}
		if(!temp->next) {	//key not found
			return -1 * probes;
		}
		Node* nodeToDelete = temp->next;
		value = temp->next->data->value;
		probes++;
		temp->next = temp->next->next; //set the next node to be the next node of the node that is being removed
		delete nodeToDelete;

		backingArray[i]->size--;
		occupiedSize--;
		return probes;
	}

	int search(S key, T &value) {
		int i = forward_hash(key);
		int probes = 0;
		if (backingArray[i]->size == 0) {
			return -1 * probes;
		}
		Node* temp = backingArray[i]->head;
		probes++;
		while(temp) {
			if(forward_equals(key, temp->data->key)) {
				value = temp->data->value;
				return probes;
			}
			probes++;
			temp = temp->next;
		}
		return -1 * probes;
	}

	void clear() {
		for (int i = 0; i < backingArraySize; i++) {
			if (!backingArray[i]->head) {
				//do nothing
			}else if (backingArray[i]->size == 1) {
				backingArray[i]->head = NULL;
			} else {
				Node* temp = backingArray[i]->head;
				Node* nodeToDelete;
				temp = temp->next;
				while (temp) {
					nodeToDelete = backingArray[i]->head;
					backingArray[i]->head = temp;
					delete nodeToDelete;
					temp = temp->next;
				}
				backingArray[i]->head = NULL;
			}
			backingArray[i]->size = 0;
		}
		occupiedSize = 0;
	}

	bool is_empty() {
		if(occupiedSize == 0) {
			return true;
		}
		return false;
	}

	std::size_t capacity()  {
		return backingArraySize;
	}

	std::size_t size()  {
		return occupiedSize;
	}

	double load() {
		return (double) size() / capacity();
	}

	std::ostream& print(std::ostream& out) const {
		for(int i = 0; i < backingArraySize; i ++) {
			if(backingArray[i]->head != NULL) {
				out << "(";
				Node* temp = backingArray[i]->head;
				while(temp) {
					out << temp->data->key;
					if(temp->next) {
						out << ",";
					}
					temp = temp->next;
				}
				out << ") ";
			}
			else {
				out << "- ";
			}
		}
		out << std::endl;
		return out;
	}

	std::vector<std::pair<int,int>> cluster_distribution() {
		//clusters are all the linked lists based on their sizes
		std::vector<std::pair<int,int>> result;
		if(size() == 0) {
			throw std::logic_error("Cannot show cluster distribution when there are no elements in the map");
		}
		int j = 0;
		for(int i = 0; i < backingArraySize; i++) {
			j = backingArray[i]->size;
			if (j > 0) {
				std::pair<int, int> pair = std::make_pair(j, 1);
				result.push_back(pair);
				j = 0;
			}
		}
		//sort vector
		std::sort(result.begin(), result.end());
		//combine clusters of same size
		//size, #
		for(int i = 0; i < result.size() - 1; i++) {
			if(i == result.size() - 1) {
				break;
			}
			if(result[i].first == result[i+1].first) {
				result[i].second += 1;
				result.erase(result.begin() + (i + 1));
				--i;
			}
		}

		return result;
	}

	S remove_random() {
		if(!(occupiedSize > 0)) {
			throw std::logic_error("can't remove from empty list");
		}
		srand(time(NULL) );
		int r = 1 + (rand() % (occupiedSize));
		r = r - 1;
		int i = backingArray[0]->size;
		int j = 1;
		int index = r;
		if(i < r + 1) {
			index -= backingArray[0]->size;
		}
		while(i < r + 1) {
			i += backingArray[j]->size;
			index -= backingArray[j]->size;
			++j;
		}
		--j;
		int count = 0;
		Node* temp = backingArray[j]->head;
		while(count < index) {
			temp = temp->next;
			count++;
		}

		S key = temp->data->key;
		T value;
		remove(key, value);
		return key;
	}
};
