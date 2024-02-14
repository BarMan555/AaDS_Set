#pragma once

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

		void print();
		bool insert(int key);
		bool contains(int key);
		bool erase(int key);

		Set& operator=(const Set& set);
	};

}