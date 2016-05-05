#include <iostream>
using namespace std;

//输入一个整数数组，实现一个函数来调整该数组中数字的
//顺序，使得所有奇数位于数组的前半部分，所有的偶数
//位于数组的后半部分

void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ReorderOddEven(int *pData, unsigned int length)
{
	if (pData == NULL || length == 0)
	{
		return;
	}
	int left = 0;
	int right = length - 1;
	while (left < right)
	{
		while (left < right && pData[left] % 2 == 1)
		{
			left++;
		}
		while (left < right && pData[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			Swap(pData[left], pData[right]);
			left++;
			right--;
		}
	}
}

//可扩展性的解法
bool isEven(int n)
{
	return (n & 1) == 0;
}


void ReorderOddEven_(int *pData, unsigned int length, bool (*func)(int))
{
	if (pData == NULL || length == 0)
	{
		return;
	}
	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !(func(*pBegin)))
		{
			pBegin++;
		}
		while (pBegin < pEnd && (func(*pEnd)))
		{
			pEnd--;
		}
		if (pBegin < pEnd)
		{
			Swap(*pBegin, *pEnd);
		}
	}
}

void Show(int *pData, unsigned int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << pData[i] << " ";
	}
	cout << endl;
}

int main()
{
	int pData[] = { 1, 2, 3, 4, 5 };
	Show(pData, sizeof(pData) / sizeof(pData[0]));
	ReorderOddEven(pData, sizeof(pData) / sizeof(pData[0]));
	//ReorderOddEven_(pData, sizeof(pData) / sizeof(pData[0]), isEven);
	Show(pData, sizeof(pData) / sizeof(pData[0]));
	return 0;
}