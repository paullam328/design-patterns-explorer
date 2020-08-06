#pragma once

//You wrote an old version of Fibonacci sequence, but yout think your friend's version is better...

#include <iostream>

using namespace std;

namespace Adapter {

	class MyFibonacci {
	public:
		virtual void fibonacci(int n1, int n2, int numCount)
		{
			--numCount;

			if (numCount > 0)
			{
				cout << n1 << ", ";
				fibonacci(n2, n1 + n2, numCount);
			}
			else
				cout << n1 << endl;
		}
	};

	class MyFriendsSolution {
	public:
		int Fib(int n) {
			int num1 = 0;
			int num2 = 1;
			int num_temp;
			int num_next = 1;
			if (n >= 1)
				cout << 0 << " ";
			if (n >= 2)
				cout << 1 << " ";
			for (int i = 0; i < n - 2; i++) {
				num_next = num1 + num2;
				cout << num_next << " ";
				num1 = num2;
				num2 = num_next;
			}
			return n;
		}
	};

	//Your Friend's functions are different.  Is it really adaptable to your code?
	//create an adapter instead extending your naming conventions:

	class FibonacciAdapter : public MyFibonacci, private MyFriendsSolution {
	public:
		virtual void fibonacci(int n1, int n2, int numCount)
		{
			Fib(numCount);
		}
	};

	class Client {
	public:
		void Calculate();
	};
}