
#include "tree.h"
#include <iostream>
#include <ctime>


using namespace BSTree;
using namespace std;

int main()
{
	Tree<long long> tree;
	srand(time(0));
	float arr1[9]{}, arr2[9]{}, arr3[9]{}, arr4[9]{}, arr5[9]{}, arr6[9]{}, arr7[9]{}, arr8[9]{}, arr9[9]{};
	// Бенчмарк для 10 элементов
	cout << 1 << endl;
	float start_time = clock();
	for (int i = 0; i < 10; i++) {
		tree.insert(1+rand()%100);
	}
	float end_time = clock();
	arr1[4] = end_time - start_time;
	start_time = clock();
	tree.print();
	end_time = clock();
	arr1[0] = end_time- start_time;

	start_time = clock();
	tree.print(traversal_order('a'));
	end_time = clock();
	arr1[1] = end_time - start_time;

	start_time = clock();
	tree.print(traversal_order('b'));
	end_time = clock();
	arr1[2] = end_time - start_time;
	
	start_time = clock();
	tree.print(traversal_order('c'));
	end_time = clock();
	arr1[3] = end_time - start_time;

	start_time = clock();
	tree.exists(0);
	end_time = clock();
	arr1[6] = end_time - start_time;

	start_time = clock();
	tree.save("text1.txt");
	end_time = clock();
	arr1[7] = end_time - start_time;

	start_time = clock();
	tree.~Tree();
	end_time = clock();
	arr1[5] = end_time - start_time;

	Tree<long long> tree1;
	start_time = clock();
	tree1.load("text1.txt");
	end_time = clock();
	arr1[8] = end_time - start_time;

	// Бенчмарк для 10^2 элементов
	cout << 2 << endl;
	Tree<long long> tree22;
	start_time = clock();
	for (int i = 0; i < 100; i++) {
		tree22.insert(1 + rand() % 10000);
	}
	end_time = clock();
	arr2[4] = end_time - start_time;
	start_time = clock();
	tree22.print();
	end_time = clock();
	arr2[0] = end_time - start_time;

	start_time = clock();
	tree22.print(traversal_order('a'));
	end_time = clock();
	arr2[1] = end_time - start_time;

	start_time = clock();
	tree22.print(traversal_order('b'));
	end_time = clock();
	arr2[2] = end_time - start_time;

	start_time = clock();
	tree22.print(traversal_order('c'));
	end_time = clock();
	arr2[3] = end_time - start_time;

	start_time = clock();
	tree22.exists(0);
	end_time = clock();
	arr2[6] = end_time - start_time;

	start_time = clock();
	tree22.save("text2.txt");
	end_time = clock();
	arr2[7] = end_time - start_time;

	start_time = clock();
	tree22.~Tree();
	end_time = clock();
	arr2[5] = end_time - start_time;

	Tree<long long> tree2;
	start_time = clock();
	tree2.load("text2.txt");
	end_time = clock();
	arr2[8] = end_time - start_time;

	// Бенчмарк для 10^3 элементов
	cout << 3 << endl;
	Tree<long long> tree33;
	start_time = clock();
	for (int i = 0; i < 1000; i++) {
		tree33.insert(1 + rand() % 10000);
	}
	end_time = clock();
	arr3[4] = end_time - start_time;
	start_time = clock();
	tree33.print();
	end_time = clock();
	arr3[0] = end_time - start_time;

	start_time = clock();
	tree33.print(traversal_order('a'));
	end_time = clock();
	arr3[1] = end_time - start_time;

	start_time = clock();
	tree33.print(traversal_order('b'));
	end_time = clock();
	arr3[2] = end_time - start_time;

	start_time = clock();
	tree33.print(traversal_order('c'));
	end_time = clock();
	arr3[3] = end_time - start_time;

	start_time = clock();
	tree33.exists(0);
	end_time = clock();
	arr3[6] = end_time - start_time;

	start_time = clock();
	tree33.save("text3.txt");
	end_time = clock();
	arr3[7] = end_time - start_time;

	start_time = clock();
	tree33.~Tree();
	end_time = clock();
	arr3[5] = end_time - start_time;

	Tree<long long> tree3;
	start_time = clock();
	tree3.load("text3.txt");
	end_time = clock();
	arr3[8] = end_time - start_time;

	// Бенчмарк для 10^4 элементов
	cout << 4 << endl;
	Tree<long long> tree44;
	start_time = clock();
	for (int i = 0; i < 10000; i++) {
		tree44.insert(1 + rand());
	}
	end_time = clock();
	arr4[4] = end_time - start_time;
	start_time = clock();
	tree44.print();
	end_time = clock();
	arr4[0] = end_time - start_time;

	start_time = clock();
	tree44.print(traversal_order('a'));
	end_time = clock();
	arr4[1] = end_time - start_time;

	start_time = clock();
	tree44.print(traversal_order('b'));
	end_time = clock();
	arr4[2] = end_time - start_time;

	start_time = clock();
	tree44.print(traversal_order('c'));
	end_time = clock();
	arr4[3] = end_time - start_time;

	start_time = clock();
	tree44.exists(0);
	end_time = clock();
	arr4[6] = end_time - start_time;

	start_time = clock();
	tree44.save("text4.txt");
	end_time = clock();
	arr4[7] = end_time - start_time;

	start_time = clock();
	tree44.~Tree();
	end_time = clock();
	arr4[5] = end_time - start_time;

	Tree<double> tree4;
	start_time = clock();
	tree4.load("text4.txt");
	end_time = clock();
	arr3[8] = end_time - start_time;

	// Бенчмарк для 10^5 элементов
	cout << 5 << endl;
	Tree<long long> tree55;
	start_time = clock();
	for (int i = 0; i < 100000; i++) {
		tree55.insert(1 + rand()*(rand()%100));
	}
	end_time = clock();
	arr5[4] = end_time - start_time;
	start_time = clock();
	tree55.print();
	end_time = clock();
	arr5[0] = end_time - start_time;

	start_time = clock();
	tree55.print(traversal_order('a'));
	end_time = clock();
	arr5[1] = end_time - start_time;

	start_time = clock();
	tree55.print(traversal_order('b'));
	end_time = clock();
	arr5[2] = end_time - start_time;

	start_time = clock();
	tree55.print(traversal_order('c'));
	end_time = clock();
	arr5[3] = end_time - start_time;

	start_time = clock();
	tree55.exists(0);
	end_time = clock();
	arr5[6] = end_time - start_time;

	start_time = clock();
	tree55.save("text5.txt");
	end_time = clock();
	arr5[7] = end_time - start_time;

	start_time = clock();
	tree55.~Tree();
	end_time = clock();
	arr5[5] = end_time - start_time;

	Tree<double> tree5;
	start_time = clock();
	tree5.load("text5.txt");
	end_time = clock();
	arr5[8] = end_time - start_time;

	// Бенчмарк для 10^6 элементов
	cout << 6 << endl;
	Tree<long long> tree66;
	start_time = clock();
	for (int i = 0; i < 1000000; i++) {
		tree66.insert(1 + rand()*(rand() % 1000));
	}
	end_time = clock();
	arr6[4] = end_time - start_time;
	start_time = clock();
	tree66.print();
	end_time = clock();
	arr6[0] = end_time - start_time;

	start_time = clock();
	tree66.print(traversal_order('a'));
	end_time = clock();
	arr6[1] = end_time - start_time;

	start_time = clock();
	tree66.print(traversal_order('b'));
	end_time = clock();
	arr6[2] = end_time - start_time;

	start_time = clock();
	tree66.print(traversal_order('c'));
	end_time = clock();
	arr6[3] = end_time - start_time;

	start_time = clock();
	tree66.exists(0);
	end_time = clock();
	arr6[6] = end_time - start_time;

	start_time = clock();
	tree66.save("text6.txt");
	end_time = clock();
	arr6[7] = end_time - start_time;

	start_time = clock();
	tree66.~Tree();
	end_time = clock();
	arr6[5] = end_time - start_time;

	Tree<double> tree6;
	start_time = clock();
	tree6.load("text6.txt");
	end_time = clock();
	arr6[8] = end_time - start_time;

	// Бенчмарк для 10^7 элементов
	cout << 7 << endl;
	Tree<long long> tree77;
	start_time = clock();
	for (int i = 0; i < 10000000; i++) {
		tree77.insert(1 + rand()*(rand() % 10000));
	}
	end_time = clock();
	arr7[4] = end_time - start_time;
	start_time = clock();
	tree77.print();
	end_time = clock();
	arr7[0] = end_time - start_time;

	start_time = clock();
	tree77.print(traversal_order('a'));
	end_time = clock();
	arr7[1] = end_time - start_time;

	start_time = clock();
	tree77.print(traversal_order('b'));
	end_time = clock();
	arr7[2] = end_time - start_time;

	start_time = clock();
	tree77.print(traversal_order('c'));
	end_time = clock();
	arr7[3] = end_time - start_time;

	start_time = clock();
	tree77.exists(0);
	end_time = clock();
	arr7[6] = end_time - start_time;

	start_time = clock();
	tree77.save("text7.txt");
	end_time = clock();
	arr7[7] = end_time - start_time;

	start_time = clock();
	tree77.~Tree();
	end_time = clock();
	arr7[5] = end_time - start_time;

	Tree<double> tree7;
	start_time = clock();
	tree7.load("text7.txt");
	end_time = clock();
	arr7[8] = end_time - start_time;

	// Бенчмарк для 10^8 элементов
	cout << 8 << endl;
	Tree<long long> tree88;
	start_time = clock();
	for (int i = 0; i < 100000000; i++) {
		tree88.insert(1 + rand()*(rand()%10000));
	}
	end_time = clock();
	arr8[4] = end_time - start_time;
	start_time = clock();
	tree88.print();
	end_time = clock();
	arr8[0] = end_time - start_time;

	start_time = clock();
	tree88.print(traversal_order('a'));
	end_time = clock();
	arr8[1] = end_time - start_time;

	start_time = clock();
	tree88.print(traversal_order('b'));
	end_time = clock();
	arr8[2] = end_time - start_time;

	start_time = clock();
	tree88.print(traversal_order('c'));
	end_time = clock();
	arr8[3] = end_time - start_time;

	start_time = clock();
	tree88.exists(0);
	end_time = clock();
	arr8[6] = end_time - start_time;

	start_time = clock();
	tree88.save("text8.txt");
	end_time = clock();
	arr8[7] = end_time - start_time;

	start_time = clock();
	tree88.~Tree();
	end_time = clock();
	arr8[5] = end_time - start_time;

	Tree<double> tree8;
	start_time = clock();
	tree8.load("text8.txt");
	end_time = clock();
	arr8[8] = end_time - start_time;

	// Бенчмарк для 10^9 элементов
	cout << 9 << endl;
	Tree<long long> tree99;
	start_time = clock();
	for (int i = 0; i < 1000000000; i++) {
		tree99.insert(1 + rand()*(rand()));
	}
	end_time = clock();
	arr9[4] = end_time - start_time;
	start_time = clock();
	tree99.print();
	end_time = clock();
	arr9[0] = end_time - start_time;

	start_time = clock();
	tree99.print(traversal_order('a'));
	end_time = clock();
	arr9[1] = end_time - start_time;

	start_time = clock();
	tree99.print(traversal_order('b'));
	end_time = clock();
	arr9[2] = end_time - start_time;

	start_time = clock();
	tree99.print(traversal_order('c'));
	end_time = clock();
	arr9[3] = end_time - start_time;

	start_time = clock();
	tree99.exists(0);
	end_time = clock();
	arr9[6] = end_time - start_time;

	start_time = clock();
	tree99.save("text9.txt");
	end_time = clock();
	arr9[7] = end_time - start_time;

	start_time = clock();
	tree99.~Tree();
	end_time = clock();
	arr9[5] = end_time - start_time;

	Tree<double> tree9;
	start_time = clock();
	tree9.load("text9.txt");
	end_time = clock();
	arr9[8] = end_time - start_time;

	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr1[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr2[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr3[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr4[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr5[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr6[i] << "|";
	}
	cout << endl;

	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr7[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr8[i] << "|";
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < 9; i++) {
		cout << arr9[i] << "|";
	}
	cout << endl;



    return 0;
}

