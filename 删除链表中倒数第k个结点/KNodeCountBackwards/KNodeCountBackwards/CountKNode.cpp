#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/***********************************************
��ĿҪ�������е�����k�����
��Ŀ����������һ����������������е�����k����㣬�����1��ʼ
		 �������������β�ڵ��ǵ�����һ����㡣��һ��������6��
		 ��㣬��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6����
		 ������ĵ�������������ֵ��4.
˼·������ʹ������ָ��ֱ�����Ϊ����ָ��pFast,pSlow���ÿ�ָ��
		 ����k-1�������ÿ���ָ��ͬʱ�ߣ�ֱ����ָ��ָ��β�ڵ㡣
ע�����1.������ΪNULL
		 2.����k = 0
		 3.��������ĳ���С��k
���ܲ��ԣ�1.��k������������м�
		 2.��k�����������ͷ
		 3.��k�����������β
������ԣ�1.���������
		 2.����k������
		 3.����������С��k
��չ��Ŀ��1.��������м��㣬��Ȼʹ�ÿ���ָ��
		 2.�ж�һ���������Ƿ�ɻ�
********************************************/
typedef struct Node
{
	int m_value;
	struct Node* m_next;
}ListNode,*pListNode;
pListNode FindKthToTail(pListNode pHead, size_t k)
{
	if (NULL == pHead || k == 0)//������
	{
		return NULL;
	}
	pListNode pFast = pHead, pSlow = pHead;
	while (--k && pFast->m_next)
	{
		pFast = pFast->m_next;
	}
	assert(k == 0);
	while (pFast->m_next)
	{
		pFast = pFast->m_next;
		pSlow = pSlow->m_next;
	}
	return pSlow;
}
