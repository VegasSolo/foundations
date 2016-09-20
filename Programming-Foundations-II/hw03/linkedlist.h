#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "list.h"

struct Node
{
	Node(int val, Node *nxt = NULL);
	int value;
	Node *next;
};

class LinkedList: public List
{
	public:
		LinkedList();
		LinkedList(const LinkedList &other);
		virtual ~LinkedList();

		virtual int get(int i) const;
		virtual void set(int i, int x);

		virtual void insert(int i, int x);
		virtual void append(int x);
		virtual void remove(int i);
		virtual void clear();

		virtual int length() const;
		virtual void print() const;
	private:
		Node *head, *tail;
		int size;
};

#endif

