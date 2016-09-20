/*
 * File:	stack.cpp
 * Author:	Luke Godfrey
 */

#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack()
{
}

void Stack::push(char x)
{
	elements.push_back(x);
}

char Stack::pop()
{
	int x = elements[size() - 1];
	elements.pop_back();
	return x;
}

char Stack::top() const
{
	return elements[size() - 1];
}

int Stack::size() const
{
	return elements.size();
}

void Stack::print() const
{
	// print backwards so it looks like the stack actually looks
	for(int i = size() - 1; i >= 0; i--)
	{
		cout << elements[i] << endl;
	}
}
