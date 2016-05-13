#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>
using namespace std;
/******************************************
题目名称：实现SingleTon1模式
题目要求：设计一个类，我们只能生成该类的一个实例
题目考点:
		1.构造函数，拷贝构造函数，赋值运算符重载函数私有化
		2.线程安全
		3.双重锁定
*******************************************/

class SingleTon1
{
public:
	static SingleTon1* Create()
	{
		if (pData == NULL)	//先判断实例化再加锁，提高效率
		{
			Mutex.lock();	//线程安全
			if (pData == NULL)	//双重校验锁，防止多次实例化，double_check可以让lock的调用开销降低到最小
				pData = new SingleTon1;
			Mutex.unlock();
		}
		return pData;
	}
	static void Release()
	{
		if (pData != NULL)
		{
			delete pData;
			pData = NULL;
		}
	}
private:
	SingleTon1()
	{}
	SingleTon1(const SingleTon1&);
	SingleTon1& operator=(const SingleTon1&);
	~SingleTon1()
	{}
	static SingleTon1* pData;
	static mutex Mutex;
};
SingleTon1* SingleTon1::pData = NULL;
mutex SingleTon1::Mutex;

int main()
{
	SingleTon1* a = a->Create();
	SingleTon1* b = b->Create();
	return 0;
}