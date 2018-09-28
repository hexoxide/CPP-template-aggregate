#include "typedef.h"
#include "dummy.h"

void dummyPointer(Dummy *pDum);
void dummyReference(Dummy &rDum);
void dummyValue(Dummy dum);

int main(int argc, char *argv[]) {
	Dummy dum = Dummy();

	std::cout << "dummy regular: " << dum.getIncrement() << " - " << &dum << std::endl;
	dummyPointer(&dum);
	dummyReference(dum);
	dummyValue(dum);
	std::cout << "dummy regular: " << dum.getIncrement() << " - " << &dum << std::endl;

	Dummy *dumArray = new Dummy[UINT16_MAX];
	for(uint32_t i = 0; i < UINT16_MAX; i++) {
		std::cout << "dummy array: " << &dumArray[i] << std::endl;
	}

	std::cout << "size of pointer: " << sizeof(Dummy) << std::endl; 
}

void dummyPointer(Dummy *pDum) {
	if(!pDum) return; // short guard against nullptr
	pDum->addIncrement();
	std::cout << "dummy pointer: " << pDum->getIncrement() << " - " << &pDum << std::endl;
}

void dummyReference(Dummy &rDum) {
	rDum.addIncrement();
	std::cout << "dummy reference: " << rDum.getIncrement() << " - " << &rDum << std::endl;
}

void dummyValue(Dummy dumdum) {
	dumdum.addIncrement();
	std::cout << "dummy value: " << dumdum.getIncrement() << " - " << &dumdum << std::endl;
}