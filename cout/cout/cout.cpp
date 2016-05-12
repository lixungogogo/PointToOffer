#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
using namespace std;

class _cout
{
public:
	_cout& operator <<(int value)
	{
		printf("%d", value);
		return *this;
	}
	_cout& operator <<(char value)
	{
		printf("%c", value);
		return *this;
	}
};

int main()
{
	_cout mycout;
	int i = 12;
	char c = 'a';
	mycout << i<< c;
	//cout.operator<<(i) << (i);
	//cout.operator<< (c) << endl;
	//cin.operator>>(i);
}
