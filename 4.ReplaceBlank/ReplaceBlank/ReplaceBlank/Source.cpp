#define _CRT_SECURE_NO_WARNINGS 1
/****************************************************
��Ŀ��������ʵ��һ�����������ַ����е�ÿ���ո��滻��%20��
��Ŀ���������롰We are happy"
		 ���"We%20are%20happy"
Ӧ�ó������������У����URL�����к��������ַ������ܵ���
		 ���������޷������ȷ�Ĳ���ֵ��������Ҫ�������ַ�
		 ת��Ϊ����������ʶ����ַ���
		 ת���Ĺ����ǣ���'%'�������ASCII�����λʮ������
		 ��ʾ��
��Ŀע�⣺���������ֽⷨ
		 1.�滻
		 2.�����µ��ַ���
		 ��Ҫ��ǰ�����Թ������
�ⷨ���裺���Թ�Ҫ����ԭ�����ַ��������滻�����ұ�֤�����
		 �ַ����������㹻��Ŀ����ڴ档
���ַ�����1.ʱ�临�Ӷ�ΪO��n^2��:��ǰ����滻
		 2.ʱ�临�Ӷ�ΪO(n)���ȱ���һ�飬�ó��ո���������
		   �Ӻ���ǰ�滻
�ⷨ�������Ӻ���ǰ�滻���Ӹ�Ч
�������ƣ�void ReplaceBlank(char string[],int length)
*****************************************************/
#include <iostream>
#include <assert.h>
using namespace std;
//1.replaceʱ�临�Ӷ�O(n^2)����ǰ�����滻
void ReplaceBlank1(char string[], int length)
{
	assert(string);
	int iCount = 0;
	char *temp = string;
	int count = length;
	while (*temp)
	{
		count = length + iCount;
		if (*temp == ' ')
		{
			while ((string + count - 1) != temp)
			{
				*(string + count + 1) = *(string + count - 1);
				count--;
			}
			*temp = '%';
			*(temp + 1) = '2';
			*(temp + 2) = '0';
			iCount += 2;
		}
		temp++;
	}
}
//2.ʱ�临�Ӷ�O(n)�Ľⷨ���Ӻ���ǰ�滻
void ReplaceBlank2(char string[], int length)
{
	assert(string);
	char *tail = string;
	char *head = string;
	int iCount = 0;
	int i = 0;
	while (*tail)
	{
		if (*tail == ' ')
			iCount++;
		tail++;
	}
	i = iCount - 1;
	while (*tail != *head)
	{
		if (*tail != ' ')
		{
			*(tail + iCount*3 - i-1) = *tail;
			tail--;
		}
		else
		{
			*(tail + iCount*3-3-i) = '%';
			*(tail + iCount*3-2-i) = '2';
			*(tail + iCount--*3-1-i) = '0';
			tail --;
			i--;
		}
		
	}
	if (*head == ' ')
	{
		*head = '%';
		*(head + 1) = '2';
		*(head + 2) = '0';
	}
}
int main()
{
	char s[20] = { 'w','e',' ','a','r','e',' ','h','a','p','p','y','\0','1','1','1'};
	ReplaceBlank1(s, 13);
	cout << s;
	getchar();
	return 0;
}