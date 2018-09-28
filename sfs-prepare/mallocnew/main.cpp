#include "global.h"

/**
 * Dummy class representing some basic set/get functionality
 */
class Object {
public:
	Object(uint64_t init) {
		platformIndependentInteger = init;
	}
	Object() {
		platformIndependentInteger = 0;
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
uint64_t NUM_OBJECTS = UINT16_MAX*UINT8_MAX*8;

// Change this mode to see the performance difference between malloc and new
bool modeMalloc = true;


/**
 * Malloc will be slower then new this is due to having to loop through the array to call each destructor.
 * This behavior can be optimized when calling delete[].Removing the iteration through deconstruct each Object will make malloc faster.
 * Normally this would create undefined behavior as the contents of Object aren't cleaned up but since Object does not contain
 * dynamic memory this will not cause an issue.
 * Another import note is that using new requires the class to have a default constructor and be initialized by iterating through it.
 */
int main(int argc, char *argv[]) {

	if(modeMalloc) {
		Object* objArray = (Object*)malloc(NUM_OBJECTS * sizeof(Object));
		for(uint32_t i = 0; i < NUM_OBJECTS; i++) {
			objArray[i] = Object(i);
		}
		for(uint32_t i = 0; i < NUM_OBJECTS; i++) {
			objArray[i].~Object();
		}
		free(objArray);
	}
	else {
		Object* heapArray = new Object[NUM_OBJECTS];
		for(uint32_t i = 0; i < NUM_OBJECTS; i++) {
			heapArray[i].setMeTheSaus(i);
		}
		delete[] heapArray;
	}
}