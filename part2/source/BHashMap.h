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

template<typename S, typename T>
class BHashMap {
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
	int hash(int key) {
		return key % backingArraySize;
	}
private:
	std::size_t occupiedSize;
	static const std::size_t backingArraySize = 5;
	LinkedList *backingArray[backingArraySize] = { };

public:
	//initialize with array of Linked Lists
	BHashMap() {
		occupiedSize = 0;
		for (int i = 0; i < backingArraySize; i++) {
			backingArray[i] = new LinkedList();
		}
	}

	bool insert(S key, T value) {
		Item* itemToInsert = new Item(key, value);
		int i = hash(key);
		Node* newNode = new Node();
		newNode->data = itemToInsert;
		if (!backingArray[i]->head) {
			backingArray[i]->head = newNode;
			newNode->next = NULL;
			backingArray[i]->size++;
			occupiedSize++;
		} else {
			Node* temp = backingArray[i]->head;
			if (backingArray[i]->head->data->key == key) {
				newNode->next = temp->next;
				delete temp;
				backingArray[i]->head = newNode;
			} else {
				while (temp->next && temp->next->data->key != key) {
					temp = temp->next;
				}
				if (temp->next && temp->next->data->key == key) {
					newNode->next = temp->next->next;
					temp->next = newNode;
				} else {
					temp->next = newNode;
					newNode->next = NULL;

					backingArray[i]->size++;
					occupiedSize++;
				}
			}
		}
		return true;
	}

	bool remove(S key, T &value) {
		int i = hash(key);
		if (backingArray[i]->size == 0) {
			return false;
		}
		Node* temp = backingArray[i]->head;
		if (backingArray[i]->size == 1) {
			if (backingArray[i]->head->data->key != key) {
				return false;
			}
			value = backingArray[i]->head->data->value;
			backingArray[i]->head = NULL;
			backingArray[i]->size--;
			occupiedSize--;
			return true;
		}
		if (backingArray[i]->head->data->key == key) {
			value = backingArray[i]->head->data->value;
			Node* nodeToDelete = backingArray[i]->head;
			backingArray[i]->head = backingArray[i]->head->next;
			backingArray[i]->size--;
			occupiedSize--;
			delete nodeToDelete;
			return true;
		}

		while (temp->next && temp->next->data->key != key) {
			temp = temp->next; //advance to the position 1 less than the node to be removed
		}
		if (!temp->next) { //key not found
			return false;
		}
		Node* nodeToDelete = temp->next;
		value = temp->next->data->value;
		temp->next = temp->next->next; //set the next node to be the next node of the node that is being removed
		delete nodeToDelete;

		backingArray[i]->size--;
		occupiedSize--;
		return true;
	}

	bool search(S key, T &value) {
		int i = hash(key);
		if (backingArray[i]->size == 0) {
			return false;
		}
		Node* temp = backingArray[i]->head;
		while (temp) {
			if (key == temp->data->key) {
				value = temp->data->value;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	void clear() {
		for (int i = 0; i < backingArraySize; i++) {
			if (!backingArray[i]->head) {
				//do nothing
			} else if (backingArray[i]->size == 1) {
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
		return (double) size() / capacity();
	}

	std::ostream& print(std::ostream& out) const {
		for (int i = 0; i < backingArraySize; i++) {
			if (backingArray[i]->head != NULL) {
				out << "(";
				Node* temp = backingArray[i]->head;
				while (temp) {
					out << temp->data->key;
					if (temp->next) {
						out << ",";
					}
					temp = temp->next;
				}
				out << ") ";
			} else {
				out << "- ";
			}
		}
		out << std::endl;
		return out;
	}

};
