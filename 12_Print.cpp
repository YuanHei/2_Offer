//打印1到最大的n位数
#include <iostream>
using namespace std;
//相当于大数加法，用字符串来表示数字
void PrintNumber(char *str)
{
	bool isBeginning0 = true;
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (isBeginning0 && str[i] != '0')
		{
			isBeginning0 = false;
		}
		if (!isBeginning0)
		{
			cout << str[i];
		}
	}
	cout << endl;
}

void PrintToMaxOfDigitsRecursively(char *str, int length, int index)
{
	if (index == length - 1)
	{
		//结束标志
		PrintNumber(str);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		//各位数字填写
		str[index + 1] = i + '0';
		PrintToMaxOfDigitsRecursively(str, length, index + 1);
	}
}

void PrintToMaxOfNDigits(int n)
{
	if (n < 0)
	{
		return;
	}
	char *str = new char[n + 1];
	//开辟n+1个空间，最后一个存放'\0'
	memset(str, '0', n);
	str[n] = '\0';
	//初始化

	for (int i = 0; i < 10; ++i)
	{
		str[0] = i + '0';
		//从低位开始进行输出
		PrintToMaxOfDigitsRecursively(str, n, 0);
	}

	delete[]str;
}

int main()
{
	int n;
	cin >> n;
	PrintToMaxOfNDigits(n);
	return 0;
}