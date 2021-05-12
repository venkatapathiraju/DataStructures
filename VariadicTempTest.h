#pragma  once
#include <iostream>
#include <string>
using namespace std;

namespace variadictemp {

	void print()
	{
		cout << endl << "Lets see how many times do i get called" << endl;
	}
	template<typename T>

	void print(T arg)

	{

		std::cout << arg << endl;  //print passed argument

	}

	template<typename T , typename... Args>
	void print(T firstArg, Args... args)
	{
		std::cout << sizeof...(Args);
		std::cout << sizeof...(args);
		//std::cout << firstArg << endl;
		print(firstArg);
		print(args...);
	}


	struct Node
	{
		int value;
		Node* left;
		Node* right;
		Node(int i = 0) : value(i), left(nullptr), right(nullptr)
		{

		}
	};

	auto left = &Node::left;
	auto right = &Node::right;

	template<typename T, typename... TP>
	Node* traverse(T np, TP... paths)
	{
		return (np ->* ... ->* paths);
	}

	template<typename... T>
	auto foldminus(T... s)
	{
		return(s - ...);
	}

	template<typename... Types>
	void printvar(Types const&... args)
	{
		(std::cout << ... << args);
	}




	//Passing by argument does not decya, qualifiers are retained (const, volatile)
	template<typename T>
	void printR(T const& arg)
	{
		cout << "const reference" << endl;
	}

	template<typename T>
	void outR(T& arg)
	{
		if (std::is_array<T>::value)
		{
			cout << "got array of " << std::extent<T>::value << "elems\n";
		}
		//arg = arg + 1;
	}

	void variatictest()
	{
		cout << endl << "VARIADIC BEGIN" <<endl;

		const std::string strRef = "hi";
		printR(strRef);

		int a[5];
		outR(std::string("hi"));
		

		printvar(1, 2, 3);

		

		Node* root = new Node{ 0 };
		root->left = new Node{ 1 };
		root->left->right = new Node{ 2 };

		Node* node = traverse(root, left, right);
		std::cout << "Traverse:" << node->value<< endl;

		std::string s("hel\\//l/o"s);
		print(7.5, "hello", s);

		cout << endl << "VARIADIC END " << endl;
	}
}