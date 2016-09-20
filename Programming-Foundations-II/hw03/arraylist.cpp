#include "arraylist.h"
#include "timer.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList()
{
	size = 0;
	capacity = 10;
	array = new int[capacity];
}

ArrayList::ArrayList(const ArrayList &other)
{
	size = other.size;
	capacity = other.capacity;
	array = new int[capacity];
	for(int i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

ArrayList::~ArrayList()
{
	delete[] array;
}

int ArrayList::get(int i) const
{
	return array[i];
}

void ArrayList::set(int i, int x)
{
	array[i] = x;
}

void ArrayList::insert(int i, int x)
{
	size++;

	if(size <= capacity)
	{
		for(int j = size - 1; j >= i; j--)
		{
			array[j] = array[j - 1];
		}
		array[i] = x;
	}
	else
	{
		capacity += 10;
		int *newArray = new int[capacity];
		
		// Copy first part of the array
		for(int j = 0; j < i; j++)
		{
			newArray[j] = array[j];
		}
		
		// Set new element
		newArray[i] = x;
		
		// Copy second part of the array
		for(int j = i + 1; j < size; j++)
		{
			newArray[j] = array[j - 1];
		}
	
		delete[] array;
		array = newArray;
	}
}

void ArrayList::append(int x)
{
	insert(length(), x);
}

void ArrayList::remove(int i)
{
	size--;
	for(int j = i; j < size; j++)
	{
		array[i] = array[i + 1];
	}
}

void ArrayList::clear()
{
	size = 0;
}

int ArrayList::length() const
{
	return size;
}

void ArrayList::print() const
{
	for(int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}
