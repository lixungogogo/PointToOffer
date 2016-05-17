#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

typedef struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
}ListNode, *pListNode;

void Init(pListNode *pHead)
{
	*pHead = NULL;
}
void Destory(pListNode *pHead)
{
	pListNode ptemp = *pHead;
	while (*pHead)
	{
		ptemp = *pHead;
		*pHead = (*pHead)->m_pNext;
		free(ptemp);
		ptemp = NULL;
	}
}

pListNode BuyNode(int data)
{
	pListNode pNode = (pListNode)malloc(sizeof(ListNode));
	if (pNode == NULL)
		assert(pNode);
	pNode->m_nKey = data;
	pNode->m_pNext = NULL;
	return pNode;
}
void PushBack(pListNode* pHead, int data)
{
	if (*pHead == NULL)
	{
		*pHead = BuyNode(data);
		return;
	}
	pListNode pNode = BuyNode(data);
	pListNode pTemp = *pHead;
	while (pTemp->m_pNext)
	{
		pTemp = pTemp->m_pNext;
	}
	pTemp->m_pNext = pNode;
}

void PopBack(pListNode *pHead)
{
	pListNode pTemp = *pHead;
	if (*pHead == NULL)
		return;
	while (pTemp->m_pNext != NULL)
	{
		pTemp = pTemp->m_pNext;
	}
	free(pTemp);
	pTemp = NULL;
}

void PushFront(pListNode *pHead, int data)
{
	assert(pHead);
	if (*pHead == NULL)
	{
		*pHead = BuyNode(data);
		return;
	}
	pListNode pNode = BuyNode(data);
	pNode->m_pNext = *pHead;
	*pHead = pNode;
}
void PopFont(pListNode *pHead)
{
	assert(pHead);
	if (*pHead == NULL)
		return;
	pListNode pTemp = *pHead;
	*pHead = (*pHead)->m_pNext;
	free(pTemp);
}
