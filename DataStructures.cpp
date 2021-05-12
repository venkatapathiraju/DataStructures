// DataStructures.cpp : Defines the entry point for the application.
//

#include "DataStructures.h"
#include <vector>
#include <array>
#include "StackTest.h"
#include "QueueTest.h"
#include "HotDrink.h"
using namespace std;
#include "Util.h"
#include "VariadicTempTest.h"
#include "LinkedList.h"
#include "TreeTest.h"
#include "HeapTest.h"
#include "graphtest.h"
#include "SearchTest.h"
#include "SortTest.h"
#include "bfsgraph.h"
#include "matrixbfs.h"
#include "krusalgraph.h"
#include "recursion.h"



char transformfunc(const char c)
{
	return std::toupper(c);
}

template<auto Val, typename T>
T addValue(T x)
{
	return x + Val;
}


int main()
{
	//sorttest::mymergetest();
	recursion::recursiontest();

	

	return 0;
}


class Console
{
public:
	static Console& instance()
	{
		static Console console;
		return console;
	}
private:
	Console() {}
	Console(Console const&) = delete;

};

void oldcode()
{
	

	krusalgraph::run();
	matrixbfs::matrixbfstest();
	cout << endl;
	sorttest::mergetest();

	bfstest::bfstest();
	searchtest::searchtest();

	graphtest::graphtest();

	heaptest::heaptest();
	mytree::treetest();

	mylinklist::mylinktest();

	arraytest();

	variadictemp::variatictest();

	arraytest();

	std::string s("hello");

	//std::transform(s.begin(), s.end(), s.begin(),[](unsigned char c) -> unsigned char { return std::toupper(c); });
	std::transform(s.begin(), s.end(), s.begin(), transformfunc);

	std::vector v1{ 1,2,3,4,5 };
	std::transform(v1.begin(), v1.end(), v1.begin(), addValue<5, int>);
	util::printContainer(v1);

	cout << s;

	int i = 4;


	/*
std::vector<Node*> spMat;
Node* node = new Node();
node->col = 4;
node->val = 8;
*/
//arraytest();

	Queue<int> q{};
	q.push(1);
	q.push(2);
	q.push(3);

	cout << q.peek().value_or(0) << endl;

	DrinkWithVolumeFactory df1;
	df1.make_drink("tea");
	df1.make_drink("coffee");


	DrinkFactory df;
	auto c = df.make_drink("coffee");
	auto t = df.make_drink("tea");

	PersonFactory f;
	Person p1 = f.create_person("hi");
	Person p2 = f.create_person("hello");

	cout << p1 << p2 << endl;

	cout << "Hello CMake." << endl;
}