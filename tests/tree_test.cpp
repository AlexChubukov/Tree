#include <catch.hpp>
#include <sstream>
#include "tree.h"
using namespace BSTree;

TEST_CASE("insert")
{
	Tree tree;
	tree.insert(6);
	tree.insert(2);
	tree.insert(8);
	REQUIRE( tree.insert(3)==1);
	REQUIRE( tree.insert(3)==0);
}

