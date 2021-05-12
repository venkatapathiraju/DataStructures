
#include <iostream>
#include <set>

namespace chap5{

	std::multiset<std::string> names;

	template<typename T>
	void logAndAdd(T&& name)
	{

		names.emplace(std::forward<T>(name));
	}
}