#pragma once
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<errno.h>

int	yangFind(int arr[3][3], int row, int col, int find);
int	yangFind2(int arr[3][3], int* row, int* col, int find);

void strRotate(char* pa, int n);
void strRotate2(char* pa, int n);

char* myStrcat(char* dest, const char* src);

int myStrcmp(const char* str1, const char* str2);

char* myStrstr(const char* str1, const char* str2);