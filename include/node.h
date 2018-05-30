
#ifndef node_h
#define node_h

namespace BSTree {
	template <typename T>
	struct Node {
		T data;
		Node<T> *left;
		Node<T> *right;
		Node<T> *parent;
		Node();
		Node(T val, Node<T> *parent);
	};

	template <typename T>
	Node<T>::Node() :left(nullptr), right(nullptr), parent(nullptr), data(nullptr) {
	}

	template <typename T>
	Node<T>::Node(T val, Node<T> *parent) : left(nullptr), right(nullptr) {
		data = val;
		this->parent = parent;
	}
}

#endif