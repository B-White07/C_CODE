#pragma once
#include<stdio.h>
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