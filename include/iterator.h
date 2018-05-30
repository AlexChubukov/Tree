#include "node.h"

namespace BSTree {

	template <typename T>
	class pre_iterator {
	public:
		pre_iterator();
		pre_iterator(Node<T>* p);
		pre_iterator(const pre_iterator<T> &);
		~pre_iterator();

		pre_iterator<T>& operator=(const pre_iterator<T> &);

		T & operator*() const;
		pre_iterator<T>& operator++();
		pre_iterator<T>& operator++(int);
		pre_iterator<T>& operator--();
		pre_iterator<T>& operator--(int);
		T* operator->() const;

		friend bool operator==(const pre_iterator<T> &iter1, const pre_iterator<T> &iter2) {
			return iter1.ptr == iter2.ptr;
		}

		friend bool operator!=(const pre_iterator<T> &iter1, const pre_iterator<T> &iter2) {
			return iter1.ptr != iter2.ptr;
		}

		friend void swap(pre_iterator<T> &lhs, pre_iterator<T> &rhs) {
			Node<T> *temp = lhs.ptr;
			lhs.ptr = rhs.ptr;
			rhs.ptr = temp;
		}

	private:
		Node<T> *ptr;
	};

	template <typename T>
	class post_iterator {
	public:
		post_iterator();
		post_iterator(Node<T>* p);
		post_iterator(const post_iterator<T> &);

		~post_iterator();

		post_iterator<T>& operator=(const post_iterator<T> &);

		T & operator*() const;
		post_iterator<T>& operator++();
		post_iterator<T>& operator++(int);
		post_iterator<T>& operator--();
		post_iterator<T>& operator--(int);
		T* operator->() const;

		friend bool operator==(const post_iterator<T> &iter1, const post_iterator<T> &iter2) {
			return iter1.ptr == iter2.ptr;
		}

		friend bool operator!=(const post_iterator<T> &iter1, const post_iterator<T> &iter2) {
			return iter1.ptr != iter2.ptr;
		}

		friend void swap(post_iterator<T> &lhs, post_iterator<T> &rhs) {
			Node<T> *temp = lhs.ptr;
			lhs.ptr = rhs.ptr;
			rhs.ptr = temp;
		}

	private:
		Node<T>* ptr;
	};

	template<typename T>
	pre_iterator<T>::pre_iterator() : ptr(nullptr) {}

	template<typename T>
	pre_iterator<T>::pre_iterator(Node<T> *ptr) {
		this->ptr = ptr;
	}

	template<typename T>
	pre_iterator<T>::pre_iterator(const pre_iterator<T> &iter) : pre_iterator() {
		this->ptr = iter.ptr;
	}

	template<typename T>
	pre_iterator<T>::~pre_iterator() {
	}

	template<typename T>
	pre_iterator<T>& pre_iterator<T>::operator=(const pre_iterator<T> & iter) {
		ptr = iter.ptr;
		return *this;
	}

	template<typename T>
	pre_iterator<T>& pre_iterator<T>::operator++() {
		if (ptr == nullptr) {
			return *this;
		}
		if ((ptr->parent == nullptr) && (ptr->right == nullptr)) {
			ptr = nullptr;
			return *this;
		}
		Node<T> *temp = ptr;
		T val = ptr->data;
		if (temp->right != nullptr) {
			temp = temp->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			ptr = temp;
			return *this;
		}
		temp = temp->parent;
		while (temp->data < ptr->data) {
			temp = temp->parent;
			if (temp == nullptr) {
				break;
			}
		}
		ptr = temp;
		return *this;
	}

	template<typename T>
	T& pre_iterator<T>::operator*() const {
		return ptr->data;
	}

	template<typename T>
	pre_iterator<T>& pre_iterator<T>::operator++(int value) {
		pre_iterator<T> temp(*this);
		if (value) {
			for (int i = value; value > 0; --value) {
				++(*this);
			}
			return temp;
		}
		++(*this);
		return temp;
	}

	template<typename T>
	pre_iterator<T>& pre_iterator<T>::operator--() {
		if (ptr == nullptr) {
			return *this;
		}
		if ((ptr->parent == nullptr) && (ptr->left == nullptr)) {
			ptr = nullptr;
			return *this;
		}
		Node<T> *temp = ptr;
		T val = ptr->data;
		if (temp->left != nullptr) {
			temp = temp->left;
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			ptr = temp;
			return *this;
		}
		temp = temp->parent;
		while (temp->data > ptr->data) {
			temp = temp->parent;
			if (temp == nullptr) {
				break;
			}
		}
		ptr = temp;
		return *this;
	}

	template<typename T>
	pre_iterator<T>& pre_iterator<T>::operator--(int value) {
		pre_iterator<T> temp(*this);
		if (value) {
			for (int i = value; value > 0; --value) {
				--(*this);
			}
			return temp;
		}
		--(*this);
		return temp;
	}

	template<typename T>
	T * pre_iterator<T>::operator->() const {
		return &(this->ptr->data);
	}

	template<typename T>
	post_iterator<T>::post_iterator() : ptr(nullptr) {}

	template<typename T>
	post_iterator<T>::post_iterator(Node<T> * p) : ptr(p) {}

	template<typename T>
	post_iterator<T>::post_iterator(const post_iterator<T> &iter) : post_iterator() {
		ptr = iter.ptr;
	}

	template<typename T>
	post_iterator<T>::~post_iterator() {
	}

	template<typename T>
	post_iterator<T>& post_iterator<T>::operator=(const post_iterator<T> & iter) {
		ptr = iter.ptr;
		return *this;
	}

	template<typename T>
	post_iterator<T>& post_iterator<T>::operator++() {
		if (ptr == nullptr) {
			return *this;
		}
		if ((ptr->parent == nullptr) && (ptr->left == nullptr)) {
			ptr = nullptr;
			return *this;
		}
		Node<T> *temp = ptr;
		T val = ptr->data;
		if (temp->left != nullptr) {
			temp = temp->left;
			while (temp->right != nullptr) {
				temp = temp->right;
			}
			ptr = temp;
			return *this;
		}
		temp = temp->parent;
		while (temp->data > ptr->data) {
			temp = temp->parent;
			if (temp == nullptr) {
				break;
			}
		}
		ptr = temp;
		return *this;
	}

	template<typename T>
	T& post_iterator<T>::operator*() const {
		return ptr->data;
	}

	template<typename T>
	post_iterator<T>& post_iterator<T>::operator++(int value) {
		post_iterator<T> temp(*this);
		if (value) {
			for (int i = value; value > 0; --value) {
				++(*this);
			}
			return temp;
		}
		++(*this);
		return temp;
	}
	template<typename T>
	post_iterator<T>& post_iterator<T>::operator--() {
		if (ptr == nullptr) {
			return *this;
		}
		if ((ptr->parent == nullptr) && (ptr->right == nullptr)) {
			ptr = nullptr;
			return *this;
		}
		Node<T> *temp = ptr;
		T val = ptr->data;
		if (temp->right != nullptr) {
			temp = temp->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			ptr = temp;
			return *this;
		}
		temp = temp->parent;
		while (temp->data < ptr->data) {
			temp = temp->parent;
			if (temp == nullptr) {
				break;
			}
		}
		ptr = temp;
		return *this;
	}
	template<typename T>
	post_iterator<T>& post_iterator<T>::operator--(int value) {
		post_iterator<T> temp(*this);
		if (value) {
			for (int i = value; value > 0; --value) {
				--(*this);
			}
			return temp;
		}
		--(*this);
		return temp;
	}

	template<typename T>
	T * post_iterator<T>::operator->() const {
		return &(this->ptr->data);
	}
}