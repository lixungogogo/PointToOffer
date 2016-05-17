#define _CRT_SECURE_NO_WARNINGS 1
#define barrier() __asm__ volatile ("lwsync")
#define __X86__

//
//#ifdef __POWERPC__
//#define barrier()   __asm__ __volatile__ ("eieio") /* ƽ̨��� */
////#define barrier()   __asm__ __volatile__ ("lwsync") /* ƽ̨��� */
//#endif
//#if defined(__X86__) || defined(__X86_64__)
//#define barrier()   __asm__ __volatile__ ("mfence") /* ƽ̨��� */
//#endif
//

#include <iostream>
#include <mutex>
using namespace std;
/******************************************
��Ŀ���ƣ�ʵ��SingleTonģʽ
��ĿҪ�����һ���࣬����ֻ�����ɸ����һ��ʵ��
��Ŀ˼·��1.����Ƕ���������Դ����
		 2.��˫��У������֤�̰߳�ȫ
		 3.��ֹ�����������Ż�����CPU����ִ��
*******************************************/
class Single
{
public:
	static Single* SingleCreatePtr()
	{
		if (m == NULL)	//���ж�ʵ�����ټ��������Ч��
		{
			Mutex.lock();	//�̰߳�ȫ
			if (m == NULL)	//˫��У��������ֹ���ʵ������double_check������lock�ĵ��ÿ������͵���С
			{
				Single *temp = new Single;
				barrier();//��ֹCPU����
				m = temp;
			}
			Mutex.unlock();
		}
		return m;
	}
	class DeleteSingle
	{
	public:
		~DeleteSingle()
		{
			if (Single::m != NULL)
			{
				delete m;
			}
		}
	};

	static DeleteSingle f;
private:
	Single()
	{}
	Single(const Single &a);
	Single& operator = (const Single &a);
	static	Single *m;
	static mutex Mutex;
};
mutex Single::Mutex;
Single* Single::m = NULL;
Single::DeleteSingle Single::f;