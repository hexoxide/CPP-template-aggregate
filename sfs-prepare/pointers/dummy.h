#include "typedef.h"

class Dummy {
public:
	Dummy();
	void addIncrement();
	uint64_t getIncrement();
private:
	uint64_t increment;
};