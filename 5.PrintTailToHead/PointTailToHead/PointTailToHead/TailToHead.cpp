
/*********************************************************
��Ŀ���ƣ�����һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ
��Ŀ˵��������ڵ㶨�����£�
		 struct ListNode
		 {
			int m_nKey;
			ListNode* m_pNext;
		 }
�ⷨ˵����������������ַ�����
		 1.����һ��ջ����Ϊͷ��β�Ľڵ�ֵ����ջ�У��ٳ�ջ��ӡ
		 2.����һ������������ͷ�巨��ԭ����ڵ���룬�������ӡ
		 3.�ݹ�ʵ��
�ⷨ����������1��2���������Ϊ����
		 ����3����������ʮ�ֳ�������¿��ܻ���ɺ�������ջ���
���ܲ��ԣ�1.�ж����������
		 2.ֻ��һ����������
������ԣ�����NULL����
***********************************************************/
#define _CRT_SECURE_NO_WARNINGS 1
#include "Node.h"
#include "DStack.h"
#include <iostream>
using namespace std;
//����һ������ջ

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
//��������ͷ�巨

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

//���������ݹ�

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

