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
class OAHashMap {
	class Item{
	public:
		S key;
		T value;
		Item(S key, T value) {
			this->key = key;
			this->value = value;
		}
	};
private:
	std::size_t occupiedSize;
	static const std::size_t backingArraySize = 5;
	Item *backingArray[backingArraySize] = {};
	int isOccupiedArray[backingArraySize] = {0};

	int linear_probe(int i) {
		return i;
	}
	int hash(int key) {
		return key % backingArraySize;
	}
	public:
		OAHashMap() {
			occupiedSize = 0;
		}
		bool insert(S key, T value) {
			Item* itemToInsert = new Item(key,value);
			int hashed = hash(key);
			int index = hashed;
			int i = 0;
			while(isOccupiedArray[index] == 1 && backingArray[index]->key != key) {
				++i;
				index = (hashed + (i * linear_probe(i))) % backingArraySize;

				if (i == backingArraySize) {
					return false; //array is full
				}
			}
			if (isOccupiedArray[index] == 0) {
				occupiedSize++;
			}
			backingArray[index] = itemToInsert;
			isOccupiedArray[index] = 1;
			return true;
		}

		bool remove(S key, T &value) {
			if(size() == 0) {
				return false;
			}

			int hashed = hash(key);
			int index = hashed;
			int i = 0;
			while(isOccupiedArray[index] == 1 && backingArray[index]->key != key) {
				++i;
				index = (hashed + (i * linear_probe(i))) % backingArraySize;

				if(i == backingArraySize) {
					return false; //key not found
				}
			}
			if(isOccupiedArray[index] == 0) {
				return false; //key not found
			}
			value = backingArray[index]->value;
			isOccupiedArray[index] = 0;
			occupiedSize--;
			//increment index to move the rest of the cluster
			++i;
			index = (hashed + (i * linear_probe(i))) % backingArraySize;

			while(isOccupiedArray[index] == 1){


				Item* itemToReinsert = backingArray[index];
				isOccupiedArray[index] = 0;
				insert(itemToReinsert->key, itemToReinsert->value);
				occupiedSize--;
				++i;
				index = (hashed + (i * linear_probe(i))) % backingArraySize;

				if(i == backingArraySize) {
					break;
				}
			}
			return true;
		}

		bool search(S key, T &value) {
			if(size() == 0) {
				return 0;
			}
			int hashed = hash(key);
			int index = hashed;
			int i = 0;
			while (isOccupiedArray[index] == 1 && backingArray[index]->key != key) {
				++i;
				index = (hashed + (i * linear_probe(i))) % backingArraySize;

				if (i == backingArraySize) {
					return false; //key not found
				}
			}
			if (isOccupiedArray[index] == 0) {
				return false; //key not found
			}
			value = backingArray[index]->value;
			return true;
		}

		void clear() {
			for(int i = 0; i < backingArraySize; i++) {
				isOccupiedArray[i] = 0;
				backingArray[i] = NULL;
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
			for(int i = 0; i < backingArraySize; i++) {
				if(isOccupiedArray[i]) {
					out << backingArray[i]->key << " ";
				}
				else {
					out << "- ";
				}
			}
			out << std::endl;
			return out;
		}

};
