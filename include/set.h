#pragma once
	
namespace SetSpace
{

	struct Node
	{
		int key;
		Node* left;
		Node* right;

		Node();
		Node(int key);
	};

	class Set
	{
		Node* _root;
		Node* copy_tree(Node* root);
		void _print(const Node* root);
		void clear(Node* root);

	public:
		Set();
		Set(const Set& other);
		~Set();

		void print();
		bool insert(int key);
		bool contains(int key);
		bool erase(int key);
		Node* get_root() const;

		Set& operator=(const Set& set);
	};

	Set intersection(const Set& first, const Set& second);
	Set difference(const Set& first, const Set& second);
}