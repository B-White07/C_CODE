#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ṹ��Test�Ĵ�С��20���ֽ�
struct Test
{
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p;//pΪ�ṹ��ָ�룬ָ��Test
//����p��ֵΪ0x100000

struct Stu
{
	char name[20];
	int age;
};
void print(int* p, int sz);
void test(char* p);

void test2(int** p2);
int Add(int x, int y);
void test3(char* str);
int Sub(int x, int y);
int Mul(int x, int y);
int Div(int x, int y);
void menu();
int Cacl(int (*pfun)(int, int));

void bubble_sort(int arr[], int sz);

int cmp_int(void* e1, void* e2);
void test_int();

int sortByAge(void* e1, void* e2);
void test_struct();

void swap(char* start, char* end, int width);
void bubble_sort2(void* base, int size, int width, int(*compare)(const void* element1, const void* element2));
void test_int2();
void test_struct2();
