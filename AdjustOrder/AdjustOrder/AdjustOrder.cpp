#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/*********************************************************
��Ŀ��������������˳��ʹ����λ��ż��ǰ��
��ĿҪ������һ���������飬ʵ��һ�����������������������ֵ�˳��
		 ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ��
		 ���֡�
˼·������������������ָ��*pBegin��*pEnd�ֱ�ָ�����鿪ͷ�ͽ�β��
		 ���ͷָ��ָ�����ż����βָ��ָ���������򽻻�����������
		 ��ͷָ���һ��βָ���һ
˼·��չ���������Ҫ���������λ�ڷǸ���ǰ�棬�������������ڲ�����
		 �����������棬��η�����
�������������ר������һ���������ڴ�Ų�ͬ��Ҫ��ͨ������������
		 �е���Ҫ�󣬲�����д�µĺ�����
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