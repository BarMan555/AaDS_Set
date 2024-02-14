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
		Node* root;
		void print_tree(const Node* root); 
		void clear(Node* root);
	public:
		Set(); 
		Set(const Set& other);
		~Set();

		void print(); 
		bool insert(int key); 
		bool contains(int key);
		bool erase(int key);

		Set& operator=(const Set& set);
	};

}