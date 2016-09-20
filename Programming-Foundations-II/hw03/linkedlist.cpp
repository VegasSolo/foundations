#include "linkedlist.h"
#include "timer.h"
#include <iostream>
using namespace std;

Node::Node(int val, Node *nxt)
{
	value = val;
	next = nxt;
}

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	size = 0;
}

LinkedList::LinkedList(const LinkedList &other)
{
	head = NULL;
	tail = NULL;
	size = other.size;
	if(other.head != NULL)
	{
		head = new Node(other.head->value);
		tail = head;
		
		Node *n = other.head->next;
		Node *m = head;
		
		while(n != NULL)
		{
			tail = m;
			m->next = new Node(n->value);
			m = m->next;
			n = n->next;
		}
	}
}

LinkedList::~LinkedList()
{
	Node *n = head;
	while(n != NULL)
	{
		Node *m = n->next;
		delete n;
		n = m;
	}
}

const int &LinkedList::get(int i) const
{
	Node *n = head;
	for(int j = 0; j < i; j++)
	{
		n = n->next;
	}
	return n->value;
}

int &LinkedList::get(int i)
{
	Node *n = head;
	for(int j = 0; j < i; j++)
	{
		n = n->next;
	}
	return n->value;
}

void LinkedList::set(int i, int x)
{
	Node *n = head;
	for(int j = 0; j < i; j++)
	{
		n = n->next;
	}
	n->value = x;
}

void LinkedList::insert(int i, int x)
{
	size++;

	if(head == NULL)
	{
		head = new Node(x);
		tail = head;
	}
	else if(i == 0)
	{
		head = new Node(x, head);
	}
	else if(i == size - 1)
	{
		tail->next = new Node(x);
		tail = tail->next;
	}
	else
	{
		Node *n = head;
		for(int j = 0; j < i - 1; j++)
		{
			n = n->next;
		}
		n->next = new Node(x, n->next);
	}
}

void LinkedList::append(int x)
{
	insert(length(), x);
}

void LinkedList::remove(int i)
{
	size--;

	if(i == 0)
	{
		Node *n = head->next;
		delete head;
		head = n;
	}
	else
	{
		Node *n = head;
		for(int j = 0; j < i - 1; j++)
		{
			n = n->next;
		}
		Node *next = n->next->next;
		delete n->next;
		n->next = next;
	
		if(next == NULL)
		{
			tail = n;
		}
	}
}

void LinkedList::clear()
{
	Node *n = head;
	while(n != NULL)
	{
		Node *m = n->next;
		delete n;
		n = m;
	}
	head = NULL;
	size = 0;
}

int LinkedList::length() const
{
	return size;
}

void LinkedList::print() const
{
	Node *n = head;
	while(n != NULL)
	{
		cout << n->value << " ";
		n = n->next;
	}
	cout << "\n";
}
