#include "../catch.hpp"
#include "HelloWorld.h"

TEST_CASE("HelloWorld.h") {
	SECTION("HelloTest") {
		HelloWorld Test;
		REQUIRE(Test.test() == MAGIC_NUM);
		//REQUIRE(Test.test() == MAGIC_NUM);
	}
}