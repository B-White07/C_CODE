#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

//�жϵ�ǰ�������ֽ���
int byteSqu()
{
	int a = 1;
	char* p = (char*)&a;
	return *p;//��˷���0��С�˷���1
}