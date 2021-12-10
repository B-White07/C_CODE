#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
int main()
{
	/*
		指针
		1.字符指针		2.指针数组		3.数组指针		4.数组传参和指针传参		5.函数指针
		6.函数指针数组	7.指向函数指针数组的指针		8.回调函数		9.指针和数组面试题的解析
	*/
	//4.数组传参和指针传参
	//	3.一级指针传参
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* p = arr;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//print(p, sz);

	//char ch = 'w';
	//char* p1 = &ch;
	//test(&ch);
	//test(p1);
	//	4.二级指针传参
	//int a = 10;
	//int* pa = &a;//pa是一级指针
	//int* *ppa = &pa;//ppa是二级指针
	////传递二级指针
	//test2(ppa);//传二级指针
	//test2(&pa);//传一级指针变量的地址
	//int* arr[10] = { 0 };
	//test2(arr);//传一级指针数组
	//printf("%d", a);


	//5.函数指针：指向函数的指针，即存放函数地址的指针		&函数名，取的就是函数的地址
	//数组名 != &数组名			函数名 == &函数名
	//void (*pt)(char*) = &test3;
	//printf("%p\n", &Add);
	//printf("%p\n", Add);
	//int (*pf)(int, int) = &Add;//pf就是一个函数指针变量
	//int (*pf)(int, int) = Add;//Add <==> pf
	//printf("%d\n",(**pf)(3, 5));//对函数指针解引用来调用函数，其实*无意义，写几个都行		1
	//printf("%d\n",Add(3, 5));	//		2
	//printf("%d\n",pf(3, 5)); //这三行等价			3			1 <==> 2 <==> 3

	//题
	//1.
	//(*(void(*)())0)();//调用0地址处的函数，该函数无参，返回类型是void
	////void(*)()			 - 函数指针类型
	////(void(*)())0		 - 将0强制类型转换为函数地址
	////*(void(*)())0		 - 对0地址进行解引用操作
	////(*(void(*)())0)()  - 调用0地址处的函数
	////2.
	//void (*signal(int, void(*)(int)))(int);
	////signal先和()结合，说明signal是函数名
	////signal函数的第一个参数的类型是int型，第二个参数的类型是函数指针，该指针指向一个参数为int，返回类型为void的函数
	////signal函数的返回类型是一个函数指针，该指针指向一个参数为int，返回类型为void的函数
	////signal是一个函数的声明
	////分析时：去掉函数名和参数即为返回类型		数组去掉名字和[]剩下的即为类型
	////void(*)(int) signal(int, void(*)(int));	//这种写法不允许，若函数返回值为函数指针，则*必须和函数名写在一起。
	////typedef 对类型进行重定义
	//typedef void (*pfun_t)(int);//对函数指针类型重命名为pfun_t，注意pfun_t必须和*写在一起而不能typedef void (*)(int) pfun_t
	//pfun_t signal(int, pfun_t);


	////6.函数指针数组：存放函数指针的数组
	//int (*pf1)(int, int) = Add;
	//int (*pf2)(int, int) = Sub;
	//int (*pfArr[2])(int, int) = { pf1,Sub };//pfArr为函数指针数组

	//计算器，计算整型的加减乘除
	//int input = 0;
	//do
	//{
	//	menu();
	//	scanf("%d", &input);
	//	//转移表 - 函数指针数组
	//	int (*pArr[4])(int, int) = { Add,Sub,Mul,Div };

	//	if ((input-1) >= 0 && (input-1) <= 3)
	//	{
	//		int x = 0;
	//		int y = 0;
	//		printf("请输入两个操作数：\n");
	//		scanf("%d %d", &x, &y);
	//		printf("%d\n", pArr[input - 1](x, y));
	//	}
	//	else if (input == 0)
	//	{
	//		printf("即将退出\n");
	//		break;
	//	}
	//	else
	//		printf("输入有误，请重新选择\n");
	//} while (input);


	//7.指向函数指针数组的指针
	//int(*p)(int, int);//函数指针
	//int(*pArr[10])(int, int);//函数指针的数组
	//int(*(*pa)[10])(int, int);//pa是指向函数指针数组的指针

	//8.回调函数：回调函数就是一个通过函数指针调用的函数。如果你把函数的指针(地址)作为参数传递给另一个函数，
	//当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数的实现方直接调用，而是在特定的事件
	//或者条件发生时由另外的一方调用的，用于对该事件或条件进行响应。
	//回调函数实现计算器
	//int input = 0;
	//do
	//{
	//	menu();
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		printf("%d\n",Cacl(Add));
	//		break;
	//	case 2:
	//		printf("%d\n", Cacl(Sub));
	//		break;
	//	case 3:
	//		printf("%d\n", Cacl(Mul));
	//		break;
	//	case 4:
	//		printf("%d\n", Cacl(Div));
	//		break;
	//	case 0:
	//		printf("即将退出\n");
	//		break;
	//	default:
	//		printf("有输入有效选项\n");
	//		break;
	//	}
	//} while (input);



	return 0;
}