
#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"

using namespace std;
using namespace BSTree;

Node::Node(int val) : left(nullptr), right(nullptr) {
	data = val;
}

bool Tree::empty() {
	if (root == nullptr) {
		return true;
	}
	return false;
}

Tree::Tree() : root(nullptr) {}

Tree::Tree(std::initializer_list<int> list) : Tree() {
	for (auto& item : list) {
		this->insert(item);
	}
}

void Tree::copy_insert(Node * node){
	if (node != nullptr) {
	this->insert(node->data);
	copy_insert(node->left);
	copy_insert(node->right);
	}
}

Tree::Tree(const Tree &tree) {
	copy_insert(tree.root);
}

auto Tree::operator=(const Tree &tree) -> Tree &  {
	Tree tree_temp(tree);
	this->swap(tree_temp);
	return *this;
}

Tree::~Tree() { clean(root); }

void Tree::clean(Node * &node) const {
	if (node != nullptr) {
		clean(node->left);
		clean(node->right);
		delete node;
		node = nullptr;
	}
}

bool Tree::remove(int val) {
	if (root == nullptr) {
		return false;
	}
	Node *p = root;
	Node *temp = p;
	if (p->data == val && p->right == nullptr) {
		root = p->left;
		delete p;
		return true;
	}
	if (p->data == val && p->right != nullptr) {
		p = p->right;
		if (p->left == nullptr) {
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
				val > temp->data ? temp->right = nullptr : temp->left = nullptr;
				delete p;
				return true;
			}
			if (p->data == val && p->right == nullptr) {
				p->data > temp->data ? temp->right = p->left : temp->left = p->left;
				delete p;
				return true;
			}
			if (p->data == val && p->right != nullptr) {
				Node *before_delete_node = temp;
				temp = p;
				Node *delete_node = p;
				p = p->right;
				if (p->left == nullptr) {
					temp->data > before_delete_node->data ? before_delete_node->right = temp->right : before_delete_node->left = temp->right;
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

void Tree::print() const {
	print(root,0);
}

void Tree::print(Node * node, int depth) const {
	if (root == nullptr) {
		cout << "Дерево пусто!" << endl;
	}
	int temp_depth = depth;
	if (node != nullptr) {
		if (node == root) {
			print(node->right, temp_depth);
			cout << endl;
			cout << node->data;
			cout << endl;
			print(node->left, temp_depth);
			return;
		}
		temp_depth++;
		print(node->right, temp_depth);
		for (int i = 0; i < temp_depth; i++)  cout << "   ";
		cout << "- " << node->data << endl;
		print(node->left,temp_depth);
		temp_depth--;
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

bool Tree::save(const string & path) {
	ifstream temp(path);
	bool exist = temp.is_open();
	temp.close();
	if (exist) {
		cout << "Файл уже существует, перезаписать ? (Yes|No): ";
		string answer;
		cin >> answer;
		if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES") {
			ofstream filew(path);
			filew << *this;
			filew.close();
			return true;
		}
		ofstream filew(path, ios_base::app);
		filew << endl;
		filew << *this;
		filew.close();
		return true;
	}
	ofstream filew(path);
	filew << *this;
	filew.close();
	return true;
}
void Tree::save(ostream & stream, Node *node) const {
	if (node != nullptr) {
		stream << node->data << " ";
		save(stream, node->left);
		save(stream, node->right);
	}
}

bool Tree::load(const string & path) {
	ifstream file(path);
	if (file.is_open() == 0) {
		return false;
	}
	int buff;
	Tree temp_tree;
	while (!file.eof()) {
		file >> buff;
		temp_tree.insert(buff);
	}
	this->swap(temp_tree);
	return true;
}

bool Tree::exists(int val) const {
	Node *p = root;
	while (p != nullptr) {
		if (p->data == val) {
			return true;
		}
		val > p->data ? p=p->right : p=p->left;
	}
	return false;
}

void Tree::swap(Tree &tree) {
	Node *temp = this->root;
	this->root = tree.root;
	tree.root = temp;
}