#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//void _out(void *expression, void* file_name, int line_num);
#define _assert(_exp) (void)((_exp) || (_out(#_exp,__FILE__,__LINE__)))

//void是给_assert()宏一个返回值
//#是把表达式转换为字符串
//！！取两次反是为了保护返回值非1即0

int _out(void *expression, void* file_name, int line_num)
{
	printf("Error:%s,file:%s,linr:%d\n", expression, file_name, line_num);
	abort();

	return 0;
}

int main()
{
	int i = 0;
	_assert(i>0);
	return 0;
}
