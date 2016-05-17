#include <iostream>
using namespace std;
/***********************************************************
题目描述：如下为类型CMyString的声明，请为该类型添加赋值运算符函数
题目代码：
class CMyString
{
public:
CMyString(char * pData = NULL);
CMyString(const CMyString& str);
~CMyString(void);
private:
char * m_pData;
};
本题考点：1.考查对C++基础语法的了解，如运算符重载等
		 2.考查对内存泄露的理解
		 3.考查是否有对代码异常安全性的了解
本题注意：1.赋值运算符重载函数的返回值的类型
		 2.函数传入参数的类型
		 3.是否检查自赋值
		 4.是否检查内存泄露
		 5.是否考虑到代码异常
*************************************************************/
class CMyString
{
public:
	CMyString(char* pData = NULL)
		:m_pData(new char[strlen(pData) + 1])
	{
		if (pData != NULL)
		{
			strcpy(m_pData, pData);
		}
		else
		{
			*m_pData = '\0';
		}
	}
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator=(const CMyString& a);
private:
	char * m_pData;
};

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString()
{
	if (m_pData != NULL)
	{
		delete[] m_pData;
		m_pData = NULL;
	}
}
CMyString& CMyString::operator=(const CMyString& a)	//参数要为const类型防止在函数中对参数进行修改
{	
	if (this != &a)	//防止自赋值
	{
		if (m_pData != NULL)
		{
			delete[] m_pData;	//防止内存泄露
		}
		m_pData = new char[strlen(a.m_pData)+1];	
		//分配空间大小要加一，为了放置'\0'
		//在这里会出现m_pData new的时候出错，导致m_pData为NULL的情况
		//那么本身m_pData的值也没有了，新的空间也没有分配成功，造成了异常
		strcpy(m_pData, a.m_pData);
	}
	return *this;	//返回this指针的值可以做到连续赋值
}
