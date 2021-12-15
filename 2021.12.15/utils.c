#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的（不要求等差递增）
//编写程序在这样的矩阵中查找某个数字是否存在，要求时间复杂的小于O(N)
//1 2 3 
//2 3 4
//4 5 6
//int	yangFind(int arr[3][3], int row, int col, int find)
//{
//	int x = 0;
//	int y = col - 1;
//	while (x < row && y >= 0)
//	{
//		if (arr[x][y] > find)
//			y--;
//		else if(arr[x][y] < find)
//			x++;
//		else
//		{
//			//printf("找到了，位置是：%d %d", x, y);
//			return 1;//找到返回1
//		}		
//	}
//	return 0;//找不到返回0
//}
//改进
int	yangFind2(int arr[3][3], int* px, int* py, int find)
{
	int x = 0;
	int y = *py - 1;
	while (x < *px && y >= 0)
	{
		if (arr[x][y] > find)
			y--;
		else if (arr[x][y] < find)
			x++;
		else
		{
			*px = x;//通过指针将位置信息带回去
			*py = y;
			return 1;//找到返回1
		}
	}
	return 0;//找不到返回0
}

//左旋字符串
//实现一个函数，可以左旋字符串中的k个字符
//eg：ABCD左旋一个字符得到BCDA，左旋两个字符得到CDAB
//方法1
void strRotate(char* pa, int n)
{
	int len = strlen(pa);
	//需要旋转几次
	for (int i = 0; i < n; i++)
	{
		//每次旋转1个字节
		char tmp = *pa;
		for (int j = 0; j < len - 1; j++)
		{
			*(pa + j) = *(pa + j + 1);
		}
		*(pa + len - 1) = tmp;
	}
}
//方法2：三步逆序法：左边逆序；右边逆序；整体逆序
void reverse(char* left, char* right)
{
	assert(left);
	assert(right);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void strRotate2(char* pa, int n)
{
	int len = strlen(pa);
	assert(pa);
	reverse(pa, pa + n - 1);
	reverse(pa + n, pa + len - 1);
	reverse(pa, pa + len - 1);
}

//判断一个字符串是否为另一个字符串旋转之后的字符串
//eg：AABCD和BCDAA返回1		abcd和ACBD返回0
int isStrRotate(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	//需要旋转几次
	for (int i = 0; i < len; i++)
	{
		//每次旋转1个字节
		char tmp = *arr1;
		for (int j = 0; j < len - 1; j++)
		{
			*(arr1 + j) = *(arr1 + j + 1);
		}
		*(arr1 + len - 1) = tmp;

		if (0 == strcmp(arr1, arr2))
			return 1;
	}
	return 0;
}
int isStrRotate2(char* arr1, char* arr2)
{
	//先考虑长度不一样的情况，长度不相等一定不是旋转得到的
	if (strlen(arr1) != strlen(arr2))
		return 0;
	int len = strlen(arr1);
	//1.给arr1追加一个arr1
	//AABCDAABCD包含了AABCD所有旋转的情况
	//strcat(arr1, arr1);//这个函数不能自己追加自己
	strncat(arr1, arr1,len);//这个函数可以自己追加自己，最后的数字为需要追加的个数
	//2.判断arr2是否为arr1的子串 
	char* p = strstr(arr1, arr2);//若是，返回子串的位置，否则返回空指针
	return NULL != p;
}

//模拟实现strcat
char* myStrcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	//找\0
	while (*dest)
	{
		dest++;
	}
	//追加，包含\0
	while (*dest++ = *src++)
	{
		;
	}
	return ret;//返回目标空间的起始地址
}

//模拟实现strcmp
int myStrcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str2 == '\0')
			return 0;
		str1++;
		str2++;
	}

	//if (*str1 > *str2)
	//	return 1;
	//else 
	//	return -1;
	return *str1 - *str2;

}

//模拟实现strstr
char* myStrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = NULL;
	const char* s2 = NULL;
	const char* ss1 = str1;

	if (*str2 == '\0')
		return (char*)str1;

	while (*ss1)
	{
		//外层循环控制s1的起点是哪，即从哪里开始比较
		s1 = ss1;//ss1记录本次开始的位置
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//一个字节一个字节比较，相同就++
			s1++;
			s2++;
		}
		if (*s2 == '\0')//说明找到了
			return (char*)ss1;
		ss1++;//其余情况说明本次没找到，开始找下一次
	}
	return NULL;
}
//KMP算法


