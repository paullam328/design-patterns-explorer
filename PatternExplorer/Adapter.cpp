#include "Adapter.h"

namespace Adapter {

	void Client::Calculate()
	{
		MyFibonacci* fib1 = new MyFibonacci();
		MyFibonacci* fib2 = new FibonacciAdapter(); //one line of code change here for adapter - using my friend's solution
		fib1->fibonacci(0, 1, 5);
		fib2->fibonacci(0, 1, 5);
	}

}