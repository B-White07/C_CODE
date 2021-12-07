#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

//模拟实现strcpy
void myStrcpy1(char* dest,char* src)
{
	while (*dest++ = *src++)
	{
		;
	}
}
//改进
//只希望dest指向的内容被修改，而src指向的内容不应被修改
//strcpy()返回的是目标空间的的起始地址
char* myStrcpy2(char* dest,const char* src)
{
	assert(src != NULL);//断言，表达式为假报错
	assert(dest != NULL);//断言，表达式为假报错
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	} 
	return ret;
}

//模拟strlen()
//健壮性、鲁棒性
//size_t -- unsigned int
size_t myStrlen(const char* str)
{
	assert(str != NULL);
	//assert(str);
	size_t len = 0;
	while (*str++ != '\0')
	{
		len++;
	}
	return len;
}

//计算n二进制中1的个数
int numOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

//判断一个数是否是2的n次方
//2的n次方只有一个1
int ncifang(int n)
{
	int flag = 0;
	if (0 == n & (n - 1))
	{
		flag = 1;
	}
	return flag;
}

//判断两个数不同位的个数
int dif(int a, int b)
{
	int res = a ^ b;
	return numOf1(res);
}

//分别打印一个数的奇数位和偶数位
void jiOu(int n)
{
	for (int i = 31; i >= 1; i-=2)
		printf("%d", (n >> i) & 1);
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
		printf("%d", (n >> i) & 1);
}

//最小公倍数
int zui(int a, int b)
{
	for (int i = 0;; i++)
	{
		if (a * i % b == 0)
		{
			return a * i;
		}
	}
}

//倒置字符串中的单词 -- 三步翻转法：1.字符串整体反转	2.每个单词逆序
void reverse(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverseWord(char* str)
{
	char* start = str;
	while (*start)
	{
		char* end = start;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		reverse(start, end - 1);
		if (*end == ' ')
			start = end + 1;
		else
			start = end;
	}
}
