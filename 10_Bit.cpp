//二进制中1的个数
#include <iostream>
using namespace std;

//方法一
int Count(int n)
{
	int count = 0;
	while (n)
	{
		if (n & 1)
		{
			count++;
		}
		n /= 2;
	}
	return count;
}
//方法二
int Count_(int n)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);//有多少个一就重复多少次
		count++;
	}
	return count;
}

int main()
{
	int n;
	cin >> n;
	cout << Count(n) << endl;
	cout << Count_(n) << endl;
	return 0;
}