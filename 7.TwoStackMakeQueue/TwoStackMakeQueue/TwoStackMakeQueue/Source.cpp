#define _CRT_SECURE_NO_WARNINGS 1
#define Left 0
#define Right 1
#include <iostream>
using namespace std;
#include "DStack.h"
#include "Queue.h"
/***************************************************
功能描述：两个栈实现一个队列
思路描述：两个栈中其中S2用来作为缓冲栈
算法优化：在S2不为空的情况下，先不将S2的元素给S1返回，
		 而是根据下一步是出队还是入队进行选择，如果下
		 一步是入队操作，则将S2的元素给S1Push，如果下
		 一步是出队操作，则直接将S2进行出栈操作
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