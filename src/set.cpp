#include <iostream>
#include "set.h"

using namespace SetSpace;

Node::Node() : key(0), left(nullptr), right(nullptr){}
Node::Node(int key) : Node()
{
	this->key = key;
}

Set::Set() : _root(nullptr), _size(0) {}

Node* Set::get_root() const
{
	return this->_root;
}

Node* Set::copy_tree(Node* root) {
	insert(root->key);
	if (root->left)
		copy_tree(root->left);
	if (root->right)
		copy_tree(root->right);
	return this->_root;
}

Set::Set(const Set& other) : Set()
{
	_root = copy_tree(other.get_root());
	_size = other.get_size();
}

Set& Set::operator=(const Set& other)
{
	if(this != &other)
	{
		clear(_root);
		_root = copy_tree(other.get_root());
		_size = other.get_size();
	}
	return *this;
}

void Set::clear(Node* root)
{
	if (!root) return;
	clear(root->left);
	clear(root->right);
	delete root;
}

Set::~Set()
{
	clear(_root);
	_root = nullptr;
	_size = 0;
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
	if (!_root) return;
	print_tree(_root);
}

bool Set::insert(int key)
{
	if (!_root)
	{
		_root = new Node(key);
		++_size;
		return true;
	}

	Node* tmp = _root;
	while (tmp && tmp->key != key)
	{
		if (key < tmp->key)
		{
			if (tmp->left) tmp = tmp->left;
			else
			{
				tmp->left = new Node(key);
				++_size;
				return true;
			}
		}
		else
		{
			if (tmp->right) tmp = tmp->right;
			else
			{
				tmp->right = new Node(key);
				++_size;
				return true;
			}
		}
	}

	return false;
}

bool Set::contains(int key)
{
	if (!_root) return false;
	Node* tmp = _root;
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

bool Set::erase(int key)
{
	Node* tmp = _root;
	Node* parent = nullptr;
	while (tmp && tmp->key != key)
	{
		parent = tmp;
		if (tmp->key > key)
		{
			tmp = tmp->left;
		}
		else
		{
			tmp = tmp->right;
		}
	}

	// �� ����� ����
	if (!tmp)
		return false;

	// �������� ������
	if (tmp->left == nullptr)
	{
		if (parent && parent->left == tmp)
			parent->left = tmp->right;
		if (parent && parent->right == tmp)
			parent->right = tmp->right;
		delete tmp;
		--_size;
		return true;
	}
	
	// �������� �����
	if (tmp->right == nullptr)
	{
		if (parent && parent->left == tmp)
			parent->left = tmp->left;
		if (parent && parent->right == tmp)
			parent->right = tmp->left;
		delete tmp;
		--_size;
		return true;
	}

	// 2 �������
	Node* replace = tmp->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->key;
	erase(replace_value);
	tmp->key = replace_value;
	--_size;
	return true;
}

int Set::get_size() const
{
	return _size;
}