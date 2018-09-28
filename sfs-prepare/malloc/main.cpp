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

// Try this with large amount of objects, be careful of memory consumption
uint64_t NUM_OBJECTS = UINT16_MAX*UINT8_MAX*4;

int main(int argc, char *argv[]) {
	// Allocate large amount of memory to create a large amount of objects using malloc
	std::cout << "create " << NUM_OBJECTS << " objects of size " << sizeof(Object) << " for a total size of " << (NUM_OBJECTS * sizeof(Object)) << std::endl;
	Object* objArray = (Object*)malloc(NUM_OBJECTS * sizeof(Object));
	for(uint32_t i = 0; i < NUM_OBJECTS; i++) {
		objArray[i] = Object(i);
	}

	// Wait for user input and deconstruct all the objects and free the memory allocation
	std::cin.get();
	std::cout << "free all objects" << std::endl;
	for(uint32_t i = 0; i < NUM_OBJECTS; i++) {
		objArray[i].~Object();
	}
	free(objArray);

	// The example demonstrates using malloc an free with c++ classes which because of the large size
	// will be much faster than using c++ new
	std::cin.get();
}