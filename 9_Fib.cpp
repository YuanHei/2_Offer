//斐波那契数列/青蛙上台阶/矩形覆盖
#include <iostream>
using namespace std;
//非递归
long long int Fibonacci_(unsigned n)
{
	long long int Fib1 = 1;
	long long int Fib2 = 1;
	long long int Fib = 0;
	for (int i = 2; i < n; ++i)
	{
		Fib = Fib1 + Fib2;
		Fib1 = Fib2;
		Fib2 = Fib;
	}
	return Fib2;
}
//递归
long long int Fibonacci(unsigned n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	long long int n; 
	cin >> n;
	cout << Fibonacci(n) << endl;
	cout << Fibonacci_(n) << endl;
	return 0;
}