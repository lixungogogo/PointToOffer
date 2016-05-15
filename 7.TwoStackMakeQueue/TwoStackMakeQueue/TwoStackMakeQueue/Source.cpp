#define _CRT_SECURE_NO_WARNINGS 1
#define Left 0
#define Right 1
#include <iostream>
using namespace std;
#include "DStack.h"
#include "Queue.h"
/***************************************************
��������������ջʵ��һ������
˼·����������ջ������S2������Ϊ����ջ
�㷨�Ż�����S2��Ϊ�յ�����£��Ȳ���S2��Ԫ�ظ�S1���أ�
		 ���Ǹ�����һ���ǳ��ӻ�����ӽ���ѡ�������
		 һ������Ӳ�������S2��Ԫ�ظ�S1Push�������
		 һ���ǳ��Ӳ�������ֱ�ӽ�S2���г�ջ����
******************************************************/
template<class T, int N = 10>
class MyQueue :public DStack<T, N>
{
public:
	MyQueue()
	{}
	MyQueue(DStack<T, N> s1, DStack<T, N> s2)
		:S1(s1)
		, S2(s2)
	{}
	void Push(const T& data);
	T Pop();
	void Print()const;
private:
	DStack<T, N> S1;
	DStack<T, N> S2;
};
template<class T, int N = 10>
void MyQueue<T,N>::Print()const
{
	if (S1.Empty() && S2.Empty())
		return;
	if (S1.Empty())
		S2.Print();
	else
		S1.Print();
}
template<class T, int N = 10>
void MyQueue<T, N>::Push(const T& data)
{
	if (S2.Empty())
	{
		S1.Push(data);
		return;
	}
	if (!S2.Empty())
	{
		while (!S2.Empty())
		{
			S1.Push(S2.PopData());
		}
		S1.Push(data);
		return;
	}
}
template<class T, int N = 10>
T MyQueue<T, N>::Pop()
{
	while (!S1.Empty())
	{
		S2.Push(S1.PopData());
	}
	return S2.PopData();
}

int Test()
{
	MyQueue<int> a;
	a.Push(1);
	a.Push(2);
	a.Push(3);
	a.Push(4);
	a.Print();
	a.Pop();
	a.Push(5);
	a.Push(6);
	a.Print();

	return 0;
}