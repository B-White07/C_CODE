#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
void print(int* p, int sz)
{
	for (int i = 0; i < sz; i++)
		printf("%d ", *(p + i));
	printf("\n");
}
void test(char* p) {}

void test2(int** p2)
{
	**p2 = 20;
}

int Add(int x, int y)
{
	return x + y;
}
void test3(char* str) {}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("********************\n");
	printf("**1.Add      2.Sub**\n");
	printf("**3.Mul      4.Div**\n");
	printf("**     0.exit     **\n");
}

int Cacl(int (*pfun)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数：\n");
	scanf("%d %d", &x, &y);
	return pfun(x, y);
}

void bubble_sort(int arr[], int sz)
{
	for (int i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			int tmp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = tmp;
			flag = 0;
		}
		if (flag == 1)
			break;
	}
}

int cmp_int(void* e1, void* e2)
{
	return *(int*)e1 - *(int*)e2;	//不能直接对形参解引用，因为他是void类型指针，解引用不知道应该访问几个字节
}
void test_int()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}


int sortByAge(void* e1, void* e2)
{//按年龄排序
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int sortByName(void* e1, void* e2)
{//按名字排序
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//strcmp比较对应位置字符的ASCLL
}
void test_struct()
{
	struct Stu s[] = { {"zhangsan",30},{"lisi",35},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), sortByAge);
	qsort(s, sz, sizeof(s[0]), sortByName);
}

//模拟qsort，实现任意类型的冒泡排序
void swap(char* start, char* end, int width)
{
	for (int i = 0; i < width; i++)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end++;
	}
	
}
void bubble_sort2(void* base, int size, int width, int(*compare)(const void* element1, const void* element2))
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			//两个元素的比较
			if ( compare( (char*)base + j * width , (char*)base + (j + 1) * width) > 0 )
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void test_int2()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort2(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}

void test_struct2()
{
	struct Stu s[] = { {"zhangsan",30},{"lisi",35},{"wangwu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	//bubble_sort2(s, sz, sizeof(s[0]), sortByAge);
	bubble_sort2(s, sz, sizeof(s[0]), sortByName);
}