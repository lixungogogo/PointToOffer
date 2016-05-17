#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/*********************************************************
题目描述：输入数字n，按顺序打印出从1到最大的n位十进制数。比如
		 输入3，则打印出1、2、3一直到最大数即999
思路分析：1.模拟加法——时间复杂度较大
		 2.数字的全排列——使用递归更加简洁
注意事项：1.要考虑到当n足够大的时候，使用整数保存溢出的问题，
		 所以使用字符数组打印数据
		 2.字符数组的大小要比输入参数多一位，为了存储'\0'
		 3.如何判断已经到了最大的n位数 
		 4.创建字符数组，在函数结尾要释放空间
*********************************************************/
/****************************************
函数名称：void Print(char *num, size_t n)
函数功能：打印字符数组
注意事项：打印时高位为0不打印
*****************************************/
void Print(char *num, size_t n)
{
	int i = 0;
	int ret = 0;
	char *temp = num;
	for (; i < n; i++)
	{
		if (num[i] != '0')
			ret = 1;
		if (ret == 1)
		{
			printf("%s\t", temp);
			break;
		}
		else
			temp++;
	}
}
/****************************************
函数名称：int PrintNum(char *num, size_t n,int i) 
函数功能：对字符数组进行处理并打印
思路分析：利用递归对字符数组进行加法处理
*****************************************/
int PrintNum(char *num, size_t n,int i) 
{
	int temp = i;
	int m = n - i;
	int ret = 0;
	for (int count = 0; count < 10; count++)
	{
		num[m] = '0' + count;
		if (m < n-1)
			ret = PrintNum(num, n, i - 1);
		if (ret == 0)
			Print(num,n);
	}
	cout << endl;
	return 1;
}
/****************************************
函数名称：void PrintN(size_t n)
函数功能：打印出1到最大的n位数
注意事项：1.new出的num数组要在函数结尾delete
		 2.注意是否为最大的n位数的判断条件
		 3.new之后要考虑如果new失败时的异常处理
特殊测试：1.输入0
		 2.输入负数
*****************************************/
void PrintN(size_t n)
{
	assert(n > 0);
	char *num = new char[n + 1];
	assert(NULL != num);//new失败后的异常处理
	memset(num, 0, n);
	num[n] = '\0';//最后多一位存放字符串结束标志
	while (num[0] != 9 + '0')//到最大值的判断条件。
	{ 
		PrintNum(num, n, n);
	}
	delete[] num;
}

int main()
{
	PrintN(4);
	return 0;
}