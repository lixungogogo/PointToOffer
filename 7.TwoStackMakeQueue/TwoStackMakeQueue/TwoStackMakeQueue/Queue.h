#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node(T data = 0, Node<T>* next = NULL)
		:_data(data)
		, _next(next)
	{}
	Node(const Node&);
	Node& operator=(const Node&);

	~Node(){}
	T _data;
	Node<T>* _next;
};

template <class T>
class Queue
{
public:
	Queue(Node<T>* head = NULL, Node<T>* tail = NULL, size_t sz = 0)
		:_head(head)
		, _tail(tail)
		, _size(sz)
	{}
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	Node<T>* BuyNode(const T& data);
	void Push(const T& data);
	void Pop();
	T PopData();
	T& Front();
	T& Back();
	bool Empty() const;
	size_t Size();
	void SetEmpty();
private:
	Node<T> *_head;
	Node<T> *_tail;
	size_t _size;
};

/*******************************************
�������ƣ�Queue<T>::Queue(Queue&a)
�������ܣ����еĿ������캯��
����������const Queue& a
����ֵ  ����
ע�����Ҫ���ж���������Ƿ�ΪNULL
������ԣ�����һ��Ϊ�յĲ���
********************************************/
template <class T>
Queue<T>::Queue(const Queue&a)
{
	if (a.Empty())
	{
	}
	else
	{
		Node<T>* pTemp = a._head;
		_head = _tail = BuyNode(pTemp->_data);
		Node<T>* pNode = _head;
		while (pTemp != a._tail)
		{
			pTemp = pTemp->_next;
			Node<T>* pNewNode = BuyNode(pTemp->_data);
			pNode->_next = pNewNode;
			pNode = pNode->_next;
			_tail = pNode;
		}
		_size = a._size;
	}
}
/******************************************************
�������ƣ�Queue<T>& Queue<T>::operator=(const Queue& a)
�������ܣ����еĸ�ֵ��������غ���
����������const Queue& a
����ֵ  ��Queue<T>&
ע�����1.��ֹ�Ը�ֵ
2.����ֵΪ���ò���������ֵ
3.�����������еĳ����������
������ԣ�1.�Ը�ֵ
2.������ֵ
3.����������ȵĶ���֮�丳ֵ
4.�����и��̶��и�ֵ
5.�̶��и������и�ֵ
6.�������Ϊ��
******************************************************/
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& a)
{
	if (this != &a)
	{
		if (a.Empty())
		{
			Node<T> *temp = _head;
			while (temp != NULL)
			{
				_head = _head->_next;
				delete temp;
				temp = _head;
			}
			_head = NULL;
			_tail = NULL;
			_size = 0;
			return *this;
		}
		Node<T>* pNode1 = _head;
		Node<T>* pNode2 = a._head;
		if (_size >= a._size)
		{
			while (pNode2 != a._tail)
			{
				pNode1->_data = pNode2->_data;
				pNode1 = pNode1->_next;
				pNode2 = pNode2->_next;
			}
			if (pNode1 == _tail)
				pNode1->_data = pNode2->_data;
			else
			{
				pNode1->_data = pNode2->_data;
				_tail = pNode1;
				delete pNode1->_next;
				_tail->_next = NULL;
			}
		}
		else
		{
			while (pNode1 != _tail)
			{
				pNode1->_data = pNode2->_data;
				pNode1 = pNode1->_next;
				pNode2 = pNode2->_next;
			}
			pNode1->_data = pNode2->_data;
			while (pNode2 != a._tail)
			{
				pNode2 = pNode2->_next;
				Node<T>* pNewNode = BuyNode(pNode2->_data);
				_tail->_next = pNewNode;
				_tail = _tail->_next;
			}

		}
		_size = a._size;
	}
	return *this;
}
/*******************************************
�������ƣ�Node<T>* Queue<T>::BuyNode(const T& data)
�������ܣ����нڵ����ɺ���
����������const T& data
����ֵ  �����ɶ��нڵ�
ע�����Ҫ�ж��Ƿ�newʧ�ܣ����newʧ�ܷ��ؿ�
������ԣ���
********************************************/
template <class T>
Node<T>* Queue<T>::BuyNode(const T& data)
{
	Node<T> *pNode = new Node<T>(data);
	if (pNode == NULL)
	{
		cout << "�����ڴ�ʧ��" << endl;
		return NULL;
	}
	return pNode;
}
/*******************************************
�������ƣ�void Queue<T>::Push(const T& data)
�������ܣ����
����������const T& data
����ֵ  ����
ע�����Ҫ�ж��Ƿ�Ϊ�ն�
������ԣ����նӽ�����Ӳ���
********************************************/
template <class T>
void Queue<T>::Push(const T& data)
{
	Node<T>* temp = BuyNode(data);
	if (Empty())
	{
		_head = _tail = temp;
		_size++;
	}
	else
	{
		_tail->_next = temp;
		_tail = temp;
		_size++;
	}
}
/*******************************************
�������ƣ�void Queue<T>::Pop()
�������ܣ����Ӻ���
������������
����ֵ  ����
ע������ж��Ƿ�Ϊ�նӣ�Ϊ�նӽ��г��Ӳ���
������ԣ��Կնӽ��г��Ӳ���
********************************************/
template <class T>
void Queue<T>::Pop()
{
	if (Empty())
	{
		cout << "Queue is empty,cannot Pop" << endl;
		return;
	}
	Node<T> *temp = _head;
	_head = _head->_next;
	delete temp;
	_size--;
}
template <class T>
T Queue<T>::PopData()
{
	T data;
	if (Empty())
	{
		cout << "Queue is empty,cannot Pop" << endl;
		return -1;
	}
	Node<T> *temp = _head;
	data = temp->_data;
	_head = _head->_next;
	delete temp;
	_size--;
	return data;
}
/*******************************************
�������ƣ�T& Queue<T>::Front()
�������ܣ����ضӵ�ͷ����ֵ
������������
����ֵ  ��ͷ����ֵ
ע������ж��Ƿ�Ϊ�ն�
������ԣ��Կնӽ��в���
********************************************/
template <class T>
T& Queue<T>::Front()
{
	if (Empty())
	{
		cout << "Queue is empty" << endl;
	}
	return _head->_data;
}
/*******************************************
�������ƣ�T& Queue<T>::Back()
�������ܣ����ض�β��ֵ
������������
����ֵ  ����β�ڵ�ֵ
ע������ж��Ƿ�Ϊ�ն�
������ԣ��Կնӽ��в���
********************************************/
template <class T>
T& Queue<T>::Back()
{
	if (Empty())
		cout << "Queue is empty" << endl;
	return _tail->_data;
}
/*******************************************
�������ƣ�bool Queue<T>::Empty()const
�������ܣ��пպ���
������������
����ֵ  ����
ע���������Ϊconst������thisָ��Ϊconst
������ԣ���
********************************************/
template <class T>
bool Queue<T>::Empty()const
{
	return _size ? false : true;
}
/*******************************************
�������ƣ�size_t Queue<T>::Size()
�������ܣ����ضӵĳ���
������������
����ֵ  ���ӵĳ���
ע�������
������ԣ���
********************************************/
template <class T>
size_t Queue<T>::Size()
{
	return _size;
}
