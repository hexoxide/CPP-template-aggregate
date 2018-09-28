#include <boost/timer/timer.hpp>
#include <iostream>
#include <string>

#if _WIN32_
	#include "windowsstuff.hpp"
#else
	#include "linuxstuff.hpp"
#endif

#include "main.hpp"

using namespace boost::timer;

int main(int argc, char* argv[]) {
	cpu_timer timer;
	std::cout << helloWorldFunction() << std::endl;
	doPlatformStuff();
	std::cout << timer.format() << std::endl;
	return 0;
}

std::string helloWorldFunction() {
	return std::string("Hello world");
}