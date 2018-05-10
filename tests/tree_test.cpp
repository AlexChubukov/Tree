#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "tree.h"
using namespace std;
using namespace BSTree;

TEST_CASE("input")
{
	Tree tree;
	REQUIRE(tree.get_root()==nullptr);
	Tree tree1{6,8,7,9,4,1};
	tree1.save("file1.txt");
	ifstream filer("file1.txt");
	string s;
	while(getline(filer, s)){	
	}
	filer.close();
	REQUIRE(s=="6 8 7 9 4 1 ");
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

