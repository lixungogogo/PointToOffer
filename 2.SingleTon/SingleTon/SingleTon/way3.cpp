#define _CRT_SECURE_NO_WARNINGS 1
#define barrier() __asm__ volatile ("lwsync")
#define __X86__

//
//#ifdef __POWERPC__
//#define barrier()   __asm__ __volatile__ ("eieio") /* 平台相关 */
////#define barrier()   __asm__ __volatile__ ("lwsync") /* 平台相关 */
//#endif
//#if defined(__X86__) || defined(__X86_64__)
//#define barrier()   __asm__ __volatile__ ("mfence") /* 平台相关 */
//#endif
//

#include <iostream>
#include <mutex>
using namespace std;
/******************************************
题目名称：实现SingleTon模式
题目要求：设计一个类，我们只能生成该类的一个实例
题目思路：1.利用嵌套类进行资源回收
		 2.加双重校验锁保证线程安全
		 3.防止编译器过度优化导致CPU乱序执行
*******************************************/
class Single
{
public:
	static Single* SingleCreatePtr()
	{
		if (m == NULL)	//先判断实例化再加锁，提高效率
		{
			Mutex.lock();	//线程安全
			if (m == NULL)	//双重校验锁，防止多次实例化，double_check可以让lock的调用开销降低到最小
			{
				Single *temp = new Single;
				barrier();//防止CPU乱序
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