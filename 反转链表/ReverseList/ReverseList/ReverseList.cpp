#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/*******************************************
题目要求：反转链表
题目描述：定义一个函数，输入一个链表的头结点，反转该链表并输出
		 反转后链表的头结点。
思路分析：1.使用三个指针进行方向反转
		 2.使用递归
		 3.使用头插法再构造一个链表
注意事项：1.输入链表头指针为NULL或者只有一个结点时，程序崩溃
		 2.反转链表出现断裂
		 3.返回的头结点不是反转前链表的尾节点
功能测试：1.输入只含有一个结点的链表
		 2.输入含有多个结点的链表
特殊测试：输入链表头结点为NULL指针
************************************************/
typedef struct Node
{
	int m_value;
	struct Node* m_next;
}ListNode,*pListNode;

pListNode BuyNode(int data)
{
	pListNode pNode = (pListNode)malloc(sizeof(ListNode));
	assert(pNode);
	pNode->m_value = data;
	pNode->m_next = NULL;
	return pNode;
}
void PushBack(pListNode *pHead, int data)
{
	assert(pHead);
	if ((*pHead) == NULL)
	{
		(*pHead) = BuyNode(data);
	}
	else
	{
		pListNode pNode = BuyNode(data);
		pListNode pTemp = (*pHead);
		while (pTemp->m_next != NULL)
		{
			pTemp = pTemp->m_next;
		}
		pTemp->m_next = pNode;
	}
}
/*************************************************************
方法一：使用三个指针
思路分析：使用三个指针分别为pPre,pCur,pNext指向当前结点，当前结点的
		前一个结点以及当前结点的下一个结点，将链表方向反转。
方法分析：代码量小，不占用多余空间，但要注意反转时链表断裂的问题。
		 控制好边界条件，不然容易导致越界访问
**************************************************************/
pListNode ReverseList1(pListNode *pHead)
{
	assert(pHead);
	if ((*pHead) == NULL || (*pHead)->m_next == NULL)
	{
		return *pHead;
	}
	pListNode pPre, pCur, pNext;
	pPre = *pHead;
	pCur = pPre->m_next;
	pNext = pCur->m_next;
	while (pNext)
	{
		pCur->m_next = pPre;
		if (pPre == *pHead)
			pPre->m_next = NULL;
		pPre = pCur;
		pCur = pNext;
		pNext = pNext->m_next;
	}
	pCur->m_next = pPre;
	return pCur;
}
/***********************************************
方法2：递归实现
**********************************************/
pListNode Reverse(pListNode *pHead)
{
	assert(pHead);
	pListNode p = (*pHead)->m_next;
	pListNode q = NULL;
	if (p->m_next != NULL)
	{
		q = Reverse(&(*pHead)->m_next);//将尾节点即反转后的头结点返回
	}
	else
	{
		p->m_next = (*pHead);//遍历到尾节点先逆置再返回尾节点
		return p;
	}
	p->m_next = (*pHead);//逆置
	return q;
}
pListNode ReverseList2(pListNode *pHead)
{
	pListNode p = Reverse(pHead);
	(*pHead)->m_next = NULL;//逆置后尾节点next置空
	(*pHead) = p;//交换头尾指针
	return *pHead;
}

/***************************************************
方法3：使用头插法构造新链表
思路：先头插构造一个新链表，再将原来的链表释放掉
分析：方法简单，但代码量大，空间使用量比其他方法大，
	 容易忘记释放空间造成内存泄露
******************************************************/
void PushFront(pListNode *pHead, int data)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		(*pHead) = BuyNode(data);
	}
	else
	{
		pListNode pNode = BuyNode(data);
		pNode->m_next = (*pHead);
		(*pHead) = pNode;
	}
}

pListNode ReverseList3(pListNode* pHead)
{
	assert(pHead);
	pListNode pTemp = *pHead;
	pListNode pNode = NULL;
	while (pTemp)
	{
		PushFront(&pNode, pTemp->m_value);
		pTemp = pTemp->m_next;
	}
	pTemp = *pHead;
	*pHead = pNode;
	pListNode p = pTemp;
	while (p)
	{
		p = p->m_next;
		delete pTemp;
		pTemp = p;
	}
	return *pHead;
}

void Test()
{
	pListNode pHead = NULL;
	PushBack(&pHead, 1);
	PushBack(&pHead, 2);
	PushBack(&pHead, 3);
	PushBack(&pHead, 4);
	PushBack(&pHead, 5);
	PushBack(&pHead, 6);
	ReverseList1(&pHead);
	ReverseList2(&pHead);
	ReverseList3(&pHead);
}

int main()
{
	Test();
	return 0;
}