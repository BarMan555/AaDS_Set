#include "set.h"
#include <iostream>

using namespace SetSpace;

Node::Node() : key(0), left(nullptr), right(nullptr){}

Node::Node(int key) : Node()
{
	this->key = key;
}

Set::Set()
{
	root = nullptr;
}

//Set::Set(const Set& other)
//{
//	root = new Node(other.root->key);
//}

void Set::clear(Node* root)
{
	if (!root) return;
	clear(root->left);
	clear(root->right);
	delete root;
}

Set::~Set()
{
	clear(root);
	root = nullptr;
}

void Set::print_tree(const Node* root)
{
	if (!root) return;
	std::cout << root->key << " ";
	print_tree(root->left);
	print_tree(root->right);
}

void Set::print()
{
	if (!root) return;
	print_tree(root);
}

bool Set::insert(int key)
{
	if (!root)
	{
		root = new Node(key);
		return true;
	}

	Node* tmp = root;
	while (tmp && tmp->key != key)
	{
		if (key < tmp->key)
		{
			if (tmp->left) tmp = tmp->left;
			else
			{
				tmp->left = new Node(key);
				return true;
			}
		}
		else
		{
			if (tmp->right) tmp = tmp->right;
			else
			{
				tmp->right = new Node(key);
				return true;
			}
		}
	}

	return false;
}

bool Set::contains(int key)
{
	if (!root) return false;
	Node* tmp = root;
	while (tmp)
	{
		if (tmp->key == key) return true;
		if (key < tmp->key)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}

	return false;
}