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
		bool _erase(Node*& node, int key);
		void clear(Node* root);

	public:
		Set();
		Set(std::initializer_list<int> list);
		Set(const Set& other);
		~Set();

		void print();
		bool insert(int key);
		bool contains(int key) const;
		bool erase(int key);
		Node* get_root() const;

		Set& operator=(const Set& set);
	};

	bool operator==(const Set& first, const Set& second);

	Set intersection(const Set& first, const Set& second);
	Set difference(const Set& first, const Set& second);
}