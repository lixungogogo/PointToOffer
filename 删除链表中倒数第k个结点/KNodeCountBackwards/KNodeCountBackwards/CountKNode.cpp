#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/***********************************************
题目要求：链表中倒数第k个结点
题目描述：输入一个链表，输出该链表中倒数第k个结点，本题从1开始
		 奇数，即链表的尾节点是倒数第一个结点。如一个链表有6个
		 结点，从头结点开始他们的值依次是1，2，3，4，5，6。这
		 个链表的倒数第三个结点的值是4.
思路分析：使用两个指针分别设立为快慢指针pFast,pSlow，让快指针
		 先走k-1步，再让快慢指针同时走，直到快指针指向尾节点。
注意事项：1.输入结点为NULL
		 2.输入k = 0
		 3.输入链表的长度小于k
功能测试：1.第k个结点在链表中间
		 2.第k个结点在链表头
		 3.第k个结点在链表尾
特殊测试：1.输入空链表
		 2.输入k等于零
		 3.输入链表长度小于k
扩展题目：1.求链表的中间结点，依然使用快慢指针
		 2.判断一个单链表是否成环
********************************************/
typedef struct Node
{
	int m_value;
	struct Node* m_next;
}ListNode,*pListNode;
pListNode FindKthToTail(pListNode pHead, size_t k)
{
	if (NULL == pHead || k == 0)//空链表
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
