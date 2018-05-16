
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
		bool empty();
		Tree();
		Tree(std::initializer_list<int> list);
		Tree(const Tree &tree);
		bool insert(int val);
		bool exists(int val) const;
		bool remove(int val);
		bool print(traversal_order order) const;
		void print() const;
		bool save(const std::string &path);
		bool load(const std::string& path);
		//friend auto operator << (std::ostream& stream, const Tree &q)->std::ostream &;
		friend auto operator << (std::ostream& stream, const Tree &q)->std::ostream & { // Надо const Tree &q!!!
			q.save(stream, q.root);
			return stream;
		}
		auto operator=(const Tree&) ->Tree& ;
		void swap(Tree& tree);
		~Tree();
	private:
		void clean(Node * &node) const;
		void print(Node *node, int level) const;
		void direct_bypass(Node *node) const;
		void cross_bypass(Node *node) const;
		void opposite_bypass(Node *node) const;
		void save(std::ostream & stream, Node *node) const;
		void copy_insert(Node *node);
	};
}
#endif
