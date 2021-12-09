#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

//int main()
//{
//	/*
//		二、指针
//		1.字符指针		2.指针数组		3.数组指针		4.数组传参和指针传参		5.函数指针
//		6.函数指针数组	7.指向函数指针数组的指针		8.回调函数		9.指针和数组面试题的解析
//	*/
//	//1.字符指针
//	//char ch = 'q';
//	//char* pc = &ch;
//	//char* ps = "hello world";//本质上是把字符串的首字符地址存储在了ps中
//	//*ps = 'w';//err，常量不能改
//	//char arr[] = "hello world";
//	//printf("%c\n", *ps);
//	//printf("%s\n", ps);
//	//printf("%s\n", arr);
//
//	//char str1[] = "hello world.";
//	//char str2[] = "hello world.";
//	//const char* str3 = "hello world.";
//	//const char* str4 = "hello world.";//"hello world."是常量字符串，在内存中只有一份。两个指针指向同一空间
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
//	//2.指针数组：是存放指针的数组
//	//int *arr[3];//存放整型指针的数组
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
//	//3.数组指针--指向数组的指针
//	//整形指针--指向整形的指针		字符指针--指向字符的指针
//	//int arr[10] = { 1,2,3,4,5 };
//	////arr;//是首元素arr[0]的地址
//	//int(*parr)[10] = &arr;//parr就是一个数组指针，其中存放的是数组的地址.			若无括号，parr先和[]结合，变成了指针数组。
//	//double* d[5];
//	//double* (*pd)[5] = &d;//pd就是一个数组指针
//
//	//int arr[10] = { 0 };
//	////printf("%p\n", arr);
//	////printf("%p\n", &arr);
//	//int* p1 = arr;
//	//int(*p2)[10] = &arr;//取出的是数组的地址
//	//printf("%p\n", p1);
//	//printf("%p\n", p1 + 1);
//	//printf("%p\n", p2);
//	//printf("%p\n", p2 + 1);
//
//	//数组名是数组首元素的地址，但是有两个例外：
//	//	1.sizeof(数组名) - 数组名表示整个数组，计算的是整个数组的大小，单位是字节
//	//	2.&数组名 - 数组名表示整个数组，取出的是整个数组的地址
//
//	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int(*pa)[10] = &arr;
//	//for (int i = 0; i < 10; i++)
//	//	printf("%d ", *(*pa + i));//数组指针用在一维数组很繁琐
//
//	//int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	////print1(arr, 3, 5);
//	//print2(arr, 3, 5);
//
//	//int arr[5]	arr是整型数组。
//	//int *parr1[10]	parr1是整型指针的数组。
//	//int (*parr2)[10]		parr2是数组指针，该指针指向一个数组，数组有10个元素，每个元素是int型。
//	//int (*parr3[10])[5];		parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，每个指针指向一个有5个元素的数组，每个元素位int型
//	//数组名[]去掉以后，剩下的就是数组每个元素的类型
//
//	//4.数组传参和指针传参
//	//	1.一维数组传参
//	//int arr[10] = { 0 };
//	//int* arr2[20] = { 0 };
//	//test(arr);//ok
//	//test2(arr2);//ok
//	//调用arr
//	//void test(int arr[]) {}//ok
//	//void test(int arr[10]) {}//ok
//	//void test(int* arr) {}//ok
//	//调用arr2
//	//void test(int* arr[20]) {}//ok
//	//void test(int** arr) {}//ok
//
//	//	2.二维数组传参
//	//int arr[3][5] = { 0 };
//	//void test(int arr[3][5]) {}//ok
//	//void test(int arr[][5]) {}//ok
//	//void test(int arr[][]) {}//err
//	//void test(int* arr) {}//err
//	//void test(int* arr[5]) {}//err
//	//void test(int (*arr)[5]) {}//ok
//	//void test(int** arr) {}//err
//
//	//其实就是看传过去的是什么，以及是什么类型
//
//
//
//	//5.函数指针
//	//6.函数指针数组
//	//7.指向函数指针数组的指针
//	//8.回调函数
//	//9.指针和数组面试题的解析
//
//	return 0;
//}

//题
//int i;//不初始化，默认为0
int main()
{
	//1.
	//i--;
	//if (i > sizeof(i))//sizeof的计算结果为unsigned int,int与其运算时需要转换为unsigned int
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
	//在32位大端模式处理器上b等于?			无论大端小端，解引用总是从内存地位开始
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