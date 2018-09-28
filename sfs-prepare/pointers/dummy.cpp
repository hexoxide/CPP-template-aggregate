#include "dummy.h"

Dummy::Dummy() {
	this->increment = 0;
};

void Dummy::addIncrement() {
	this->increment++;
}

uint64_t Dummy::getIncrement() {
	return this->increment;
}
