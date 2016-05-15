#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
using namespace std;
/******************************************
题目名称：实现SingleTon2模式
题目要求：设计一个类，我们只能生成该类的一个实例
题目思路：饿汉方法，在初始化时直接实例化
		 在程序结束前，自动回收资源
*******************************************/

class SingleTon2
{
public:
	static SingleTon2 * Get()
	{
		return pData;
	}
private:
	SingleTon2()
	{}
	SingleTon2(const SingleTon2&);
	SingleTon2& operator=(const SingleTon2&);
	~SingleTon2()
	{}
	static SingleTon2* pData;
};
SingleTon2* SingleTon2::pData = new SingleTon2();


int main()
{
	SingleTon2 *a = a->Get();
	SingleTon2 *b = b->Get();
	return 0;
}