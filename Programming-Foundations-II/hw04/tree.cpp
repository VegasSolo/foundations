/*
 * File:	tree.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include <vector>
#include "tree.h"
#include "day.h"
using namespace std;

BinaryTree::BinaryTree(const BinaryTree &bt)
{
	copyNode(bt.root);
}

BinaryTree::~BinaryTree()
{
	deleteNode(root);
}

void BinaryTree::insert(int k, Day *v)
{
	insert(k, v, root);
}

void BinaryTree::remove(int k)
{
	remove(k, root);
}

vector<Day *> BinaryTree::searchBefore(int k)
{
	vector<Day *> out;
	searchBefore(k, root, out);
	return out;
}

vector<Day *> BinaryTree::searchAfter(int k)
{
	vector<Day *> out;
	searchAfter(k, root, out);
	return out;
}

vector<Day *> BinaryTree::searchRange(int min, int max)
{
	vector<Day *> out;
	searchRange(min, max, root, out);
	return out;
}

int BinaryTree::size() const
{
	return size(root);
}

int BinaryTree::height() const
{
	return height(root);
}

void BinaryTree::print() const
{
	print(root);
}

// MARK: Private methods

void BinaryTree::copyNode(const Node *n)
{
	if(n != NULL)
	{
		insert(n->key, n->value);
		copyNode(n->left);
		copyNode(n->right);
	}
}

void BinaryTree::deleteNode(Node *&n)
{
	if(n != NULL)
	{
		deleteNode(n->left);
		deleteNode(n->right);
		delete n;
		n = NULL;
	}
}

void BinaryTree::insert(int k, Day *v, Node *&n)
{
	if(n == NULL)
	{
		n = new Node(k, v);
	}
	else if(k <= n->key)
	{
		insert(k, v, n->left);
	}
	else
	{
		insert(k, v, n->right);
	}
}

void BinaryTree::remove(int k, Node *&n)
{
	if(n != NULL)
	{
		if(k < n->key)
		{
			remove(k, n->left);
		}
		else if(k > n->key)
		{
			remove(k, n->right);
		}
		else
		{
			remove(k, n->left);
			if (n->left != NULL && n->right != NULL)
			{
				Node *successor = n->right;
				while(successor->left != NULL)
				{
					successor = successor->left;
				}
				n->key = successor->key;
				n->value = successor->value;
				remove(successor->key, successor);
			}
			else if(n->left != NULL)
			{
				Node *left = n->left;
				delete n;
				n = left;
			}
			else if(n->right != NULL)
			{
				Node *right = n->right;
				delete n;
				n = right;
			}
			else
			{
				delete n;
				n = NULL;
			}
		}
	}
}

void BinaryTree::searchBefore(int k, Node *n, vector<Day *> &out)
{
	if(n != NULL)
    {
        if(k < n->key)
        {
            searchBefore(k, n->left, out);
        }
        else if (k >= n->key)
        {
			searchBefore(k, n->right, out);
			out.push_back(n->value);
            searchBefore(k, n->left, out);
        }
    }
}

void BinaryTree::searchAfter(int k, Node *n, vector<Day *> &out)
{
	if(n != NULL)
    {
        if(k > n->key)
        {
            searchAfter(k, n->right, out);
        }
        else if (k <= n->key)
        {
			searchAfter(k, n->left, out);
			out.push_back(n->value);
			searchAfter(k, n->right, out);
        }
    }
}


void BinaryTree::searchRange(int min, int max, Node *n, vector<Day *> &out)
{
    if(n != NULL)
    {
        if(min <= n->key && max >= n->key)
        {
            searchRange(min, max, n->left, out);
            out.push_back(n->value);
            searchRange(min, max, n->right, out);
        }
        else if(min <= n->key)
        {
            searchRange(min, max, n->left, out);
        }
        else
        {
            searchRange(min, max, n->right, out);
        }
    }
}

int BinaryTree::size(Node *n) const
{
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		return size(n->left) + size(n->right) + 1;
	}
}

int BinaryTree::height(Node *n) const
{
	if(n == NULL)
	{
		return 0;
	}
	else
	{
		return max(height(n->left), height(n->right)) + 1;
	}
}

void BinaryTree::print(Node *n) const
{
	if(n != NULL)
	{
		print(n->left);
		n->value->print();
		print(n->right);
	}
}