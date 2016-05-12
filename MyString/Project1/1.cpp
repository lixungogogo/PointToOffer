#include <iostream>
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
CMyString& CMyString::operator=(const CMyString& a)	//����ҪΪconst���ͷ�ֹ�ں����жԲ��������޸�
{	
	if (this != &a)	//��ֹ�Ը�ֵ
	{
		if (m_pData != NULL)
		{
			delete[] m_pData;	//��ֹ�ڴ�й¶
		}
		m_pData = new char[strlen(a.m_pData)+1];	
		//����ռ��СҪ��һ��Ϊ�˷���'\0'
		//����������m_pData new��ʱ���������m_pDataΪNULL�����
		//��ô����m_pData��ֵҲû���ˣ��µĿռ�Ҳû�з���ɹ���������쳣
		strcpy(m_pData, a.m_pData);
	}
	return *this;	//����thisָ���ֵ��������������ֵ
}
