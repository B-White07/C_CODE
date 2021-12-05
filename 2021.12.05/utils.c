#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

int* test()
{
	int a = 10;
	return &a;
}

int myStrlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int myStrlen2(char* str)
{
	int* start = str;
	while (*str != '\0')
	{
		str++;
	}
	return str - start;
}

void print1(struct Stu stu)
{
	printf("%c %d %lf %s %d %s\n", stu.b.c, stu.b.s, stu.b.d, stu.name, stu.age, stu.id);
}

void print2(struct Stu* pstu)
{
	printf("%c %d %lf %s %d %s\n", pstu->b.c, pstu->b.s, pstu->b.d, pstu->name, pstu->age, pstu->id);
}

int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

//模拟实现strcpy() '\0'也需要拷贝
void myStrcpy(char* dest, char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = *src;
}