#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

//int main()
//{
//	/*
//		����ָ��
//		1.�ַ�ָ��		2.ָ������		3.����ָ��		4.���鴫�κ�ָ�봫��		5.����ָ��
//		6.����ָ������	7.ָ����ָ�������ָ��		8.�ص�����		9.ָ�������������Ľ���
//	*/
//	//1.�ַ�ָ��
//	//char ch = 'q';
//	//char* pc = &ch;
//	//char* ps = "hello world";//�������ǰ��ַ��������ַ���ַ�洢����ps��
//	//*ps = 'w';//err���������ܸ�
//	//char arr[] = "hello world";
//	//printf("%c\n", *ps);
//	//printf("%s\n", ps);
//	//printf("%s\n", arr);
//
//	//char str1[] = "hello world.";
//	//char str2[] = "hello world.";
//	//const char* str3 = "hello world.";
//	//const char* str4 = "hello world.";//"hello world."�ǳ����ַ��������ڴ���ֻ��һ�ݡ�����ָ��ָ��ͬһ�ռ�
//	//if (str1 == str2)
//	//	printf("str1 and str2 are same\n");
//	//else
//	//	printf("str1 and str2 are not same\n");
//	//if (str3 == str4)
//	//	printf("str3 and str4 are same\n");
//	//else
//	//	printf("str3 and str4 are not same\n");
//
//
//	//2.ָ�����飺�Ǵ��ָ�������
//	//int *arr[3];//�������ָ�������
//	//int a = 10;
//	//int b = 20;
//	//int c = 30;
//	//int* arr[3] = { &a,&b,&c };
//	//for (int i = 0; i < 3; i++)
//	//	printf("%d ", *(arr[i]));
//
//	//int a[5] = { 1,2,3,4,5 };
//	//int b[] = { 2,3,4,5,6 };
//	//int c[] = { 3,4,5,6,7 };
//
//	//int* arr[3] = { a,b,c };
//	//for (int i = 0; i < 3; i++)
//	//{
//	//	for (int j = 0; j < 5; j++)
//	//		printf("%d ", *(arr[i] + j));
//	//		//printf("%d ",arr[i][j]);
//	//	printf("\n");
//	//}
//
//	//3.����ָ��--ָ�������ָ��
//	//����ָ��--ָ�����ε�ָ��		�ַ�ָ��--ָ���ַ���ָ��
//	//int arr[10] = { 1,2,3,4,5 };
//	////arr;//����Ԫ��arr[0]�ĵ�ַ
//	//int(*parr)[10] = &arr;//parr����һ������ָ�룬���д�ŵ�������ĵ�ַ.			�������ţ�parr�Ⱥ�[]��ϣ������ָ�����顣
//	//double* d[5];
//	//double* (*pd)[5] = &d;//pd����һ������ָ��
//
//	//int arr[10] = { 0 };
//	////printf("%p\n", arr);
//	////printf("%p\n", &arr);
//	//int* p1 = arr;
//	//int(*p2)[10] = &arr;//ȡ����������ĵ�ַ
//	//printf("%p\n", p1);
//	//printf("%p\n", p1 + 1);
//	//printf("%p\n", p2);
//	//printf("%p\n", p2 + 1);
//
//	//��������������Ԫ�صĵ�ַ���������������⣺
//	//	1.sizeof(������) - ��������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//	//	2.&������ - ��������ʾ�������飬ȡ��������������ĵ�ַ
//
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int(*pa)[10] = &arr;
//	//for (int i = 0; i < 10; i++)
//	//	printf("%d ", *(*pa + i));//����ָ������һά����ܷ���
//
//	//int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	////print1(arr, 3, 5);
//	//print2(arr, 3, 5);
//
//	//int arr[5]	arr���������顣
//	//int *parr1[10]	parr1������ָ������顣
//	//int (*parr2)[10]		parr2������ָ�룬��ָ��ָ��һ�����飬������10��Ԫ�أ�ÿ��Ԫ����int�͡�
//	//int (*parr3[10])[5];		parr3��һ�����飬��������10��Ԫ�أ�ÿ��Ԫ����һ������ָ�룬ÿ��ָ��ָ��һ����5��Ԫ�ص����飬ÿ��Ԫ��λint��
//	//������[]ȥ���Ժ�ʣ�µľ�������ÿ��Ԫ�ص�����
//
//	//4.���鴫�κ�ָ�봫��
//	//	1.һά���鴫��
//	//int arr[10] = { 0 };
//	//int* arr2[20] = { 0 };
//	//test(arr);//ok
//	//test2(arr2);//ok
//	//����arr
//	//void test(int arr[]) {}//ok
//	//void test(int arr[10]) {}//ok
//	//void test(int* arr) {}//ok
//	//����arr2
//	//void test(int* arr[20]) {}//ok
//	//void test(int** arr) {}//ok
//
//	//	2.��ά���鴫��
//	//int arr[3][5] = { 0 };
//	//void test(int arr[3][5]) {}//ok
//	//void test(int arr[][5]) {}//ok
//	//void test(int arr[][]) {}//err
//	//void test(int* arr) {}//err
//	//void test(int* arr[5]) {}//err
//	//void test(int (*arr)[5]) {}//ok
//	//void test(int** arr) {}//err
//
//	//��ʵ���ǿ�����ȥ����ʲô���Լ���ʲô����
//
//
//
//	//5.����ָ��
//	//6.����ָ������
//	//7.ָ����ָ�������ָ��
//	//8.�ص�����
//	//9.ָ�������������Ľ���
//
//	return 0;
//}

//��
//int i;//����ʼ����Ĭ��Ϊ0
int main()
{
	//1.
	//i--;
	//if (i > sizeof(i))//sizeof�ļ�����Ϊunsigned int,int��������ʱ��Ҫת��Ϊunsigned int
	//	printf(">\n");
	//else
	//	printf("<\n");

	//2.
	//int a = 0;
	//int n = 0;
	//scanf("%d %d", &a, &n);
	//printf("%d", Sn(a, n));

	//3.
	//isZiMi();

	//4.
	//int money = 0;
	//scanf("%d", &money);
	//printf("%d", drink(money));

	//5.
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int len = sizeof(arr) / sizeof(arr[0]);
	//change(arr, len);
	//print(arr,len);

	//6.
	//��32λ���ģʽ��������b����?			���۴��С�ˣ����������Ǵ��ڴ��λ��ʼ
	//unsigned int a = 0x1234;
	////00 00 12 34 - a
	////00 - *(unsigned char*)&a
	////00 - b
	//unsigned char b = *(unsigned char*)&a;

	//7.
	//yangHui();
		
	//8.
	//printf("%c", whoIsKiller());

	//9.
	order();


	return 0;
}