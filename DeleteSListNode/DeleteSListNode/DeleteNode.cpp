#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

/*****************************************************************
��Ŀ���ƣ���O��1��ʱ��ɾ������ڵ�
��Ŀ�������������������ͷָ���һ�����ָ�룬����һ������
		 ��O��1��ʱ��ɾ���ý�㡣�������뺯���������£�
		 struct ListNode
		 {
			int m_nValue;
			ListNode *m_pNext;
		 };
		 void DeleteNode(ListNode **pHead,ListNode * pToBeDelete);
˼·��������ɾ����������ʱ��һ������Ϊ��ͷָ�뿪ʼ����������
		 ֱ���ҵ��ý�㣬�ٽ���ɾ������������������Ϊ��˳����ң�
		 ����ʱ�临�Ӷ�ΪO(n),����Ҫ��ʱ�临�Ӷ�ΪO(1)������
		 ���ǿ��Բ��ý�����������Ҫɾ���Ľ���ֵ����һ�����ֵ
		 ������Ȼ��ֱ��ɾ����һ����㣬��ʵ����ʱ�临�Ӷ�ΪO(1)
		 ��ɾ�����������
���������1.����Ϊ������
		 2.����ֻ��һ����������
		 3.��ɾ�����Ϊͷ���
		 4.��ɾ�����Ϊβ�ڵ�
ע�����1.�ж�ͷָ���Ƿ�Ϊ���Լ���ɾ������Ƿ�Ϊ��
		 2.�ͷſռ��ָ���ÿգ���ֹҰָ��ĳ���
		 3.������ǰ���Ǳ�ɾ�����һ����������
********************************************************************/
struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};
void DeleteNode(ListNode **pHead, ListNode * pToBeDelete)
{
	if ((*pHead) == NULL || pToBeDelete == NULL)//������
	{
		printf("Empty");
		return;
	}
	if (*pHead == pToBeDelete)//������ֻ��һ�����
	{
		free(pToBeDelete);
		pToBeDelete = NULL;
		*pHead = NULL;
		return;
	}
	if (pToBeDelete->m_pNext == NULL)//�����к��ж�����ɾ��β�ڵ�
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
	//ɾ���м���
	ListNode *pTemp = pToBeDelete->m_pNext;
	pToBeDelete->m_nValue = pTemp->m_nValue;
	pToBeDelete->m_pNext = pTemp->m_pNext;
	free(pTemp);
	pTemp = NULL;
}