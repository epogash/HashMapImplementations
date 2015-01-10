#include "BucketHashMap.h"

void insert(){
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
	std::cout << "/////////Testing Insert Method-ints/////////" << std::endl;
	std::cout << "//Inserting first element//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(854, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at same hash location//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(954, 7) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting same key overwrites the key//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(954, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at different locations//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(852, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(853, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(850, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(851, 5) << std::endl;
	map->print(std::cout);
}

void remove() {
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing Remove Method-ints/////////" << std::endl;
	std::cout << "//Removing from empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(845, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting then removing an element//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->remove(850, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element that doesn't exist//" << std::endl;
	value = 0;
	map->insert(850, 5);
	std::cout << "Probe attempts: " << map->remove(860, value) << std::endl;
	map->print(std::cout);
	map->insert(860, 7);
	std::cout << "Probe attempts: " << map->remove(870, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element when there is more than one in the list//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(860, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void search() {
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
	int value = 0;
	std::cout << "/////////Testing Search Method-ints/////////" << std::endl;
	std::cout << "//Search for key that doesn't exist-empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->search(880, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Insert then search for the key//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(850, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "Value: " << value << std::endl;
	std::cout << "//Insert then search for the key- more than 1 element//" << std::endl;
	map->insert(870, 7);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(870, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "//Search for key that doesn't exist//" << std::endl;
	std::cout << "Probe attempts: " << map->search(880, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void clear() {
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
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
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
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
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
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
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
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
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
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

void cluster_distribution() {
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
	std::cout << "/////////Testing cluster_distribution Method-ints/////////" << std::endl;
	std::cout << "//Test if cluster_distribution throws exception on empty map//" << std::endl;
	int value;
	map->insert(854, 5);
	map->remove(854, value);
	try{
		map->cluster_distribution();
	} catch(std::logic_error &le) {
		std::cout << "//Exception thrown//" << std::endl;
	}
	std::cout << "//Test if clusters show correctly with many elements//" << std::endl;
	map->insert(854, 5);
	map->insert(874, 5);
	map->insert(884, 5);
	map->insert(853, 5);
	map->insert(863, 5);
	map->insert(852, 5);
	map->insert(851, 5);
	map->insert(851, 5);
	map->print(std::cout);
	std::vector<std::pair<int, int>> vector =  map->cluster_distribution();
	for(int i = 0; i < vector.size(); i++) {
	    std:: cout << vector[i].first << ", " << vector[i].second << std::endl;
	}
}

void remove_random() {
	BucketHashMap<int, int>* map = new BucketHashMap<int, int>();
	std::cout << "/////////Testing remove_random Method-ints/////////" << std::endl;
	std::cout << "//Throws exception when removing from empty list//" << std::endl;
	map->print(std::cout);
	try {
		std::cout << map->remove_random() << std::endl;
	} catch (std::logic_error &le) {
		std::cout << "Exception caught" << std::endl;
	}
	std::cout << "//Test if remove_random works with many values//" << std::endl;
	map->insert(863, 5);
	map->insert(853, 5);
	map->insert(852, 5);
	map->insert(842, 5);
	map->insert(851, 5);
	map->insert(821, 5);
	map->insert(850, 5);
	map->insert(820, 5);
	map->insert(854, 5);
	map->insert(844, 5);
	map->print(std::cout);
	std::cout << map->remove_random() << std::endl;
	map->print(std::cout);
}

void insert_double(){
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	std::cout << "/////////Testing Insert Method-doubles/////////" << std::endl;
	std::cout << "//Inserting first element//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(854.5, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at same hash location//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(954.5, 7) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting same key overwrites the key//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(954.5, 5) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at different locations//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(852.5, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(853.5, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(850.5, 5) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(851.5, 5) << std::endl;
	map->print(std::cout);
}

void remove_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing Remove Method-doubles/////////" << std::endl;
	std::cout << "//Removing from empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(845.5, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting then removing an element//" << std::endl;
	map->insert(850, 5);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->remove(850.5, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element that doesn't exist//" << std::endl;
	value = 0;
	map->insert(850.5, 5);
	std::cout << "Probe attempts: " << map->remove(860.5, value) << std::endl;
	map->print(std::cout);
	map->insert(860.5, 7);
	std::cout << "Probe attempts: " << map->remove(870.5, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element when there is more than one in the list//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(860.5, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void search_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing Search Method-doubles/////////" << std::endl;
	std::cout << "//Search for key that doesn't exist-empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->search(880.5, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Insert then search for the key//" << std::endl;
	map->insert(850.5, 5);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(850.5, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "Value: " << value << std::endl;
	std::cout << "//Insert then search for the key- more than 1 element//" << std::endl;
	map->insert(870.5, 7);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(870.5, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = 0;
	std::cout << "//Search for key that doesn't exist//" << std::endl;
	std::cout << "Probe attempts: " << map->search(880.5, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void clear_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	std::cout << "/////////Testing Clear Method-double/////////" << std::endl;
	std::cout << "//Clear empty map//" << std::endl;
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with an element//" << std::endl;
	map->insert(850.5, 5);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with more than 1 element//" << std::endl;
	map->insert(850.5, 5);
	map->insert(860.5, 5);
	map->insert(862.5, 5);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Test if it's empty//" << std::endl;
	std::cout << "Is empty?: ";
	std::cout << map->is_empty() << std::endl;
}

void is_empty_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing is_empty Method-double/////////" << std::endl;
	std::cout << "//Test if empty on empty map//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is inserted//" << std::endl;
	map->insert(860.5, 5);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	map->insert(863.5, 5);
	map->print(std::cout);
	std::cout << "//Test if empty when another element is inserted//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is removed//" << std::endl;
	map->remove(863.5, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when a nonexistent element is removed//" << std::endl;
	map->remove(863.5, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when last element is removed//"<< std::endl;
	map->insert(833.5, 5);
	map->insert(863.5, 5);
	map->print(std::cout);
	map->remove(863.5, value);
	map->print(std::cout);
	map->remove(833.5, value);
	map->print(std::cout);
	map->remove(860.5, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
}

void capacity_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing capacity Method-double/////////" << std::endl;
	std::cout << "//Test if capacity changes with insertions and removals//"<< std::endl;
	map->insert(833.5, 5);
	map->insert(863.5, 5);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(863.5, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(863.5, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(833.5, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
}

void size_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing size Method-double/////////" << std::endl;
	std::cout << "//Test if size() is correct with insertions and removals//"<< std::endl;
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(833.5, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(862.5, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(864.5, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(874.5, 5);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(862.5, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(862.5, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(833.5, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(864.5, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(874.5, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
}

void load_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	double value = 0;
	std::cout << "/////////Testing load Method-double/////////" << std::endl;
	std::cout << "//Test if load() is correct with insertions and removals//" << std::endl;
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(833.5, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(862.5, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(864.5, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(874.5, 5);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(862.5, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(862.5, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(833.5, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(864.5, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(874.5, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
}
void cluster_distribution_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	std::cout << "/////////Testing cluster_distribution Method-double/////////" << std::endl;
	std::cout << "//Test if cluster_distribution throws exception on empty map//" << std::endl;
	double value;
	map->insert(854.0, 5);
	map->remove(854.0, value);
	try{
		map->cluster_distribution();
	} catch(std::logic_error &le) {
		std::cout << "//Exception thrown//" << std::endl;
	}
	std::cout << "//Test if clusters show correctly with many elements//" << std::endl;
	map->insert(854.0, 5);
	map->insert(874.0, 5);
	map->insert(884.0, 5);
	map->insert(853.0, 5);
	map->insert(863.0, 5);
	map->insert(852.0, 5);
	map->insert(851.0, 5);
	map->insert(851.0, 5);
	map->print(std::cout);
	std::vector<std::pair<int, int>> vector =  map->cluster_distribution();
	for(int i = 0; i < vector.size(); i++) {
	    std:: cout << vector[i].first << ", " << vector[i].second << std::endl;
	}
}

void remove_random_double() {
	BucketHashMap<double, double>* map = new BucketHashMap<double, double>();
	std::cout << "/////////Testing remove_random Method-double/////////" << std::endl;
	std::cout << "//Throws exception when removing from empty list//" << std::endl;
	map->print(std::cout);
	try {
		std::cout << map->remove_random() << std::endl;
	} catch (std::logic_error &le) {
		std::cout << "Exception caught" << std::endl;
	}
	std::cout << "//Test if remove_random works with many values//" << std::endl;
	map->insert(863.0, 5);
	map->insert(853.0, 5);
	map->insert(852.0, 5);
	map->insert(842.0, 5);
	map->insert(851.0, 5);
	map->insert(821.0, 5);
	map->insert(850.0, 5);
	map->insert(820.0, 5);
	map->insert(854.0, 5);
	map->insert(844.0, 5);
	map->print(std::cout);
	std::cout << map->remove_random() << std::endl;
	map->print(std::cout);
}

void insert_cstring(){
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char strE[] = "E";
	char strF[] = "F";
	char insert[] = "insert";
	std::cout << "/////////Testing Insert Method-cstring/////////" << std::endl;
	std::cout << "//Inserting first element//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strA, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at same hash location//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strB, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting same key overwrites the key//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strB, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at different locations//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strC, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strD, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strE, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strF, insert) << std::endl;
	map->print(std::cout);
}

void remove_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing Remove Method-cstring/////////" << std::endl;
	std::cout << "//Removing from empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(strB, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting then removing an element//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->remove(strA, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element that doesn't exist//" << std::endl;
	value = "";
	map->insert(strA, insert);
	std::cout << "Probe attempts: " << map->remove(strC, value) << std::endl;
	map->print(std::cout);
	map->insert(strC, insert);
	std::cout << "Probe attempts: " << map->remove(strD, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element when there is more than one in the list//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(strC, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void search_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing Search Method-cstring/////////" << std::endl;
	std::cout << "//Search for key that doesn't exist-empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->search(strA, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Insert then search for the key//" << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(strB, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = "";
	std::cout << "Value: " << value << std::endl;
	std::cout << "//Insert then search for the key- more than 1 element//" << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(strC, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = "";
	std::cout << "//Search for key that doesn't exist//" << std::endl;
	std::cout << "Probe attempts: " << map->search(strA, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void clear_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char insert[] = "insert";

	std::cout << "/////////Testing Clear Method-cstring/////////" << std::endl;
	std::cout << "//Clear empty map//" << std::endl;
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with an element//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with more than 1 element//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Test if it's empty//" << std::endl;
	std::cout << "Is empty?: ";
	std::cout << map->is_empty() << std::endl;
}

void is_empty_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing is_empty Method-cstring/////////" << std::endl;
	std::cout << "//Test if empty on empty map//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is inserted//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "//Test if empty when another element is inserted//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is removed//" << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when a nonexistent element is removed//" << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when last element is removed//"<< std::endl;
	map->insert(strC, insert);
	map->insert(strB, insert);
	map->print(std::cout);
	map->remove(strB, value);
	map->print(std::cout);
	map->remove(strC, value);
	map->print(std::cout);
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
}

void capacity_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing capacity Method-cstring/////////" << std::endl;
	std::cout << "//Test if capacity changes with insertions and removals//"<< std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strB, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strB, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strA, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
}

void size_cstring() {
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char* value;
	char insert[] = "insert";

	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	std::cout << "/////////Testing size Method-cstring/////////" << std::endl;
	std::cout << "//Test if size() is correct with insertions and removals//"<< std::endl;
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strD, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strC, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strD, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
}

void load_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing load Method-cstring/////////" << std::endl;
	std::cout << "//Test if load() is correct with insertions and removals//" << std::endl;
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strD, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strC, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strD, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
}

void cluster_distribution_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char strE[] = "E";
	char strF[] = "F";
	char strG[] = "G";
	char* value;
	char insert[] = "insert";

	std::cout << "/////////Testing cluster_distribution Method-cstring/////////" << std::endl;
	std::cout << "//Test if cluster_distribution throws exception on empty map//" << std::endl;

	map->insert(strA, insert);
	map->remove(strA, value);
	try{
		map->cluster_distribution();
	} catch(std::logic_error &le) {
		std::cout << "//Exception thrown//" << std::endl;
	}
	std::cout << "//Test if clusters show correctly with many elements//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->insert(strD, insert);
	map->insert(strE, insert);
	map->insert(strF, insert);
	map->insert(strG, insert);
	map->print(std::cout);
	std::vector<std::pair<int, int>> vector =  map->cluster_distribution();
	for(int i = 0; i < vector.size(); i++) {
	    std:: cout << vector[i].first << ", " << vector[i].second << std::endl;
	}
}

void remove_random_cstring() {
	BucketHashMap<char*, char*>* map = new BucketHashMap<char*, char*>();
	char strA[] = "A";
	char strB[] = "B";
	char strC[] = "C";
	char strD[] = "D";
	char strE[] = "E";
	char strF[] = "F";
	char strG[] = "G";
	char insert[] = "insert";

	std::cout << "/////////Testing remove_random Method-cstring/////////" << std::endl;
	std::cout << "//Throws exception when removing from empty list//" << std::endl;
	map->print(std::cout);
	try {
		std::cout << map->remove_random() << std::endl;
	} catch (std::logic_error &le) {
		std::cout << "Exception caught" << std::endl;
	}
	std::cout << "//Test if remove_random works with many values//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->insert(strD, insert);
	map->insert(strE, insert);
	map->insert(strF, insert);
	map->insert(strG, insert);
	map->print(std::cout);
	std::cout << map->remove_random() << std::endl;
	map->print(std::cout);
}

void insert_stdstring(){
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string insert = "insert";

	std::cout << "/////////Testing Insert Method-stdstring/////////" << std::endl;
	std::cout << "//Inserting first element//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strA, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at same hash location//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strB, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting same key overwrites the key//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strB, insert) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting at different locations//" << std::endl;
	std::cout << "Probe attempts: " << map->insert(strC, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strD, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strE, insert) << std::endl;
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->insert(strF, insert) << std::endl;
	map->print(std::cout);
}

void remove_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing Remove Method-stdstring/////////" << std::endl;
	std::cout << "//Removing from empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(strB, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Inserting then removing an element//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->remove(strA, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element that doesn't exist//" << std::endl;
	value = '\0';
	map->insert(strA, insert);
	std::cout << "Probe attempts: " << map->remove(strC, value) << std::endl;
	map->print(std::cout);
	map->insert(strC, insert);
	std::cout << "Probe attempts: " << map->remove(strD, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	map->print(std::cout);
	std::cout << "//Removing an element when there is more than one in the list//" << std::endl;
	std::cout << "Probe attempts: " << map->remove(strC, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void search_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing Search Method-stdstring/////////" << std::endl;
	std::cout << "//Search for key that doesn't exist-empty map//" << std::endl;
	std::cout << "Probe attempts: " << map->search(strA, value) << std::endl;
	map->print(std::cout);
	std::cout << "//Insert then search for the key//" << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(strB, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = '\0';
	std::cout << "Value: " << value << std::endl;
	std::cout << "//Insert then search for the key- more than 1 element//" << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Probe attempts: " << map->search(strC, value) << std::endl;
	std::cout << "Value: " << value << std::endl;
	value = '\0';
	std::cout << "//Search for key that doesn't exist//" << std::endl;
	std::cout << "Probe attempts: " << map->search(strA, value) << std::endl;
	map->print(std::cout);
	std::cout << "Value: " << value << std::endl;
}

void clear_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing Clear Method-stdstring/////////" << std::endl;
	std::cout << "//Clear empty map//" << std::endl;
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with an element//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Clear list with more than 1 element//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->print(std::cout);
	map->clear();
	map->print(std::cout);
	std::cout << "//Test if it's empty//" << std::endl;
	std::cout << "Is empty?: ";
	std::cout << map->is_empty() << std::endl;
}

void is_empty_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing is_empty Method-stdstring/////////" << std::endl;
	std::cout << "//Test if empty on empty map//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is inserted//" << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "//Test if empty when another element is inserted//" << std::endl;
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when an element is removed//" << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when a nonexistent element is removed//" << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
	std::cout << "//Test if empty when last element is removed//"<< std::endl;
	map->insert(strC, insert);
	map->insert(strB, insert);
	map->print(std::cout);
	map->remove(strB, value);
	map->print(std::cout);
	map->remove(strC, value);
	map->print(std::cout);
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Is empty?: " << map->is_empty() << std::endl;
}

void capacity_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing capacity Method-stdstring/////////" << std::endl;
	std::cout << "//Test if capacity changes with insertions and removals//"<< std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strB, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strB, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
	map->remove(strA, value);
	std::cout << "Capacity: " << map->capacity() << std::endl;
}

void size_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing size Method-stdstring/////////" << std::endl;
	std::cout << "//Test if size() is correct with insertions and removals//"<< std::endl;
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->insert(strD, insert);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strC, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
	map->remove(strD, value);
	map->print(std::cout);
	std::cout << "Size: " << map->size() << std::endl;
}

void load_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing load Method-stdstring/////////" << std::endl;
	std::cout << "//Test if load() is correct with insertions and removals//" << std::endl;
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strA, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strB, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strC, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->insert(strD, insert);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strB, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strA, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strC, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
	map->remove(strD, value);
	map->print(std::cout);
	std::cout << "Load: " << map->load() << std::endl;
}

void cluster_distribution_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing cluster_distribution Method-stdstring/////////" << std::endl;
	std::cout << "//Test if cluster_distribution throws exception on empty map//" << std::endl;
	map->insert(strA, insert);
	map->remove(strA, value);
	try{
		map->cluster_distribution();
	} catch(std::logic_error &le) {
		std::cout << "//Exception thrown//" << std::endl;
	}
	std::cout << "//Test if clusters show correctly with many elements//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->insert(strD, insert);
	map->insert(strE, insert);
	map->insert(strF, insert);
	map->print(std::cout);
	std::vector<std::pair<int, int>> vector =  map->cluster_distribution();
	for(int i = 0; i < vector.size(); i++) {
	    std:: cout << vector[i].first << ", " << vector[i].second << std::endl;
	}
}

void remove_random_stdstring() {
	BucketHashMap<std::string, std::string>* map = new BucketHashMap<std::string, std::string>();
	std::string strA = "A";
	std::string strB = "B";
	std::string strC = "C";
	std::string strD = "D";
	std::string strE = "E";
	std::string strF = "F";
	std::string value;
	std::string insert = "insert";

	std::cout << "/////////Testing remove_random Method-stdstring/////////" << std::endl;
	std::cout << "//Throws exception when removing from empty list//" << std::endl;
	map->print(std::cout);
//	try {
//		std::cout << map->remove_random() << std::endl;
//	} catch (std::logic_error &le) {
//		std::cout << "Exception caught" << std::endl;
//	}
	std::cout << "//Test if remove_random works with many values//" << std::endl;
	map->insert(strA, insert);
	map->insert(strB, insert);
	map->insert(strC, insert);
	map->insert(strD, insert);
	map->insert(strE, insert);
	map->insert(strF, insert);
	map->print(std::cout);
	std::cout << map->remove_random() << std::endl;
	map->print(std::cout);
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
	cluster_distribution();
	remove_random();

	insert_double();
	remove_double();
	search_double();
	clear_double();
	is_empty_double();
	capacity_double();
	size_double();
	load_double();
	cluster_distribution_double();
	remove_random_double();

	insert_cstring();
	remove_cstring();
	search_cstring();
	clear_cstring();
	is_empty_cstring();
	capacity_cstring();
	size_cstring();
	load_cstring();
	cluster_distribution_cstring();
	remove_random_cstring();

	insert_stdstring();
	remove_stdstring();
	search_stdstring();
	clear_stdstring();
	is_empty_stdstring();
	capacity_stdstring();
	size_stdstring();
	load_stdstring();
	cluster_distribution_stdstring();
	remove_random_stdstring();
}
