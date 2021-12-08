#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

//判断当前机器的字节序
int byteSqu()
{
	int a = 1;
	char* p = (char*)&a;
	return *p;//大端返回0，小端返回1
}