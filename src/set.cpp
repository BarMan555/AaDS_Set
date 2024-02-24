#include <iostream>
#include <exception>
#include <queue>
#include <vector>
#include "set.h"

using namespace SetSpace;

Node::Node() : key(0), left(nullptr), right(nullptr){}
Node::Node(int key) : Node()
{
	this->key = key;
}

Set::Set() : _root(nullptr) {}

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
}

Set& Set::operator=(const Set& other)
{
	if(this != &other)
	{
		clear(_root);
		_root = copy_tree(other.get_root());
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
}

void Set::_print(const Node* root)
{
	if (!root) return;
	_print(root->left);
	std::cout << root->key << " ";
	_print(root->right);
}

void Set::print()
{
	if (!_root) return;
	_print(_root);
}

bool Set::insert(int key)
{
	if (!_root)
	{
		_root = new Node(key);
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

	// не нашли ключ
	if (!tmp)
		return false;

	// заменяем правым
	if (tmp->left == nullptr)
	{
		if (parent && parent->left == tmp)
			parent->left = tmp->right;
		if (parent && parent->right == tmp)
			parent->right = tmp->right;
		delete tmp;
		return true;
	}
	
	// заменяем левым
	if (tmp->right == nullptr)
	{
		if (parent && parent->left == tmp)
			parent->left = tmp->left;
		if (parent && parent->right == tmp)
			parent->right = tmp->left;
		delete tmp;
		return true;
	}

	// 2 потомка
	Node* replace = tmp->right;
	while (replace->left)
		replace = replace->left;
	int replace_value = replace->key;
	erase(replace_value);
	tmp->key = replace_value;
	return true;
}

Set SetSpace::intersection(const Set& first, const Set& second)
{
	if (!first.get_root() || !second.get_root()) return Set();
	Set result;
	Set copy_first(first);

	std::queue<Node*> que; que.push(second.get_root());
	while (!que.empty())
	{
		Node* current = que.front();
		if (!copy_first.insert(current->key)) result.insert(current->key);
		if (current->left) que.push(current->left);
		if (current->right) que.push(current->right);
		que.pop();
	}

	return result;
}

Set SetSpace::difference(const Set& first, const Set& second)
{
	if (!first.get_root()) return Set();
	if (!second.get_root()) return Set(first);
	Set result;
	Set copy_second(second);

	std::queue<Node*> que; que.push(first.get_root());
	while (!que.empty())
	{
		Node* current = que.front();
		if (copy_second.insert(current->key)) result.insert(current->key);
		if (current->left) que.push(current->left);
		if (current->right) que.push(current->right);
		que.pop();
	}

	return result;
}