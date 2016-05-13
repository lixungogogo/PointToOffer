#define _CRT_SECURE_NO_WARNINGS 1
#define Get(i,j) GetValue((int**)arr,line, column, i, j)
/**********************************************************
��Ŀ��������һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������
		 ÿһ�ж����մ��ϵ��µ�����˳������
		 �����һ������������������һ����ά�����һ���������ж�
		 �������Ƿ��и�����
��Ŀ���ݣ�1	2	8	9
		 2	4	9	12
		 4	7	10	13
		 6	8	11	15
��ĿҪ�󣺲���7
����������1.���Ұ����������е�����
		 2.���Ҳ������������е�����
		 3.����������ԡ�����ָ��
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