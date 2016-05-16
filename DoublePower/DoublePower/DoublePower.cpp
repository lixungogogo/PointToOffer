#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/*********************************************************
��Ŀ������ʵ�ֺ���double power��double base��int exponent��
		 ��base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ����
		 ��������
˼·������1.���������뵽��ѭ����������Ŀ������Ҫ���ǵ�����Ϊ
		 �������߷��������
		 2.�ù�ʽ���
		 3.����������ֱ�ӱȽ�
���������1.0��0�η�����������Ϊ0��0�η�����0
		 2.n��0�η�
		 3.n��1�η�
		 4.n�Ĵ���1�η�
		 5.n��С��1�η�
		 6.n�ĸ����η�
		 7.����baseΪ0
		 8.����baseΪ1
		 9.����baseΪ����
������ԣ�1.����������������0���Լ�С��
		 2.������Էֽ����
***********************************************************/
#define EOF 0.00000000001
bool DoubleEqual(double num1, double num2)
{
	if ((num1 - num2) >-EOF && (num1 - num2) < EOF)//double���Ͳ���ֱ�ӱȽ�
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
	result = PowerUnsigned(base, ex >> 1);//���õݹ飬�����Ʋ������������Ч�ʸ���
	result *= result;
	if (ex & 0x01 == 1)//����exΪ���������
	{
		result *= base;
	}
	return result;
}
double power(double base, int exponent)
{
	double result = 1;
	size_t unex = (size_t)exponent;
	if (DoubleEqual(base,0.0))//����ָ��Ϊ0�����
		return 0;
	if (DoubleEqual(base,1.0) || exponent == 1)//����ָ��Ϊ1������Լ�����Ϊ1�����
		return base;
	if (exponent < 0)//����ָ��Ϊ���������
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
