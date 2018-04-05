#include <iostream>
#include "tree.h"
using namespace std;

Node::Node(int val) : left(nullptr), right(nullptr) {
	data = val;
}

Node* Tree::get_root() {
	return root;
}

Tree::Tree() : root(nullptr) {};
Tree::Tree(const Tree &tree)
{
}
Tree::~Tree() { clean(root); }

void Tree::clean(Node * &node) {
	if (node != nullptr) {
		clean(node->left);
		clean(node->right);
		delete node;
		node = nullptr;
	}
}
bool Tree::remove(int val) {
	return 0;
}
bool Tree::find(int val) {
	return 0;
}
bool Tree::insert(int val) {
	Node *p = root;
	if (p == nullptr) {
		root = new Node{ val };
		return true;
	}
	else {
		while (p != nullptr) {
			if (val == p->data) {
				return false;
			}
			if (val < p->data && p->left != nullptr) {
				p = p->left;
			}
			if (val < p->data && p->left == nullptr) {
				p->left = new Node{ val };
				return true;
			}
			if (val > p->data && p->right != nullptr) {
				p = p->right;
			}
			if (val > p->data && p->right == nullptr) {
				p->right = new Node{ val };
				return true;
			}
		}
	}
}

void Tree::print(Node *node) {
if (root == nullptr) {
		cout << "Дерево пусто!" << endl;
	}
	if (node != nullptr) {
		static int count_rec = 0;
		if (node == root) {
			print(node->right);
			cout << endl;
			std::cout << node->data;
			cout << endl << endl;
			print(node->left);
			return;
		}
		count_rec++;
		print(node->right);
		for (int i = 0; i < count_rec; i++)  cout << "  ";
		cout << "-- "<<node->data<<endl;
		print(node->left);
		count_rec--;
		return;
	}
}

