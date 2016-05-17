#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <mutex>
using namespace std;
/******************************************
��Ŀ���ƣ�ʵ��SingleTon1ģʽ
��ĿҪ�����һ���࣬����ֻ�����ɸ����һ��ʵ��
��Ŀ����:
		1.���캯�����������캯������ֵ��������غ���˽�л�
		2.�̰߳�ȫ
		3.˫������
*******************************************/

class SingleTon1
{
public:
	static SingleTon1* Create()
	{
		if (pData == NULL)	//���ж�ʵ�����ټ��������Ч��
		{
			Mutex.lock();	//�̰߳�ȫ
			if (pData == NULL)	//˫��У��������ֹ���ʵ������double_check������lock�ĵ��ÿ������͵���С
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