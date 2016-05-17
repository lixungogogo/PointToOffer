#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/*********************************************************
题目描述：实现函数double power（double base，int exponent）
		 求base的exponent次方，不得使用库函数，同时不需要考虑
		 大数问题
思路分析：1.很容易能想到用循环解答这个题目，但是要考虑当输入为
		 负数或者分数的情况
		 2.用公式求解
		 3.浮点数不能直接比较
所有情况：1.0的0次方，本题中认为0的0次方等于0
		 2.n的0次方
		 3.n的1次方
		 4.n的大于1次方
		 5.n的小于1次方
		 6.n的负数次方
		 7.底数base为0
		 8.底数base为1
		 9.底数base为负数
特殊测试：1.输入正数，负数，0，以及小数
		 2.输入可以分解的数
***********************************************************/
#define EOF 0.00000000001
bool DoubleEqual(double num1, double num2)
{
	if ((num1 - num2) >-EOF && (num1 - num2) < EOF)//double类型不能直接比较
	{
		return true;
	}
	return false;
}

double PowerUnsigned(double base, size_t ex)
{
	double result = 1.0;
	if (ex == 0)
		return 1;
	if (ex == 1)
		return base;
	result = PowerUnsigned(base, ex >> 1);//采用递归，用右移操作代替除法，效率更高
	result *= result;
	if (ex & 0x01 == 1)//考虑ex为奇数的情况
	{
		result *= base;
	}
	return result;
}
double power(double base, int exponent)
{
	double result = 1;
	size_t unex = (size_t)exponent;
	if (DoubleEqual(base,0.0))//考虑指数为0的情况
		return 0;
	if (DoubleEqual(base,1.0) || exponent == 1)//考虑指数为1的情况以及底数为1的情况
		return base;
	if (exponent < 0)//考虑指数为负数的情况
	{
		unex = (size_t)-exponent;
	}
	result = PowerUnsigned(base, unex);
	if (exponent < 0)
	{
		result = 1.0 / result;
	}
	return result;
}

int main()
{
	double result1 = power(2, 2);
	double result2 = power(2, 0);
	double result3 = power(2, 1);
	double result4 = power(2, -2);
	double result5 = power(0, 2);
	double result6 = power(1, 2);
	return 0;
}
