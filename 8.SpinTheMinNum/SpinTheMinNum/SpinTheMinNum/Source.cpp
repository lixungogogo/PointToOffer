#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/**********************************************
��Ŀ��������һ�������ʼ�����ɸ�Ԫ�ذᵽ����ĩβ������
		 ��֮Ϊ�������ת������һ����������������һ��
		 ��ת�������ת�������СԪ�ء���������{3,4,5,1,2}
		 ������{1��2��3��4��5}��һ����ת�����������Сֵ
		 ��1
˼·������1.����һ�Ǵ�ͷ��β�������飬�ҳ���Сֵ���������
		 ��ʱ�临�Ӷ�ΪO(n),��Ȼ�ܹ�ʵ���ҳ���Сֵ������
		 Ч�ʲ��ߡ�
		 2.��Ϊ��ת�����һ�������ǣ����ǿ��Խ���ת����
		 �����������������������ɵģ�����ֻҪ���ǿ���
		 �ҵ�����������ķֽ�㣬���ҵ�����Сֵ���������
		 �����ǿ��Խ������ַ����в��ң���������ָ�룬��
		 ͷָ���βָ��ֵ�ıȽϣ�������������֡�
���������1.�������飬��û�н�����ת������
		 2.������{1��0��1��1��1}������ͷβ��ͬ������
		 3.��������������ǿ���ֱ���ñ�������
������ԣ�1.���������
		 2.������������
		 3.����ͷβ�Լ��м�ֵ��ͬ������
		 4.����ֻ��һ��ֵ������
**********************************************/

int MinInOrder(int num[], int length)
{
	assert(NULL != num || length > 0);
	int icount = 0;
	int min = num[0];
	for (icount = 1; icount < length; icount++)
	{
		if (num[icount] < min)
			min = num[icount];
	}
	return min;
}

int Min(int num[], int length)
{
	assert(NULL != num || length > 0);
	int left = 0;
	int right = length - 1;
	int mid = left + (right - left) / 2;//Ϊ�˷�ֹlength������left + right���
	if (left == right)//������ֻ��һ��ֵʱ�����ظ�ֵ
		return num[left];
	if (num[left] < num[right])//��ת��������ԣ�ֻҪ�����С�����ұߣ�һ�����������飬��������ߵ�
		return num[left];
	while (num[left] >= num[right])
	{
		mid = left + (right - left) / 2;
		if (left == right - 1)	//�ҵ��˷ֽ�㣬����Сֵ
			return num[right];
		if (num[left] == num[right] && num[left] == num[mid])//������{1��0��1��1��1}�����
			return MinInOrder(num, length);//���������ҳ���Сֵ
		if (num[left] < num[mid])
		{
			left = mid;
		}
		else if (num[left] > num[mid])
		{
			right = mid;
		}
	}
	return num[mid];
}