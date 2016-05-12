
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
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
	{
		if (pData != NULL)
		{
			m_pData = new char[strlen(pData) + 1];
			// 当strlen的参数为NULL时，会出错，所以要判断
			strcpy(m_pData, pData);
		}
		else
		{
			m_pData = new char[1];
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
CMyString& CMyString::operator=(const CMyString& a)
{
	if (this != &a)
	{
		//为了防止new失败后产生异常
		CMyString temp(a);
		char *strtemp = temp.m_pData;
		temp.m_pData = m_pData;
		m_pData = strtemp;
	}
	return *this;
}
int main()
{
	CMyString a("1111");
	CMyString b;
	b = a = a;
	int i = 1;
	return 0;
}
