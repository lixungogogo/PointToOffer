#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <mutex>
using namespace std;
/******************************************
��Ŀ���ƣ�ʵ��SingleTon2ģʽ
��ĿҪ�����һ���࣬����ֻ�����ɸ����һ��ʵ��
��Ŀ˼·�������������ڳ�ʼ��ʱֱ��ʵ����
		 �ڳ������ǰ���Զ�������Դ
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