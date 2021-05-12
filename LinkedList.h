#pragma once

namespace mylinklist
{
	template<typename T>
	struct LinkNode
	{
		T elem;
		LinkNode* next;

	};

	template<typename T>
	class MyLinkedList
	{
	public:
		MyLinkedList();
		~MyLinkedList();
		bool empty() const;
		const T& front() const;
		void addFront(const T& elem);
		void removeFront();
	private:
		LinkNode<T>* elem;
	};

	template<typename T>
	MyLinkedList<T>::MyLinkedList()
	{
	}

	template<typename T>
	MyLinkedList<T>::~MyLinkedList(){}

	template<typename T>
	bool MyLinkedList<T>::empty() const
	{
		return (elem == nullptr);
	}

	void mylinktest()
	{
		MyLinkedList<int> intList;
		cout << "Is Empty->" << intList.empty() << endl;
	}

};