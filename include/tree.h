#include "stdafx.h"
#ifndef tree_h
#define tree_h

namespace BSTree
{
	enum traversal_order {
		direct = 'a',
		cross = 'b',
		opposite = 'c'
	};
	struct Node {
		Node *left;
		Node *right;
		int data;
		Node(int val);
	};

	class Tree {
		Node *root;
	public:
		Tree();
		Tree(const Tree &tree);
		Node* get_root();
		void clean(Node * &node);
		bool remove(int val);
		bool find(int val);
		bool insert(int val);
		bool print(traversal_order order) const;
		void print();
		~Tree();
	private:
		void print(Node *node) const;
		void direct_bypass(Node *node) const;
		void cross_bypass(Node *node) const;
		void opposite_bypass(Node *node) const;
	};
}
#endif
