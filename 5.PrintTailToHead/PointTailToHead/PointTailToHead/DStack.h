#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<class T, int N = 10>
class DStack
{
public:
	DStack(size_t capacity = N)
		:_capacity(capacity)
	{
		_data = new T[N];
		_size = 0;
	}
	~DStack()
	{
		delete[] _data;
	}
	DStack(const DStack&);
	DStack& operator=(const DStack& a);
	void Push(const T&);
	void Pop();
	T PopData();
	T& Top();
	bool Empty();
	size_t Size();
	bool CheckCapacity();
	bool IsLow(T in[], T out[],int size);
protected:
	T* _data;
	size_t _size;
	size_t _capacity;
};
/******************************
�������ƣ�DStack(const DStack&)
�������ܣ���̬ջ�Ŀ������캯��
����������DStack<int> b(a);
ע���������������Nֵ������ͬ
������ԣ�DStack<int,10> a;
DStack<int,20> b(a);
���������
*******************************/
template<class T, int N = 10>
DStack<T, N>::DStack(const DStack& a)
{
	_data = new T[a._capacity];
	memcpy(_data, a._data, sizeof(T)*a._capacity);
	_size = a._size;
	_capacity = a._capacity;
}
/***************************************
�������ƣ�DStack& operator=(const DStack&)
�������ܣ���̬ջ�ĸ�ֵ��������غ���
����������DStack<int> a;
DStack<int> b;
b = a;
ע���������������Nֵ������ͬ
������ԣ�1.�Ը�ֵ
2.Nֵ����ͬ��ֵ
3.������ֵ a = b = c
**************************************/
template<class T, int N = 10>
DStack<T, N>& DStack<T, N>::operator=(const DStack& a)
{
	if (this != &a)
	{
		DStack<T, N> temp(a);
		T* pTemp = temp._data;
		temp._data = _data;
		_data = pTemp;
		_size = a._size;
		_capacity = a._capacity;
	}
	return *this;
}
/******************************
�������ƣ�bool CheckCapacity()
�������ܣ�����Ƿ���Ҫ����
������������
����ֵ  ���Ƿ����ݳɹ�
ע�����Ҫ����Ƿ�����ʧ��
������ԣ���
*******************************/
template<class T, int N = 10>
bool DStack<T, N>::CheckCapacity()
{
	if (_size >= _capacity)
	{
		T *temp = (T*)realloc(_data, sizeof(T)* _capacity * 2);
		if (temp == NULL)
		{
			cout << "����ʧ��" << endl;
			return false;
		}
		_data = temp;
		_capacity *= 2;
	}
	return true;
}
/*******************************************
�������ƣ�void DStack<T,N>::Push(const T& a)
�������ܣ���ջ�ڼ���Ԫ��
����������������Ԫ��ֵ
����ֵ  ����
ע�����Ҫ����Ƿ�����
������ԣ���
********************************************/
template<class T, int N = 10>
void DStack<T, N>::Push(const T& a)
{
	if (CheckCapacity())
		_data[_size++] = a;
}
/*******************************************
�������ƣ�void DStack<T,N>::Pop()
�������ܣ�Ԫ�س�ջ
������������
����ֵ  ����
ע��������ջ�Ƿ�Ϊ�գ�Ϊ�ղ���ջ
������ԣ���ջ��ջ
********************************************/
template<class T, int N = 10>
void DStack<T, N>::Pop()
{
	if (!Empty())
		_size--;
}
template<class T, int N = 10>
T DStack<T, N>::PopData()
{
	if (!Empty())
	{
		_size--;
		return  _data[_size];
	}
	return -1;
}
/*******************************************
�������ƣ�T& DStack<T,N>::Top()
�������ܣ�ȡջ��Ԫ��
������������
����ֵ  ������ջ��Ԫ�ص�����
ע�����1.����ֵΪ���û����Զ�ջ��Ԫ�ؽ����޸�
2.����Ƿ��ջȡջ��Ԫ��
������ԣ���ջȡջ��Ԫ��
********************************************/
template<class T, int N = 10>
T& DStack<T, N>::Top()
{
	if (!Empty())
		return _data[_size - 1];
	cout << "Empty DStack!" << endl;
	return _data[0];
}
/*******************************************
�������ƣ�bool DStack<T,N>::Empty()
�������ܣ����ջ�Ƿ�Ϊ��
������������
����ֵ  ���Ƿ�Ϊ��
ע�������
������ԣ���
********************************************/
template<class T, int N = 10>
bool DStack<T, N>::Empty()
{
	return _size ? false : true;
}
/*******************************************
�������ƣ�size_t DStack<T,N>::Size()
�������ܣ�����ջ�ĳ���
������������
����ֵ  ��ջ�ĳ���
ע�������
������ԣ���
********************************************/
template<class T, int N = 10>
size_t DStack<T, N>::Size()
{
	return _size;
}
