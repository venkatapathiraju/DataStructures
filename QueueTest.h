
#pragma once
#include <queue>
#include <optional>
#include <mutex>

template<typename T>
class Queue {
	std::queue<T> myq;
	mutable std::mutex mutex_;
public:
	Queue() = default;
	Queue(const Queue<T>&) = delete;
	Queue& operator=(const Queue<T>&) = delete;

	Queue(Queue<T>&& other)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		myq = std::move(other.myq);
	}

	virtual ~Queue() {}

	bool empty() const { return myq.empty(); }
	unsigned long size() const { return myq.size(); }

	std::optional<T> pop()
	{
		std::lock_guard<std::mutex> lock(mutex_);
		if (myq.empty())
			return {};
		T tmp = myq.front();
		myq.pop();
		return temp;
	}

	void push(const T& item)
	{
		std::lock_guard<std::mutex> lock(mutex_);
		myq.push(item);
	}

	std::optional<T> peek()
	{
		if (myq.empty())
			return {};
		return myq.front();
	}
};


template<typename T>
class MyQueue
{

};