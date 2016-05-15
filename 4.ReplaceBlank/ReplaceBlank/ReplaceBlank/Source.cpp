#define _CRT_SECURE_NO_WARNINGS 1
/****************************************************
题目描述：请实现一个函数，把字符串中的每个空格替换成%20。
题目用例：输入“We are happy"
		 输出"We%20are%20happy"
应用场景：网络编程中，如果URL参数中含有特殊字符，可能导致
		 服务器端无法获得正确的参数值。我们需要将特殊字符
		 转换为服务器可以识别的字符。
		 转换的规则是；在'%'后面跟上ASCII码的两位十六进制
		 表示。
题目注意：本题有两种解法
		 1.替换
		 2.创建新的字符串
		 需要提前向面试官问清楚
解法假设：面试官要求在原来的字符串上做替换，并且保证输入的
		 字符串后面有足够多的空闲内存。
两种方法：1.时间复杂度为O（n^2）:从前向后替换
		 2.时间复杂度为O(n)：先遍历一遍，得出空格数量，再
		   从后向前替换
解法分析：从后向前替换更加高效
函数名称：void ReplaceBlank(char string[],int length)
*****************************************************/
#include <iostream>
#include <assert.h>
using namespace std;
//1.replace时间复杂度O(n^2)：从前往后替换
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
//2.时间复杂度O(n)的解法：从后向前替换
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