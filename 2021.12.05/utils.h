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
	struct B b;//��Ա����������һ���ṹ�����
	char name[20];
	int age;
	char id[20];
}s1, s2;//s1��s2Ҳ�ǽṹ���������ȫ�ֱ���

int* test();
int myStrlen(char* str);
void print1(struct Stu stu);
void print2(struct Stu* pstu);
int Add(int x, int y);
void myStrcpy(char* dest, char* src);