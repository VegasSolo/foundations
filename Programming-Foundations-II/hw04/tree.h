/*
 * File:	tree.h
 * Author:	Luke Godfrey
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include "day.h"
using namespace std;

struct Node
{
	Node(int key, Day *value, Node *left = NULL, Node *right = NULL)
	: key(key), value(value), left(left), right(right) {}

	int key;
	Day *value;
	Node *left, *right;
};

class BinaryTree
{
	public:
		BinaryTree() : root(NULL) {}
		BinaryTree(const BinaryTree &bt);
		~BinaryTree();

		void insert(int k, Day *v);
		void remove(int k);
		vector<Day *> searchBefore(int k);
		vector<Day *> searchAfter(int k);
		vector<Day *> searchRange(int min, int max);
		int size() const;
		int height() const;
		void print() const;

	private:
		void copyNode(const Node *n);
		void deleteNode(Node *&n);
		void insert(int k, Day *v, Node *&n);
		void remove(int k, Node *&n);
		void searchBefore(int k, Node *n, vector<Day *> &out);
		void searchAfter(int k, Node *n, vector<Day *> &out);
		void searchRange(int min, int max, Node *n, vector<Day *> &out);
		int size(Node *n) const;
		int height(Node *n) const;
		void print(Node *n) const;

		Node *root;
};

#endif
