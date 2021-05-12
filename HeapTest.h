#pragma once
#include <iostream>
#include <queue>
#include <vector>

#include "Util.h"

namespace heaptest {


	struct median
	{
		std::priority_queue<int> maxHeap;
		std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

		double get()
		{
			if (maxHeap.size() == minHeap.size())
				return (maxHeap.top() + minHeap.top()) / 2.0;
			if (maxHeap.size() < minHeap.size())
				return minHeap.top();
			return maxHeap.top();
		}

        void insert(int data)
        {
            if (maxHeap.size() == 0) {
                maxHeap.push(data);
                return;
            }

            if (maxHeap.size() == minHeap.size())

            {

                if (data <= get())

                    maxHeap.push(data);

                else

                    minHeap.push(data);



                return;

            }

            if (maxHeap.size() < minHeap.size())

            {

                if (data > get())

                {

                    maxHeap.push(minHeap.top());

                    minHeap.pop();

                    minHeap.push(data);

                }

                else

                    maxHeap.push(data);

                return;

            }

            if (data < get())

            {

                minHeap.push(maxHeap.top());

                maxHeap.pop();

                maxHeap.push(data);

            }

            else

                minHeap.push(data);
                    

		}


     

	};


    struct node
    {
        int data;
        int listPosition;
        int dataPosition;
    };

    std::vector<int> merge(const std::vector<std::vector<int>>& input)
    {
        auto comparator = [](const node& left, const node& right) {
            if (left.data == right.data)
                return left.listPosition > right.listPosition;
            return left.data > right.data;
        };

        std::vector<node> heap;
        for (int i = 0; i < input.size(); i++)
        {
            heap.push_back({ input[i][0], i, 0 });
            std::push_heap(heap.begin(), heap.end(), comparator);
        }

        std::vector<int> result;
        while (!heap.empty())
        {
            std::pop_heap(heap.begin(), heap.end(), comparator);
            auto min = heap.back();
            heap.pop_back();

            result.push_back(min.data);
            int nextIndex = min.dataPosition + 1;
            if (nextIndex < input[min.listPosition].size())
            {
                heap.push_back({ input[min.listPosition][nextIndex], min.listPosition, nextIndex });
                std::push_heap(heap.begin(), heap.end(), comparator);
            }
        }

        return result;
    }


	void heaptest()
	{

        {
            std::vector<int> v1 = { 1, 3, 8, 15, 105 };
            std::vector<int> v2 = { 2, 3, 10, 11, 16, 20, 25 };
            std::vector<int> v3 = { -2, 100, 1000 };
            std::vector<int> v4 = { -1, 0, 14, 18 };
            auto result = merge({ v1, v2, v3, v4 });
            for (auto i : result)
                std::cout << i << ' ';
        }

        median med;
        med.insert(1);

        std::cout << "Median after insert 1: " << med.get() << std::endl;

        med.insert(5);

        std::cout << "Median after insert 5: " << med.get() << std::endl;

        med.insert(2);

        std::cout << "Median after insert 2: " << med.get() << std::endl;

        med.insert(10);

        std::cout << "Median after insert 10: " << med.get() << std::endl;

        med.insert(40);

        std::cout << "Median after insert 40: " << med.get() << std::endl;
	}
}