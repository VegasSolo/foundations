/*
 * File:	stack.h
 * Author:	Luke Godfrey
 */

#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

class Stack
{
	public:
		Stack();
		void push(char x);
		char pop();
		char top() const;
		int size() const;
		void print() const;
	private:
		vector<char> elements;
};

#endif
