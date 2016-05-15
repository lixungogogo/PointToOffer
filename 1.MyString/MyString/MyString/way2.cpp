
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string.h>
using namespace std;
/***********************************************************
��Ŀ����������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ���������
��Ŀ���룺
			class CMyString
			{
			public:
				CMyString(char * pData = NULL);
				CMyString(const CMyString& str);
				~CMyString(void);
			private:
				char * m_pData;
			};
���⿼�㣺1.�����C++�����﷨���˽⣬����������ص�
		   2.������ڴ�й¶�����
		   3.�����Ƿ��жԴ����쳣��ȫ�Ե��˽�
����ע�⣺1.��ֵ��������غ����ķ���ֵ������
		   2.�����������������
		   3.�Ƿ����Ը�ֵ
		   4.�Ƿ����ڴ�й¶
	   	   5.�Ƿ��ǵ������쳣
*************************************************************/
class CMyString
{
public:
	CMyString(char* pData = NULL)
	{
		if (pData != NULL)
		{
			m_pData = new char[strlen(pData) + 1];
			// ��strlen�Ĳ���ΪNULLʱ�����������Ҫ�ж�
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
		//Ϊ�˷�ֹnewʧ�ܺ�����쳣
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
