#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "tree.h"
using namespace BSTree;

TEST_CASE("input")
{
	Tree tree;
	REQUIRE(tree.get_root()==nullptr);
	Tree tree1{6,8,7,9,4,1};
	ofstream filew(file1);
	tree1.save(file1);
	tree.load(file1);
	REQUIRE(tree==tree1);
	filew.close();
}

TEST_CASE("insert")
{
	Tree tree;
	tree.insert(6);
	tree.insert(2);
	tree.insert(8);
	REQUIRE( tree.insert(3)==1);
	REQUIRE( tree.insert(3)==0);
}

