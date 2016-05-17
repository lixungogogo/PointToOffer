
/*********************************************************
题目名称：输入一个链表的头结点，从尾到头反过来打印出每个节点的值
题目说明：链表节点定义如下：
		 struct ListNode
		 {
			int m_nKey;
			ListNode* m_pNext;
		 }
解法说明：这个问题有三种方法：
		 1.创建一个栈，将为头到尾的节点值放在栈中，再出栈打印
		 2.创建一个新链表，采用头插法将原链表节点插入，在正向打印
		 3.递归实现
解法分析：方法1，2——代码较为繁琐
		 方法3——在链表十分长的情况下可能会造成函数调用栈溢出
功能测试：1.有多个结点的链表
		 2.只有一个结点的链表
特殊测试：输入NULL链表
***********************************************************/
#define _CRT_SECURE_NO_WARNINGS 1
#include "Node.h"
#include "DStack.h"
#include <iostream>
using namespace std;
//方法一：借助栈

void PrintTailToHead1(pListNode pHead)
{
	DStack<int> s;
	pListNode pTemp = pHead;
	while (pTemp)
	{
		s.Push(pTemp->m_nKey);
		pTemp = pTemp->m_pNext;
	}
	while (!s.Empty())
	{
		cout << s.PopData() << endl;
	}
}

int Test1()
{
	pListNode Node;
	Init(&Node);
	PushBack(&Node, 1);
	PushBack(&Node, 2);
	PushBack(&Node, 3);
	PushBack(&Node, 4);
	PushBack(&Node, 5);
	PushBack(&Node, 6);
	PrintTailToHead1(Node);
	return 0;
}
//方法二：头插法

void PrintTailToHead2(pListNode pHead)
{
	pListNode pNode, pTemp = pHead;
	Init(&pNode);
	while (pTemp)
	{
		PushFront(&pNode, pTemp->m_nKey);
		pTemp = pTemp->m_pNext;
	}
	pTemp = pNode;
	while (pNode)
	{
		cout << pNode->m_nKey << endl;
		pNode = pNode->m_pNext;
	}
	Destory(&pTemp);
}

int Test2()
{
	pListNode Node;
	Init(&Node);
	PushBack(&Node, 1);
	PushBack(&Node, 2);
	PushBack(&Node, 3);
	PushBack(&Node, 4);
	PushBack(&Node, 5);
	PushBack(&Node, 6);
	PrintTailToHead2(Node);
	return 0;
}

//方法三：递归

void PrintTailToHead3(pListNode pHead)
{
	//pListNode P = pHead;
	if (pHead->m_pNext != NULL)
		PrintTailToHead3(pHead->m_pNext);
	printf("%d", pHead->m_nKey);
}

int Test3()
{
	pListNode Node;
	Init(&Node);
	PushBack(&Node, 1);
	PushBack(&Node, 2);
	PushBack(&Node, 3);
	PushBack(&Node, 4);
	PushBack(&Node, 5);
	PushBack(&Node, 6);
	PrintTailToHead3(Node);
	return 0;
}

