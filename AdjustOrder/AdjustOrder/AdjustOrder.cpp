#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/*********************************************************
题目描述：调整数组顺序使奇数位于偶数前面
题目要求：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
		 使得所有奇数位于数组的前半部分，所有偶数位于数组的后半
		 部分。
思路分析：可以设立两个指针*pBegin，*pEnd分别指向数组开头和结尾，
		 如果头指针指向的是偶数，尾指针指向奇数，则交换两个数，否
		 则头指针加一，尾指针减一
思路扩展：如果需求要求调整负数位于非负数前面，被三整除的数在不被三
		 整除的数后面，如何分析？
解决方法：可以专门设置一个函数用于存放不同的要求，通过该需求函数进
		 行调整要求，不用再写新的函数。
**********************************************************/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
bool IsData(int num)
{
	return (num % 2 == 0);
}
void Adjust(int *num, int size)
{
	assert(num);
	int *pBegin = num;
	int *pEnd = num + size - 1;
	while (pBegin < pEnd)
	{
		if (IsData(*pBegin)&& !IsData(*pEnd))
		{
			swap(pBegin, pEnd);
			pBegin++;
			pEnd--;
		}
		else if (IsData(*pBegin) && IsData(*pEnd))
		{
			pEnd--;
		}
		else
		{
			pBegin++;
			pEnd--;
		}
	}
}

int main()
{
	int num[] = {0,1,2,3,4,5,6,7,8,9};
	Adjust(num, sizeof(num) / sizeof(num[0]));
	return 0;
}