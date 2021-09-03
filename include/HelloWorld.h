#ifndef HELLO_WORLD
#define HELLO_WORLD

#define MAGIC_NUM 100

#include <stdio.h>

class HelloWorld {
public:
	HelloWorld() {
		test_num = MAGIC_NUM;
	};
	~HelloWorld() = default;
	int test();
private:
	int test_num;
};

#endif