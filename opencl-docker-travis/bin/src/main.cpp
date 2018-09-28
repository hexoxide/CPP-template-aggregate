#include <iostream>

#include "bar.h"

int main(int argc, const char* argv[]) {
	std::cout << std::hex << Bar::base() << std::endl;
	std::cout << std::hex << Bar::stack() << std::endl;
	std::cout << std::hex << Bar::rsi() << std::endl;
	std::cout << std::hex << Bar::rdi() << std::endl;
}
