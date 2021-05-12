

namespace recursion
{


	//tail recursion fibonocci

	int fibonocci(int n)
	{
		if (n == 0) return 0;
		if (n == 1) return 1;

		return fibonocci(n - 1) + fibonocci(n - 2);
	}

	void tailfibonocci(int n, int &accumulate)
	{
		if (n == 0)
		{
			accumulate += 0;
			return;
		}
		if (n == 1) {
			accumulate += 1;
			return;
		}

		tailfibonocci(n - 1, accumulate);
		tailfibonocci(n - 2, accumulate);
	}


	void recursiontest()
	{
		std::cout << fibonocci(10);
		int fib = 0;
		tailfibonocci(10, fib);
		std::cout << "tail recursion ->" << fib;
	}


}