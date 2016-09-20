#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "list.h"

class ArrayList: public List
{
	public:
		ArrayList();
		ArrayList(const ArrayList &other);
		virtual ~ArrayList();

		virtual int get(int i) const;
		virtual void set(int i, int x);

		virtual void insert(int i, int x);
		virtual void append(int x);
		virtual void remove(int i);
		virtual void clear();

		virtual int length() const;
		virtual void print() const;
	private:
		int *array;
		int size, capacity;
};

#endif

