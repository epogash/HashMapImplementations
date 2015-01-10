
#include <array>
#include <cstddef>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <time.h>
#include <utility>
#include <tr1/functional>
#include <string>
#include <unordered_map>

template<typename S, typename T>
class RehashingHashMap {

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

	//////////////Key type specific functions/////////////////
	int doubleHash(double key) {
		return (int) key % backingArraySize;
	}
	int doubleHash2(double key) {
		return 1 + ((int) key % (backingArraySize - 1));
	}

	int intHash(int key) {
		return key % backingArraySize;
	}
	int intHash2(int key) {
		return 1 + (key % (backingArraySize - 1));
	}
	int cstringHash(char const*  key) {
		int i = 0;
		while (*key) {
			i ^= *key++;
		}
		return i % backingArraySize;
	}
	int cstringHash2(char const* key) {
		int i = 0;
		while (*key) {
			i ^= *key++;
		}
		return 1 + (i % (backingArraySize - 1));
	}
	int stdstringHash(std::string key) {
		std::tr1::hash<std::string> l;
		int str_hash = l(key);
		return str_hash % backingArraySize;
	}

	int stdstringHash2(std::string key) {
		std::tr1::hash<std::string> l;
		int str_hash = l(key);
		return 1 + (str_hash % (backingArraySize - 1));
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

	inline int forward_hash2(char const* a) { return cstringHash2(a); }
	inline int forward_hash2(double a) { return doubleHash2(a); }
	inline int forward_hash2(std::string a) { return stdstringHash2(a); }
	inline int forward_hash2(int a) { return intHash2(a); }

public:
	RehashingHashMap() {
		occupiedSize = 0;
	}

	int insert(S key, T value) {
		Item* itemToInsert = new Item(key,value);
		int hashed = forward_hash(key);
		int index = hashed;
		int i = 0;
		int probes = 1;
		while(isOccupiedArray[index] == 1 && !forward_equals(backingArray[index]->key,key)) {
			++probes;
			++i;
			index = (hashed + (i * forward_hash2(i))) % backingArraySize;

			if (i == backingArraySize) {
				return -1 * probes; //array is full
			}
		}
		if (isOccupiedArray[index] == 0) {
			occupiedSize++;
		}
		backingArray[index] = itemToInsert;
		isOccupiedArray[index] = 1;
		return probes;
	}

	int remove(S key, T &value) {
		if(size() == 0) {
			return false;
		}

		int hashed = forward_hash(key);
		int index = hashed;
		int i = 0;
		int probes = 1;
		while(isOccupiedArray[index] == 1 && !forward_equals(backingArray[index]->key,key)) {
			++probes;
			++i;
			index = (hashed + (i * forward_hash2(i))) % backingArraySize;

			if(i == backingArraySize) {
				return -1 * probes; //key not found
			}
		}
		if(isOccupiedArray[index] == 0) {
			return -1 * probes; //key not found
		}
		value = backingArray[index]->value;
		isOccupiedArray[index] = 0;
		occupiedSize--;
		//increment index to move the rest of the cluster
		++i;
		index = (hashed + (i * forward_hash2(i))) % backingArraySize;

		while(isOccupiedArray[index] == 1){


			Item* itemToReinsert = backingArray[index];
			isOccupiedArray[index] = 0;
			insert(itemToReinsert->key, itemToReinsert->value);
			occupiedSize--;
			++i;
			index = (hashed + (i * forward_hash2(i))) % backingArraySize;

			if(i == backingArraySize) {
				break;
			}
		}
		return probes;
	}

	int search(S key, T &value) {
		if(size() == 0) {
			return 0;
		}
		int hashed = forward_hash(key);
		int index = hashed;
		int i = 0;
		int probes = 1;
		while (isOccupiedArray[index] == 1 && !forward_equals(backingArray[index]->key,key)) {
			++probes;
			++i;
			index = (hashed + (i * forward_hash2(i))) % backingArraySize;

			if (i == backingArraySize) {
				return -1 * probes; //key not found
			}
		}
		if (isOccupiedArray[index] == 0) {
			return -1 * probes; //key not found
		}
		value = backingArray[index]->value;
		return probes;
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

	std::vector<std::pair<int,int>> cluster_distribution() {
		//advance to first empty slot, mark start index; if there isn't en empty slot, return (1,size)
		//start at next slot, incrementing count until next empty value, up until hit the start index
		std::vector<std::pair<int,int>> result;
		if(size() == 0) {
			throw std::logic_error("Cannot show cluster distribution when there are no elements in the map");
		}
		int i = 0;
		while (i < backingArraySize) {
			if (!isOccupiedArray[i]) {
				break;
			}
			i++;
			if(i == backingArraySize) {
				int size = backingArraySize;
				std::pair <int,int> pair = std::make_pair(size, 1);
				result.push_back(pair);
				return result;
			}
		}
		int startIndex = i++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            ;
		int j = 0;
		while(i != startIndex) {
			if(isOccupiedArray[i]) {
				j++;
			}
			if (!isOccupiedArray[i]) {
				if(j > 0) {
					std::pair<int, int> pair = std::make_pair(j, 1);
					j = 0;
					result.push_back(pair);
				}
			}
			++i;
			if(i == backingArraySize) {
				i = 0;
			}
		}
		if (j > 0) {
			std::pair<int, int> pair = std::make_pair(j, 1);
			result.push_back(pair);
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
		srand(time(NULL) );
		int r = 1 + (rand() % (backingArraySize));
		r = r - 1;
		if(!backingArray[r]) {
			throw std::logic_error("Can't remove from an empty slot");
		}
		S key = backingArray[r]->key;
		T value;
		remove(key, value);
		return key;
	}
};
