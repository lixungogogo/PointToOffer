#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/*****************************************************************
题目名称：在O（1）时间删除链表节点
题目描述：给定单向链表的头指针和一个结点指针，定义一个函数
		 在O（1）时间删除该结点。链表结点与函数定义如下：
		 struct ListNode
		 {
			int m_nValue;
			ListNode *m_pNext;
		 };
		 void DeleteNode(ListNode **pHead,ListNode * pToBeDelete);
思路分析：在删除单链表结点时，一般做法为从头指针开始遍历单链表，
		 直到找到该结点，再进行删除。但是这种做法因为是顺序查找，
		 所以时间复杂度为O(n),本题要求时间复杂度为O(1)，所以
		 我们可以采用交换法，将将要删除的结点的值与下一个结点值
		 交换，然后直接删除下一个结点，即实现了时间复杂度为O(1)
		 的删除链表结点操作
特殊情况：1.输入为空链表
		 2.输入只有一个结点的链表
		 3.被删除结点为头结点
		 4.被删除结点为尾节点
注意事项：1.判断头指针是否为空以及被删除结点是否为空
		 2.释放空间后将指针置空，防止野指针的出现
		 3.本函数前提是被删除结点一定在链表内
********************************************************************/
struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};
void DeleteNode(ListNode **pHead, ListNode * pToBeDelete)
{
	if ((*pHead) == NULL || pToBeDelete == NULL)//空链表
	{
		printf("Empty");
		return;
	}
	if (*pHead == pToBeDelete)//链表中只有一个结点
	{
		free(pToBeDelete);
		pToBeDelete = NULL;
		*pHead = NULL;
		return;
	}
	if (pToBeDelete->m_pNext == NULL)//链表中含有多个结点删除尾节点
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext != pToBeDelete)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = NULL;
		free(pToBeDelete);
		pToBeDelete = NULL;
		return;
	}
	//删除中间结点
	ListNode *pTemp = pToBeDelete->m_pNext;
	pToBeDelete->m_nValue = pTemp->m_nValue;
	pToBeDelete->m_pNext = pTemp->m_pNext;
	free(pTemp);
	pTemp = NULL;
}