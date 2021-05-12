#pragma once
#include <iostream>
using namespace std;

namespace util {
	template<typename T>
	void printContainer(T const& elem)
	{
		for (auto n : elem)
		{
			cout << n << ",";
		}
		cout << endl;
	}
}
