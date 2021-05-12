#pragma once
#include <iostream>
#include <array>
#include <cassert>
#include <exception>

using std::array;

using namespace std;


template<typename T>
class ArrayStack {
	T* elem;
	size_t capacity;
	int top;
public:
	ArrayStack(size_t cap) : capacity(cap), elem(new T[cap]) ,top(-1){}
	
	int size() const
	{
		return top + 1;
	}

	const T& gettop() const
	{
		return elem[top];
	}
	
	
	void pop() throw(exception);
	
	void push( const T& t) 
	{
		elem[++top] = t;
	}
};

template <typename T>
void ArrayStack<T>::pop()
{
	if (top < 0)
		throw std::runtime_error("Its already empty");
	--top;
}

template<typename T>
struct Node
{
	T data;
	Node* next;
};

template<typename T>
class SLinkedStack
{
	Node<T> node; //Let the node always point to the top
	int count; //keep a counter , so that we don't have to traverse when size is asked
public:
	SLinkedStack(const T& elem)
	{
		//Create memory
		//Set the node's left to the current node's top
		//Increse the counter
	}

	void pop() const
	{
		//set Node to Node's next;
		//delete temp Node
		//decrease the counter
	}
	~SLinkedStack()
	{

	}
};

template<typename T, size_t width, size_t height>
using matrix = array< array<T, width>, height>;

using mymatrix = matrix<int, 3, 2>;
constexpr mymatrix mx{ 
	array<int,3>{1,2,3},
	array<int,3>{4,5,6}
};

template<typename T>
using heap_rows = unique_ptr<T[]>;

template<typename T>
using mtx_heap = unique_ptr< heap_rows<T>[] >;

using mtx_heap_int = mtx_heap<int>;

mtx_heap_int make_matrix_heap_int()
{
	using std::make_unique;
	//make rows array
	auto rows_arr = make_unique<heap_rows<int>[]>(2);

	const int width = 3;
	rows_arr[0] = make_unique< int[]>(width);
	rows_arr[1] = make_unique<int[]>(width);
	return rows_arr;
}

template<typename T,auto maxsize>
class Stack
{
public:
	using size_type = decltype(maxsize);
private:
	//std::vector<T> elems;
	std::array<T, maxsize> elems;
	size_type numElems;
public:

	Stack() : numElems{ 0 } {}
	Stack(Stack const&);
	Stack& operator=(Stack const&);
	void push(T const& elem);
	void pop();
	T const& top() const;
	bool empty() const { return elems.empty(); }
	auto size() const {
		return numElems;
	}
};

template<typename T, auto maxsize>
T const& Stack<T, maxsize>::top() const
{
	//assert(!elems.empty(),"hi");
	return elems[numElems - 1];
}

template<typename T, auto maxsize>
void Stack<T, maxsize>::pop()
{
	--numElems;
}


template<typename T, auto maxsize>
bool operator== (Stack<T,maxsize> const& lhs, Stack<T, maxsize> const& rhs);

template<typename T, auto maxsize>
void Stack<T,maxsize>::push(T const& elem)
{
	elems[numElems] = elem;
	++numElems;
}

using StackInt = Stack<int,10>;
using StackFloat = Stack<float,10>;
StackInt arrStackInt[10]{};



void arraytest()
{

	ArrayStack<int> aStack{ 10 };
	try {
		aStack.pop();
	}
	catch (std::exception ex)
	{
		cout << ex.what();
	}
	
	aStack.push(1);
	aStack.push(2);

	cout << aStack.gettop();
	cout << aStack.size() << endl;




	Stack<int, 20u> int20Stack;
	int20Stack.push(7);
	cout << int20Stack.top() << endl;
	//int20Stack.pop();

	auto size1 = int20Stack.size();

	Stack<std::string, 40> strStack;
	strStack.push("hello");
	std::cout << strStack.top() << endl;
	auto size2 = strStack.size();
	
	if (!std::is_same<decltype(size1), decltype(size2)>::value)
	{
		cout << "size types differ" << endl;
	}


	for (auto m : mx)
	{
		for (auto n : m)
			cout << n << " ";
		cout << endl;
	}

	static_assert( mx[0][0] == 1, "good");


	//heap
	static auto use_matrix_heap = []() {
		mtx_heap_int mtxh = make_matrix_heap_int();
		mtxh[0][0] = 1;
		mtxh[0][1] = 2;
		mtxh[0][2] = 3;
		// row 1
		mtxh[1][0] = 4;
		mtxh[1][1] = 5;
		mtxh[1][2] = 6;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << mtxh[i][i] << endl;
		}
		
		return true;
	}();
}

