//旋转数组的最小数字
#include <iostream>
using namespace std;

//O(n)
int Min_1(int num[], int n)
{
	if (num == NULL || n <= 0)
	{
		return -1;
	}
	int i;
	for (i = 0; i < n - 2; ++i)
	{
		if ((num[i] > num[i+1]) && (num[i+1] < num[i+2]))
		{
			return i;
		}
	}
	return -1;
}

//O(logn)
int Min_2(int num[], int n)
{
	if (num == NULL || n <= 0)
	{
		return -1;
	}
	//类似二分查找
	int index1 = 0;
	int index2 = n - 1;
	int indexMid = index1;
	while (num[index1] >= num[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (num[indexMid] >= num[index1])
		{
			index1 = indexMid;
		}
		else if (num[indexMid] <= num[index2])
		{
			index2 = indexMid;
		}
	}
	return num[indexMid];
}

int main()
{
	int arr[] = { 4, 5, 1, 2, 3 };
	cout << Min_1(arr, sizeof(arr) / sizeof(arr[0])) << endl;
	cout << Min_2(arr, sizeof(arr) / sizeof(arr[0])) << endl;

	return 0;
}