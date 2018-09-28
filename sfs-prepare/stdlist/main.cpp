#include "global.h"

/**
 * Dummy class representing some basic set/get functionality
 */
class Object {
public:
	Object(uint64_t init) {
		platformIndependentInteger = init;
	}
	uint64_t getMeTheSaus() {
		return platformIndependentInteger;
	}
	void setMeTheSaus(uint64_t pII) {
		platformIndependentInteger = pII;
	}
private:
	uint64_t platformIndependentInteger = 0;
};

int main(int argc, char *argv[]) {
	// create an instance of Object on the stack, lives as long as it does not go out of scope.
	Object h = Object(0);
	// create a pointer to the object on the stack
	Object* pH = &h;
	// display the address of the object on the stack
	std::cout << "Obj addrs:		" << &h << std::endl;
	// display the address of the object on the stack by using the pointer
	std::cout << "Obj addrs via pointer:	" << &(*pH) << std::endl;
	// display the address of the pointer itself
	std::cout << "Ptr addrs:		" << &pH << std::endl;

	// create an std::list on the stack
	std::list<Object*> objList;
	// iterate 255 times 
	for(uint16_t i  = 0; i < UINT16_MAX; i++) {
		// Create new instance of Object on the heap, initialize with current value of i
		Object* hnew = new Object(i);
		// Display the address of the object and its current value
		std::cout << "Obj addrs:		" << &(*hnew) << " - value " << hnew->getMeTheSaus() << std::endl;
		// push the object onto the list
		objList.push_front(hnew);
		//objList.pop_front();
	}

	// wait for user input before continuing
	std::cin.get();

	// iterate through the list using an iterator
	for (std::list<Object*>::iterator it=objList.begin(); it != objList.end(); ++it) {
		// display the object address and its value
		std::cout << "Obj addrs: " << &(*it) << " - value " << (*it)->getMeTheSaus() /*&it*/ << std::endl;
		// remove the object from the heap (for every new there is a delete!)
		delete *it;
	}
	// resize the list back to 0 elements as it is now empty.
	objList.resize(0);

	// wait for user input before continuing
	std::cin.get();
	std::cout << "Allocated new objects and list" << std::endl;

	// create an std::list on the heap
	std::list<Object*>* objListH = new std::list<Object*>;
	for(uint8_t i  = 0; i < UINT8_MAX; i++) {
		// add new (heap) element to the list
		objListH->push_front(new Object(i));
	}

	// wait for user input before continuing
	std::cin.get();
	std::cout << "Deallocated new objects and list" << std::endl;

	// iterate through the list
	for (std::list<Object*>::iterator it=objListH->begin(); it != objListH->end(); ++it) {
		// std::cout << "Obj addrs: " << &(*it) << " - value " << (*it)->getMeTheSaus() /*&it*/ << std::endl;
		delete *it;
	}

	// delete the list from the heap, all objects still in the list are now part of definitely lost memory (leaks)
	delete objListH;

	// wait for user input before continuing
	std::cin.get();

	exit(0);
}