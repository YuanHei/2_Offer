//数值的整数次方
#include <iostream>
#include <math.h>
using namespace std;

//一般解法
bool equal(double num1, double num2)
{
	if (abs(num1 - num2) <= 0.0000001)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double PowerWithUnsigned(double base, int exponent)
{
	double result = 1.0;
	for (int i = 1; i < exponent + 1; ++i)
	{
		result *= base;
	}
	return result;
}

//公式
//a^n = a^(n/2)*a^(n/2)          n为偶数
//a^n = a^((n-1)/2)* a^((n-1)/2) n为奇数
double PowerWithUnsigned_(double base, int exponent)
{
	if (exponent == 0)
	{
		return 1.0;
	}
	if (exponent == 1)
	{
		return base;
	}

	double result = PowerWithUnsigned_(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
	{
		//判断是不是基数
		result *= base;
	}

	return result;
}

double Power(double base, int exponent)
{
	double result = 1.0;
	if (equal(base, 0.0))
	{
		cout << "底数不能为0,出错！" << endl;
		return -1;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}
	result = PowerWithUnsigned(base, absExponent);
	if (exponent < 0)
	{
		result = 1.0 / result;
	}

	return result;
}

int main()
{
	double n, m;
	cin >> n >> m;
	cout << Power(n, m) << endl;
	return 0;
}