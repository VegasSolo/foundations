#ifndef LIST_H
#define LIST_H

class List
{
	public:
		virtual ~List() {}

		virtual int get(int i) const = 0;
		virtual void set(int i, int x) = 0;

		virtual void insert(int i, int x) = 0;
		virtual void append(int x) = 0;
		virtual void remove(int i) = 0;
		virtual void clear() = 0;

		virtual int length() const = 0;
		virtual void print() const = 0;
};

#endif

