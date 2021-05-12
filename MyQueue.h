#pragma once

#include <iostream>

using namespace std;

const int SIZE = 10;
class que
{
	int *arr;
	int capacity, int front{ 0 }, int rear{ -1 }, int count{ 0 };

public:
	que(const int size = SIZE) :capacity(size), arr{new int[size]}
	{

	}

	virtual ~que() {}

	void enqueue(int x)
	{
		if (count == capacity)
			count << "sorry mate, its already full.";
		
	}

	void deque()
	{
		
	}

	ostream& operator<<(ostream& out,const que& q)
	{
		for (int i = 0; i < count; i++)
			out << arr[i] << "->";
		out << endl;
		return out;
	}

};