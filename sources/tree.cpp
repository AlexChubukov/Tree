
#include <iostream>
#include <fstream>
#include "tree.h"
using namespace std;
using namespace BSTree;

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

bool Tree::remove(int val){ 
	if (root == nullptr) {
		return false;
	}
	Node *p = root;
	Node *temp=p;
	if (p->data == val && p->right == nullptr) {
		root = p->left;
		delete p;
		return true;
	}
	if (p->data == val && p->right != nullptr) {
		p = p->right;
		if (p->left==nullptr) {
			p->left = root->left;
			delete root;
			root = p;
			return true;
		}
		while (p->left != nullptr) {
			temp = p;
			p = p->left;
		}
		temp->left = p->right; // было temp->left = nullptr;
		p->left = root->left;
		p->right = root->right;
		delete root;
		root = p;
		return true;
	}
	while (p != nullptr) {
		if (val == p->data) {
			if (p->left == p->right) {
				val > temp->data ? temp->right=nullptr : temp->left=nullptr;
				delete p;
				return true;
			}
			if (p->data == val && p->right == nullptr) {
				p->data > temp->data ? temp->right=p->left : temp->left=p->left ;
				delete p;
				return true;
			}
			if (p->data == val && p->right != nullptr) {
				Node *before_delete_node=temp;
				temp = p;
				Node *delete_node = p;
				p = p->right;
				if (p->left == nullptr) {
					temp->data > before_delete_node->data ? before_delete_node->right=temp->right : before_delete_node->left=temp->right ;
					p->left = temp->left;
					delete temp;
					return true;
				}
				while (p->left != nullptr) {
					temp = p;
					p = p->left;
				}
				temp->left = p->right; // было temp->left = nullptr;
				p->data > before_delete_node->data ? before_delete_node->right = p : before_delete_node->left = p;
				p->left = delete_node->left;
				p->right = delete_node->right;
				delete delete_node;
				return true;
			}
		}
		temp = p;
		val > p->data ? p = p->right : p = p->left;
	}
	return false;
}
bool Tree::find(int val) {
	return 0;
}

void Tree::direct_bypass(Node *node) const {
	if (node != nullptr) {
		cout << node->data << "|";
		direct_bypass(node->left);
		direct_bypass(node->right);
	}
}
void Tree::cross_bypass(Node *node) const {
	if (node != nullptr) {
		cross_bypass(node->left);
		cout << node->data << "|";
		cross_bypass(node->right);
	}
}
void Tree::opposite_bypass(Node *node) const {
	if (node != nullptr) {
		opposite_bypass(node->left);
		opposite_bypass(node->right);
		cout << node->data << "|";
	}
}

bool Tree::print(traversal_order order) const {
	switch (order)
	{
	case direct:
		direct_bypass(root);
		break;
	case cross:
		cross_bypass(root);
		break;
	case opposite:
		opposite_bypass(root);
		break;
	default:
		cout << "Неправильный ввод данных" << endl;
		return false;
		break;
	}
	return true;
}

void Tree::print() {
	print(root);
}

void Tree::print(Node *node) const {
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
		for (int i = 0; i < count_rec; i++)  cout << "   ";
		cout << "- " << node->data << endl;
		print(node->left);
		count_rec--;
		return;
	}
}

bool Tree::insert(int val) {
	Node *p = root;
	while (p != nullptr) {
		if (p->data != val) {
			if (val > p->data && p->right == nullptr) {
				p->right = new Node{ val };
				return true;
			}
			if (val < p->data && p->left == nullptr) {
				p->left = new Node{ val };
				return true;
			}
			val > p->data ? p = p->right : p = p->left;
			continue;
		}
		return false;
	}
	root = new Node{ val };
	return true;
}

void Tree::save(ofstream & stream, Node *node){
	if (node != nullptr) {
		stream << node->data << " ";
		save(stream,node->left);
		save(stream,node->right);
	}
}
