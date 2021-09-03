#include "HelloWorld.h"
#include <iostream>
#include "unistd.h"
#include <sys/types.h>

//entry
int main(int argc,char argv[]) {
	if (argc < 2) {            //参数太少了
		std::cerr << "Program name not specified";
		return -1;
	}

	auto prog = argv[1];

	auto pid = 0;
	HelloWorld test;
	std::cout << test.test();
	return 0;
}