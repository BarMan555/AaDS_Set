#include <iostream>
	
namespace Set {

	struct Node {
		int key;
		Node* left;
		Node* right;

	public:
		Node();
		Node(const int key);
	};

	class Set {
		Node* root;
		Node* find(const int key);

	public:
		Set() = default;
		Set(const Set& other);
		~Set();

		void print() const;
		bool insert(const int key);
		bool contains(const int key);
		bool erase(const int key);

		Set& operator+(const Set& set);
	};

	Set::Node* Set::find(const int key) {
		if (root->key == key) return root;

		return nullptr;
	}

	void Set::print() const {
		std::cout << key << " ";
		if (left) left->print();
		if (right) right->print();
	}

	bool Set::insert(const int key) {
		if (find(key)) return false;
		if (key < this->key)
			if (left)
				left->insert(key);
			else
				if (key > this->key)
					if (right)
						right->insert(key);
	}
}