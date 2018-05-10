
#ifndef tree_h
#define tree_h
#include <iostream>
#include <string>

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
		Tree(std::initializer_list<int> list);
		Tree(const Tree &tree);
		bool insert(int val);
		bool exists(int val) const;
		bool remove(int val);
		Node* get_root() const;
		void clean(Node * &node) const;
		bool print(traversal_order order)const;
		void print() const;
		bool save(const std::string &path);
		bool load(const std::string& path);
		friend auto operator << (std::ostream& stream, Tree &q)->std::ostream & { // Надо const Tree &q!!!
			q.save(stream, q.root);
			return stream;
		}
		auto operator=(const Tree&)->Tree& ;
		~Tree();
	private:
		void print(Node *node) const;
		void direct_bypass(Node *node) const;
		void cross_bypass(Node *node) const;
		void opposite_bypass(Node *node) const;
		void save(std::ostream & stream, Node *node) const;
		void copy_insert(Node *node);
	};
}
#endif
