
#ifndef tree_h
#define tree_h
#include "node.h"
#include "iterator.h"
#include <iostream>
#include <fstream>
#include <string>

namespace BSTree {
	enum traversal_order {
		direct = 'a',
		cross = 'b',
		opposite = 'c'
	};

	template <typename T>
	class Tree {
		Node<T> *root;
	public:
		bool empty() const;
		Tree();
		Tree(std::initializer_list<T> list);
		Tree(const Tree<T> &tree);
		bool insert(T val);
		bool exists(T val) const;
		bool remove(T val);
		bool print(traversal_order order) const;
		void print() const;
		bool save(const std::string &path, bool) const;
		bool load(const std::string& path);
		friend auto operator << (std::ostream& stream, const Tree<T> &q)->std::ostream & {
			q.save(stream, q.root);
			return stream;
		}
		auto operator=(const Tree<T>&)->Tree<T>&;
		void swap(Tree<T>& tree);
		auto begin() const ->pre_iterator<T>;
		auto end() const ->pre_iterator<T>;
		auto rbegin() const ->post_iterator<T>;
		auto rend() const ->post_iterator<T>;
		~Tree();
	private:
		void clean(Node<T> * &node) const;
		void print(Node<T> *node, int level) const;
		void direct_bypass(Node<T> *node) const;
		void cross_bypass() const;
		void opposite_bypass(Node<T> *node) const;
		void save(std::ostream & stream, Node<T> *node) const;
		void copy_insert(Node<T> *node);
	};
}
	template <typename T>
	bool BSTree::Tree<T>::empty() const {
		if (root == nullptr) {
			return true;
		}
		return false;
	}

	template <typename T>
	BSTree::Tree<T>::Tree() : root(nullptr) {}

	template <typename T>
	BSTree::Tree<T>::Tree(std::initializer_list<T> list) : Tree() {
		for (auto& item : list) {
			this->insert(item);
		}
	}

	template <typename T>
	void BSTree::Tree<T>::copy_insert(Node<T> * node) {
		if (node != nullptr) {
			this->insert(node->data);
			copy_insert(node->left);
			copy_insert(node->right);
		}
	}

	template <typename T>
	BSTree::Tree<T>::Tree(const Tree<T> &tree) {
		copy_insert(tree.root);
	}

	template <typename T>
	auto BSTree::Tree<T>::operator=(const Tree<T> &tree) -> Tree<T> & {
		Tree<T> tree_temp(tree);
		this->swap(tree_temp);
		return *this;
	}

	template <typename T>
	BSTree::Tree<T>::~Tree() { clean(root); }

	template <typename T>
	void BSTree::Tree<T>::clean(Node<T> * &node) const {
		if (node != nullptr) {
			clean(node->left);
			clean(node->right);
			delete node;
			node = nullptr;
		}
	}

	template <typename T>
	bool BSTree::Tree<T>::remove(T val) {
		if (root == nullptr) {
			return false;
		}
		Node<T> *p = root;
		if (p->data == val) {
			if (p->right == nullptr) {
				root = p->left;
				if (root != nullptr) {
				root->parent = nullptr;
			}
				delete p;
				return true;
			}
			if (p->right != nullptr) {
				p = p->right;
				while (p->left != nullptr) {
					p = p->left;
				}
				if (root->left != nullptr) {
					root->left->parent = p;
				}
				if (p->parent != root) {
					root->right->parent = p;
					p->parent->left = p->right;
				}
				if ((p->right != nullptr) && (p->parent != root)) {
					p->right->parent = p->parent;
				}
				p->left = root->left;
				if (p->parent != root) {
					p->right = root->right;
				}
				p->parent = nullptr;
				delete root;
				root = p;
				return true;
			}
		}
		while (p!=nullptr) {
			if (p->data == val) {
				if (p->right == nullptr) {
					if (p->left != nullptr) {
						p->left->parent = p->parent;
					}
					val > p->parent->data ? p->parent->right=p->left : p->parent->left = p->left;
					delete p;
					return true;
				}
				if (p->right != nullptr) {
					Node<T> *temp = p;
					p = p->right;
					while (p->left != nullptr) {
						p = p->left;
					}
					if (temp->left!=nullptr) {
						temp->left->parent = p;
					}
					if (p->parent != temp) {
						temp->right->parent = p;
						p->parent->left = p->right;
					}
					if ((p->right != nullptr) && (p->parent != temp)) {
						p->right->parent = p->parent;
					}
					p->left = temp->left;
					if (p->parent != temp) {
						p->right = temp->right;
					}
					p->parent = temp->parent;
					val > p->parent->data ? temp->parent->right = p : temp->parent->left = p;
					delete temp;
					temp = p;
					return true;
				}
			}
			val > p->data ? p = p->right : p = p->left;
		}
		return false;
	}

	template <typename T>
	void BSTree::Tree<T>::direct_bypass(Node<T> *node) const {
		if (node != nullptr) {
			std::cout << node->data << "|";
			direct_bypass(node->left);
			direct_bypass(node->right);
		}
	}

	template <typename T>
	void BSTree::Tree<T>::cross_bypass() const {
		auto it = this->begin();
		auto end = this->end();
		for (; it != end; ++it) {
			std::cout << *it << '|';
		}
		std::cout << std::endl;
	}

	template <typename T>
	void BSTree::Tree<T>::opposite_bypass(Node<T> *node) const {
		if (node != nullptr) {
			opposite_bypass(node->left);
			opposite_bypass(node->right);
			std::cout << node->data << "|";
		}
	}

	template <typename T>
	bool BSTree::Tree<T>::print(traversal_order order) const {
		switch (order)
		{
		case direct:
			direct_bypass(root);
			break;
		case cross:
			cross_bypass();
			break;
		case opposite:
			opposite_bypass(root);
			break;
		default:
			std::cout << "Неправильный ввод данных" << std::endl;
			return false;
			break;
		}
		return true;
	}

	template <typename T>
	void BSTree::Tree<T>::print() const {
		print(root, 0);
	}

	template <typename T>
	void BSTree::Tree<T>::print(Node<T> * node, int depth) const {
		if (root == nullptr) {
			std::cerr << "Дерево пусто!" << std::endl;
		}
		int temp_depth = depth;
		if (node != nullptr) {
			if (node == root) {
				print(node->right, temp_depth);
				std::cout << std::endl;
				std::cout << node->data;
				std::cout << std::endl;
				print(node->left, temp_depth);
				return;
			}
			temp_depth++;
			print(node->right, temp_depth);
			for (int i = 0; i < temp_depth; i++)  std::cout << "   ";
			std::cout << "- " << node->data << std::endl;
			print(node->left, temp_depth);
			temp_depth--;
			return;
		}
	}

	template <typename T>
	bool BSTree::Tree<T>::insert(T val) {
		Node<T> *p = root;
		while (p != nullptr) {
			if (p->data != val) {
				if (val > p->data && p->right == nullptr) {
					p->right = new Node<T>{ val , p };
					return true;
				}
				if (val < p->data && p->left == nullptr) {
					p->left = new Node<T>{ val, p };
					return true;
				}
				val > p->data ? p = p->right : p = p->left;
				continue;
			}
			return false;
		}
		root = new Node<T>{ val,p };
		return true;
	}

	template <typename T>
	bool BSTree::Tree<T>::save(const std::string & path, bool rewrite) const {
		if (rewrite) {
			std::ofstream filew(path);
			filew << *this;
			if (filew.fail()) {
				filew.close();
				return false;
			}
			filew.close();
			return true;
		}
		std::ofstream filew(path, std::ios_base::app);
		filew << *this;
		if (filew.fail()) {
			filew.close();
			return false;
		}
		filew.close();
		return true;
	}

	template <typename T>
	void BSTree::Tree<T>::save(std::ostream & stream, Node<T> *node) const {
		if (node != nullptr) {
			stream << node->data << " ";
			save(stream, node->left);
			save(stream, node->right);
		}
	}

	template <typename T>
	bool BSTree::Tree<T>::load(const std::string & path) {
		std::ifstream file(path);
		if (file.is_open() == 0) {
			return false;
		}
		int buff;
		Tree<T> temp_tree;
		while (!file.eof()) {
			file >> buff;
			temp_tree.insert(buff);
		}
		this->swap(temp_tree);
		return true;
	}

	template <typename T>
	bool BSTree::Tree<T>::exists(T val) const {
		Node<T> *p = root;
		while (p != nullptr) {
			if (p->data == val) {
				return true;
			}
			val > p->data ? p = p->right : p = p->left;
		}
		return false;
	}

	template <typename T>
	void BSTree::Tree<T>::swap(Tree<T> &tree) {
		Node<T> *temp = this->root;
		this->root = tree.root;
		tree.root = temp;
	}


	namespace BSTree {
		template<typename T>
		pre_iterator<T> Tree<T>::begin() const {
			Node<T> *p = root;
			while (p->left != nullptr) {
				p = p->left;
			}
			pre_iterator<T> temp(p);
			return temp;
		}

		template<typename T>
		pre_iterator<T> Tree<T>::end() const {
			Node<T> *p = root;
			while (p->right != nullptr) {
				p = p->right;
			}
			pre_iterator<T> temp(p->right);
			return temp;
		}

		template<typename T>
		post_iterator<T> Tree<T>::rbegin() const {
			Node<T> *p = root;
			while (p->right != nullptr) {
				p = p->right;
			}
			post_iterator<T> temp(p);
			return temp;
		}

		template<typename T>
		post_iterator<T> Tree<T>::rend()  const {
			Node<T> *p = root;
			while (p->left != nullptr) {
				p = p->left;
			}
			post_iterator<T> temp(p->left);
			return temp;
		}
	}

#endif
