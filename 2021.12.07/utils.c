#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

//ģ��ʵ��strcpy
void myStrcpy1(char* dest,char* src)
{
	while (*dest++ = *src++)
	{
		;
	}
}
//�Ľ�
//ֻϣ��destָ������ݱ��޸ģ���srcָ������ݲ�Ӧ���޸�
//strcpy()���ص���Ŀ��ռ�ĵ���ʼ��ַ
char* myStrcpy2(char* dest,const char* src)
{
	assert(src != NULL);//���ԣ����ʽΪ�ٱ���
	assert(dest != NULL);//���ԣ����ʽΪ�ٱ���
	char* ret = dest;
	while (*dest++ = *src++)
	{
		;
	} 
	return ret;
}

//ģ��strlen()
//��׳�ԡ�³����
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

//����n��������1�ĸ���
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

//�ж�һ�����Ƿ���2��n�η�
//2��n�η�ֻ��һ��1
int ncifang(int n)
{
	int flag = 0;
	if (0 == n & (n - 1))
	{
		flag = 1;
	}
	return flag;
}

//�ж���������ͬλ�ĸ���
int dif(int a, int b)
{
	int res = a ^ b;
	return numOf1(res);
}

//�ֱ��ӡһ����������λ��ż��λ
void jiOu(int n)
{
	for (int i = 31; i >= 1; i-=2)
		printf("%d", (n >> i) & 1);
	printf("\n");
	for (int i = 30; i >= 0; i -= 2)
		printf("%d", (n >> i) & 1);
}

//��С������
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

//�����ַ����еĵ��� -- ������ת����1.�ַ������巴ת	2.ÿ����������
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
