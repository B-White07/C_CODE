#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

//���Ͼ���
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ���Ҫ��Ȳ������
//��д�����������ľ����в���ĳ�������Ƿ���ڣ�Ҫ��ʱ�临�ӵ�С��O(N)
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
//			//printf("�ҵ��ˣ�λ���ǣ�%d %d", x, y);
//			return 1;//�ҵ�����1
//		}		
//	}
//	return 0;//�Ҳ�������0
//}
//�Ľ�
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
			*px = x;//ͨ��ָ�뽫λ����Ϣ����ȥ
			*py = y;
			return 1;//�ҵ�����1
		}
	}
	return 0;//�Ҳ�������0
}

//�����ַ���
//ʵ��һ�����������������ַ����е�k���ַ�
//eg��ABCD����һ���ַ��õ�BCDA�����������ַ��õ�CDAB
//����1
void strRotate(char* pa, int n)
{
	int len = strlen(pa);
	//��Ҫ��ת����
	for (int i = 0; i < n; i++)
	{
		//ÿ����ת1���ֽ�
		char tmp = *pa;
		for (int j = 0; j < len - 1; j++)
		{
			*(pa + j) = *(pa + j + 1);
		}
		*(pa + len - 1) = tmp;
	}
}
//����2���������򷨣���������ұ�������������
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

//�ж�һ���ַ����Ƿ�Ϊ��һ���ַ�����ת֮����ַ���
//eg��AABCD��BCDAA����1		abcd��ACBD����0
int isStrRotate(char* arr1, char* arr2)
{
	int len = strlen(arr1);
	//��Ҫ��ת����
	for (int i = 0; i < len; i++)
	{
		//ÿ����ת1���ֽ�
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
	//�ȿ��ǳ��Ȳ�һ������������Ȳ����һ��������ת�õ���
	if (strlen(arr1) != strlen(arr2))
		return 0;
	int len = strlen(arr1);
	//1.��arr1׷��һ��arr1
	//AABCDAABCD������AABCD������ת�����
	//strcat(arr1, arr1);//������������Լ�׷���Լ�
	strncat(arr1, arr1,len);//������������Լ�׷���Լ�����������Ϊ��Ҫ׷�ӵĸ���
	//2.�ж�arr2�Ƿ�Ϊarr1���Ӵ� 
	char* p = strstr(arr1, arr2);//���ǣ������Ӵ���λ�ã����򷵻ؿ�ָ��
	return NULL != p;
}

//ģ��ʵ��strcat
char* myStrcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	//��\0
	while (*dest)
	{
		dest++;
	}
	//׷�ӣ�����\0
	while (*dest++ = *src++)
	{
		;
	}
	return ret;//����Ŀ��ռ����ʼ��ַ
}

//ģ��ʵ��strcmp
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

//ģ��ʵ��strstr
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
		//���ѭ������s1��������ģ��������￪ʼ�Ƚ�
		s1 = ss1;//ss1��¼���ο�ʼ��λ��
		s2 = str2;
		while (*s1 && *s2 && (*s1 == *s2))
		{
			//һ���ֽ�һ���ֽڱȽϣ���ͬ��++
			s1++;
			s2++;
		}
		if (*s2 == '\0')//˵���ҵ���
			return (char*)ss1;
		ss1++;//�������˵������û�ҵ�����ʼ����һ��
	}
	return NULL;
}
//KMP�㷨


