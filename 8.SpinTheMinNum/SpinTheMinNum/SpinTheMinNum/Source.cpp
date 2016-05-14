#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/**********************************************
题目描述：把一个数组最开始的若干个元素搬到数组末尾，我们
	  称之为数组的旋转。输入一个递增排序的数组的一个
	  旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}
	  是数组{1，2，3，4，5}的一个旋转，该数组的最小值
	  是1
思路分析：1.方法一是从头到尾遍历数组，找出最小值，这个方法
	 的时间复杂度为O(n),虽然能够实现找出最小值，但是
	 效率不高。
	 2.因为旋转数组的一个特性是：我们可以将旋转数组
	 看成是两个有序的子数组组成的，所以只要我们可以
 	 找到这两个数组的分界点，即找到了最小值，这个方法
	 中我们可以借助二分法进行查找，设立两个指针，看
	 头指针和尾指针值的比较，进行情况的区分。
特殊情况：1.升序数组，即没有进行旋转的数组
	  2.类似于{1，0，1，1，1}这样的头尾相同的数组
	  3.上述两种情况我们可以直接用遍历查找
特殊测试：1.输入空数组
	  2.输入升序数组
	  3.输入头尾以及中间值相同的数组
	  4.输入只有一个值的数组
**********************************************/

int MinInOrder(int num[], int length)//遍历数组找出最小值函数
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
	int mid = left + (right - left) / 2;//为了防止length过大导致left + right溢出
	if (left == right)//数组中只有一个值时，返回该值
		return num[left];
	if (num[left] < num[right])//旋转数组的特性，只要最左边小于最右边，一定是升序数组，返回最左边的
		return num[left];
	while (num[left] >= num[right])
	{
		mid = left + (right - left) / 2;
		if (left == right - 1)	//找到了分界点，即最小值
			return num[right];
		if (num[left] == num[right] && num[left] == num[mid])//类似于{1，0，1，1，1}的情况
			return MinInOrder(num, length);//遍历数组找出最小值
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
