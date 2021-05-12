#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "Util.h"

namespace sorttest
{

	std::vector<int> mergesort(std::vector<int> part1, std::vector<int> part2)
	{
		util::printContainer(part1);
		util::printContainer(part2);
		std::vector<int> merged;
		auto iter1 = part1.begin();
		auto iter2 = part2.begin();

		while (iter1 != part1.end() && iter2 != part2.end())
		{
			if (*iter1 < *iter2)
			{
				merged.emplace_back(*iter1);
				iter1++;
			}
			else
			{
				merged.emplace_back(*iter2);
				iter2++;
			}
		}

		if (iter1 != part1.end())
		{
			for (; iter1 != part1.end(); iter1++)
				merged.emplace_back(*iter1);
		}

		if (iter2 != part2.end())
		{
			for (; iter2 != part2.end(); iter2++)
				merged.emplace_back(*iter2);
		}
		util::printContainer(merged);
		return merged;
	}
	



	std::vector<int> mergesort(std::vector<int> vec)
	{
		if (vec.size() > 1)
		{
			auto mid = vec.size() / 2;
			auto left_half = mergesort(std::vector<int>(vec.begin(),vec.begin()+mid));
			auto right_half = mergesort(std::vector<int>(vec.begin()+mid, vec.end()));
			return mergesort(left_half, right_half);
		}
		return vec;
	}


	template<typename T>
	void quicksort(T first, T last)
	{
		if (first == last)return;
		int dist = std::distance(first, last);
		auto pivot = *std::next(first, dist / 2);
		//Get all the elements that are less than pivot element
		T firsthalf = std::partition(first, last, [pivot](const auto& em) { return em < pivot; });
		T secondhalf = std::partition(firsthalf, last, [pivot](const auto& em) { return !(pivot < em); });
		quicksort(first, firsthalf);
		quicksort(secondhalf, last);
	}

	template<typename T>
	void selection_sort(T begin, T end)
	{
		cout << "Selection sort " << endl;
		for (auto it = begin; it != end; ++it)
		{
			std::iter_swap(it, std::min_element(it, end));
			
		}
	}


	

	void recursivemerge(std::vector<int>::iterator &itBegin, std::vector<int>::iterator &itEnd)
	{
		cout << "Recursive merge on ";
		for (auto it = itBegin; it != itEnd; it++)
		{
			cout << *it << "->";
		}

		auto distance = std::distance(itBegin, itEnd);
		cout << endl << "Distance :" << distance << endl;
		if (distance <= 1) return;
		if (distance == 2)
		{
			cout << "Compare " << *itBegin << " and " << *(itBegin + 1) << endl;
			if (*itBegin <= *(itBegin+1))
				cout << "No need to swap" << endl;
			else
			{
				iter_swap(itBegin, itBegin+1);
				cout << "swapping " << endl;
			}
			return;
		}

		recursivemerge(itBegin, itBegin + distance / 2);
		recursivemerge(itBegin + distance/2, itEnd);
		
		
		
	}
	

	void mymergetest()
	{
		std::vector<int> myvec{9, 4, 3, 7, 4, 5, 2, 7, 6};


		for (auto it = myvec.begin(); it != myvec.end(); it++)
		{
			auto next = it ;
			if (next == myvec.end()) return;
			auto min = std::min_element(next, myvec.end());
			if (*it > *min)
				swap(*it, *min);
			//for (auto jt = next; jt != myvec.end(); jt++)
			//{
			//	if (*it > *jt)
			//		swap(*it, *jt);
			//}
		}

		cout << "Sorted values";
		for (auto it = myvec.begin(); it != myvec.end(); it++)
		{
			cout << *it << "->";
		}


		myvec = std::vector<int>{ 9, 4, 3, 7, 4, 5, 2, 7, 6 };


		auto it = myvec.begin();
		auto end = myvec.end();
		recursivemerge(it, end);
		

		cout << "Recursive merge on ";
		for (auto it = myvec.begin(); it != myvec.end(); it++)
		{
			cout << *it << "->";
		}





	}
	

	void mergetest()
	{
		std::vector<int> vec1{ 9,8,7,6,5,4,3,2,1,0 };
		auto sortedvec1 = mergesort(vec1);
		util::printContainer(sortedvec1);

		std::vector<int> vec2(vec1);
		selection_sort(vec2.begin(), vec2.end());
		util::printContainer(vec2);

		cout << "sort alogirthm begin" << endl;
		std::vector<int> vec3{ 100,1000,1200};
		quicksort(vec3.begin(), vec3.end());
		util::printContainer(vec3);
		cout << endl << "sort algorithm end" << endl;

		std::vector<std::pair<int, int> > items{ {1,10},{2,7},{5,15},{9,10},{2,12},{3,11},{4,5} };
		constexpr int weight = 40;
		std::sort(items.begin(), items.end(), [](const std::pair<int, int> a1, const std::pair<int, int>a2) {
			return (float)a2.second / (float)a2.first < (float)a1.second / (float)a1.first;
			});

		//Remove any elements that are greater than the volume


		for (auto n : items)
			cout << n.first <<"->"<< n.second << endl;
		

	}
}