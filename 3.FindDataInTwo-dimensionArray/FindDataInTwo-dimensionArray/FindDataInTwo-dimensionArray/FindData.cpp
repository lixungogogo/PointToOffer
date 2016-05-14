#define _CRT_SECURE_NO_WARNINGS 1
#define Get(i,j) GetValue((int**)arr,line, column, i, j)
/**********************************************************
题目描述：在一个二维数组中，每一行都按照从左到右递增的顺序排序，
		 每一列都按照从上到下递增的顺序排序。
		 请完成一个函数，输入这样的一个二维数组和一个整数，判断
		 数组中是否含有该整数
题目数据：	 1	2	8	9
		 2	4	9	12
		 4	7	10	13
		 6	8	11	15
题目要求：查找7
测试用例：1.查找包含在数组中的数字
		 2.查找不包含在数组中的数字
		 3.特殊输入测试——空指针
**********************************************************/
#include <iostream>
#include <assert.h>
using namespace std;

int GetValue(int**arr, int line,int column, int i, int j)
{
	if (i >= line || j >= column)
	{
		cout << "wrong" << endl;
		return -1;
	}
	return *((int *)arr + column * i + j);
}

int FindData(int (**arr), int data,int line,int column) 
{
	assert(*arr);
	int lMax = line - 1;
	int cMax = column - 1;
	int l = 0;
	int c = cMax;
	while (Get(l, c) != data )
	{
		int num = Get(l, c);
		if (num > data)
		{
			c--;
		}
		else
		{
			l++;
		}
		if (l > lMax || c < 0)
		{
			return -1;
		}
	}
	return 1;
}
int main()
{
	int arr[4][4] = { 1, 2, 8,  9,
					  2, 4, 9,  12,
					  4, 7, 10, 13,
					  6, 8, 11, 15};
	FindData((int**)(arr), 10, 4,4);
	return 0;
}
