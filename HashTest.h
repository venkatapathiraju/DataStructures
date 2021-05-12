#pragma once

#include <iostream>
#include <vector>

namespace hastest
{

	using uint = unsigned int;

	class hash_map
	{
		std::vector<int> data;

		hash_map(size_t n)
		{
			data = std::vector<int>(n, -1);
		}

		void insert(uint value)
		{
			int n = data.size();
			data[value % n] = value;
			std::cout << "Inserted " << value << std::endl;
		}


	};




	void hashtest()
	{

	}
}