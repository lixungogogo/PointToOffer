#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;
/*******************************************
��ĿҪ�󣺷�ת����
��Ŀ����������һ������������һ�������ͷ��㣬��ת���������
		 ��ת�������ͷ��㡣
˼·������1.ʹ������ָ����з���ת
		 2.ʹ�õݹ�
		 3.ʹ��ͷ�巨�ٹ���һ������
ע�����1.��������ͷָ��ΪNULL����ֻ��һ�����ʱ���������
		 2.��ת������ֶ���
		 3.���ص�ͷ��㲻�Ƿ�תǰ�����β�ڵ�
���ܲ��ԣ�1.����ֻ����һ����������
		 2.���뺬�ж����������
������ԣ���������ͷ���ΪNULLָ��
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
����һ��ʹ������ָ��
˼·������ʹ������ָ��ֱ�ΪpPre,pCur,pNextָ��ǰ��㣬��ǰ����
		ǰһ������Լ���ǰ������һ����㣬��������ת��
����������������С����ռ�ö���ռ䣬��Ҫע�ⷴתʱ������ѵ����⡣
		 ���ƺñ߽���������Ȼ���׵���Խ�����
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
����2���ݹ�ʵ��
**********************************************/
pListNode Reverse(pListNode *pHead)
{
	assert(pHead);
	pListNode p = (*pHead)->m_next;
	pListNode q = NULL;
	if (p->m_next != NULL)
	{
		q = Reverse(&(*pHead)->m_next);//��β�ڵ㼴��ת���ͷ��㷵��
	}
	else
	{
		p->m_next = (*pHead);//������β�ڵ��������ٷ���β�ڵ�
		return p;
	}
	p->m_next = (*pHead);//����
	return q;
}
pListNode ReverseList2(pListNode *pHead)
{
	pListNode p = Reverse(pHead);
	(*pHead)->m_next = NULL;//���ú�β�ڵ�next�ÿ�
	(*pHead) = p;//����ͷβָ��
	return *pHead;
}

/***************************************************
����3��ʹ��ͷ�巨����������
˼·����ͷ�幹��һ���������ٽ�ԭ���������ͷŵ�
�����������򵥣����������󣬿ռ�ʹ����������������
	 ���������ͷſռ�����ڴ�й¶
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