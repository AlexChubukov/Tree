#include <catch.hpp>
#include <sstream>
#include <fstream>
#include "tree.h"
using namespace std;
using namespace BSTree;

TEST_CASE("Empty tree") {
	Tree<int> tree;
	REQUIRE(tree.empty() == true);
}

TEST_CASE("Not empty tree") {
	  Tree<int> tree{ 1 };
	  REQUIRE(tree.empty() == false);
}

TEST_CASE("input and input in file")
{
	Tree<int> tree;
	Tree<int> tree1{6,8,7,9,4,1};
	Tree<double> tree2{5.5,2.1,9.9,8.87,1.2};
	Tree<char> tree3{'l','d','v','g','p'};
	tree1.save("file1.txt",false);
	tree2.save("file2.txt",false);
	tree3.save("file3.txt",false);
	ifstream filer1("file1.txt");
	ifstream filer2("file2.txt");
	ifstream filer3("file3.txt");
	string s1,s2,s3;
	getline(filer1, s1);
	getline(filer2, s2);
	getline(filer3, s3);
	filer1.close();
	filer2.close();
	filer3.close();
	REQUIRE(s1=="6 4 1 8 7 9 ");
	REQUIRE(s2=="5.5 2.1 1.2 9.9 8.87 ");
	REQUIRE(s3=="l d g v p ");
}

TEST_CASE("insert")
{
	Tree<int> tree;
	tree.insert(6);
	tree.insert(2);
	tree.insert(8);
	tree.save("file4.txt",false);
	ifstream filer4("file4.txt");
	string s4;
	getline(filer4, s4);
	filer4.close();
	REQUIRE(s4=="6 2 8 ");
	REQUIRE( tree.insert(3)==1);
	REQUIRE( tree.insert(3)==0);
}

TEST_CASE("Existence of node") {
    BSTree::Tree<int> tree = { 8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15 };
    REQUIRE(tree.exists(8) == true);
    REQUIRE(tree.exists(100) == false);
}

