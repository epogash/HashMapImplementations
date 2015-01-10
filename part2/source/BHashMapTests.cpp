#include "BHashMap.h"

void insert(){
	BHashMap<int, int>* map = new BHashMap<int, int>();
	std::cout << "/////////Testing Insert Method-ints/////////" << std::endl;
	std::cout << "//Inserting first element//" << std::endl;
	std::cout << "Insertion Worked: " << map->insert(854, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at same hash location//" << std::endl;
	std::cout << "Insertion Worked: " << map->insert(954, 7) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting same key overwrites the key//" << std::endl;
	std::cout << "Insertion Worked: " << map->insert(954, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at different locations//" << std::endl;
	std::cout << "Insertion Worked: " << map->insert(852, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Insertion Worked: " << map->insert(853, 5) << std::endl;
	map->print(std::cout);
	std::cout <<"Insertion Worked: " << map->insert(850, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Insertion Worked: "<< map->insert(851, 5) << std::endl;
	map->print(std::cout);
}

void remove() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing Remove Method-ints/////////" << std::endl;
	std::cout << "//Removing from empty map//" << std::endl;
	std::cout << "Remove Worked: " << map->remove(845, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting then removing an element//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	std::cout << "Remove Worked: " << map->remove(850, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element that doesn't exist//" << std::endl;
	value = 0;
	map->insert(850, 5);
	std::cout << "Remove Worked: " << map->remove(860, value) << std::endl;
	map->print(std::cout);
	map->insert(860, 7);
	std::cout << "Remove Worked: " << map->remove(870, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element when there is more than one in the list//" << std::endl;
	std::cout << "Remove Worked: " << map->remove(860, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void search() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing Search Method-ints/////////" << std::endl;
	std::cout << "//Search for key that doesn't exist-empty map//" << std::endl;
	std::cout << "Key Found: " << map->search(880, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Insert then search for the key//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	std::cout << "Key Found: " << map->search(850, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "Value: " << value << std::endl;
	std::cout << "//Insert then search for the key- more than 1 element//" << std::endl;
	map->insert(870, 7);
	map->print(std::cout);
	std::cout << "Key Found: " << map->search(870, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "//Search for key that doesn't exist//" << std::endl;
	std::cout << "Key Found: " << map->search(880, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void clear() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	std::cout << "/////////Testing Clear Method-ints/////////" << std::endl;
	std::cout << "//Clear empty map//" << std::endl;
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with an element//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with more than 1 element//" << std::endl;
	map->insert(850, 5);
	map->insert(860, 5);
	map->insert(862, 5);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Test if it's empty//" << std::endl;
	std::cout << "Is empty?: ";
	std::cout << map->is_empty() << std::endl;
}

void is_empty() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing is_empty Method-ints/////////" << std::endl;
	std::cout << "//Test if empty on empty map//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is inserted//" << std::endl;
	map->insert(860, 5);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	map->insert(863, 5);
	map->print(std::cout);
	std::cout << "//Test if empty when another element is inserted//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is removed//" << std::endl;
	map->remove(863, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when a nonexistent element is removed//" << std::endl;
	map->remove(863, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when last element is removed//"<< std::endl;
	map->insert(833, 5);
	map->insert(863, 5);
	map->print(std::cout);
	map->remove(863, value);
	map->print(std::cout);
	map->remove(833, value);
	map->print(std::cout);
	map->remove(860, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
}

void capacity() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing capacity Method-ints/////////" << std::endl;
	std::cout << "//Test if capacity changes with insertions and removals//"<< std::endl;
	map->insert(833, 5);
	map->insert(863, 5);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(863, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(863, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(833, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
}

void size() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing size Method-ints/////////" << std::endl;
	std::cout << "//Test if size() is correct with insertions and removals//"<< std::endl;
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(833, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(862, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(864, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(874, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(862, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(862, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(833, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(864, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(874, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
}

void load() {
	BHashMap<int, int>* map = new BHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing load Method-ints/////////" << std::endl;
	std::cout << "//Test if load() is correct with insertions and removals//" << std::endl;
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(833, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(862, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(864, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(874, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(862, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(862, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(833, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(864, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(874, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
}

int main(int argc, char* const argv[]) {
	insert();
	remove();
	search();
	clear();
	is_empty();
	capacity();
	size();
	load();
}

