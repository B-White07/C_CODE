#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
void print(int* p, int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", *(p + i));
}
void test(char* p) {}

void test2(int** p2)
{
	**p2 = 20;
}

int Add(int x, int y)
{
	return x + y;
}
void test3(char* str){}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("********************\n");
	printf("**1.Add      2.Sub**\n");
	printf("**3.Mul      4.Div**\n");
	printf("**     0.exit     **\n");
}

int Cacl(int (*pfun)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数：\n");
	scanf("%d %d", &x, &y);
	return pfun(x, y);
}