#pragma once
#include<stdio.h>
struct B
{
	char c;
	short s;
	double d;
};
struct Stu
{
	struct B b;//成员可以是另外一个结构体变量
	char name[20];
	int age;
	char id[20];
}s1, s2;//s1和s2也是结构体变量，是全局变量

int* test();
int myStrlen(char* str);
void print1(struct Stu stu);
void print2(struct Stu* pstu);
int Add(int x, int y);
void myStrcpy(char* dest, char* src);