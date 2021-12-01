#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"utils.h"
//extern int count;
int main()
{
	/*
		一、函数的递归：函数调用自身
		递归的两个必要条件：1.存在限制条件，当满足这个限制条件的时候，递归便不再继续。
							2.每次递归调用之后越来越接近这个限制条件。
		函数调用时会在栈为此函数开辟一块空间，用来存放函数的临时变量，叫栈帧空间。
		写递归的时候：1.不能死递归，要有跳出条件，每次递归逼近跳出条件。
					  2.递归层次不能太深。
		函数内复合语句中定义的变量只在复合语句内有效（复合语句指一对大括号）

	*/
	//printf("hello world");
	//main();

	//练习1.打印数字
	//int n = 0;
	//scanf("%d", &n);
	//print(n);

	//test(1);

	//练习2.编写函数计算字符串长度
	//char arr[] = "hello";
	//printf("%d\n",myStrlen1(arr));
	//printf("%d\n",myStrlen2(arr));

	//递归与迭代：循环就是一种迭代
	//练习3.求n的阶乘，不考虑溢出
	//int a = 0;
	//scanf("%d", &a);
	//printf("%d", jieCheng(a));

	//练习4.求第n个斐波那契数（不考虑溢出）
	//int a = 0;
	//scanf("%d", &a);
	//printf("%d\n", fib2(a));

	//5.汉诺塔
	//int n = 0;
	//scanf("%d", &n);
	//hanNuo('A', 'B', 'C', n);
	//printf("共移动%d次\n", count);

	//6.青蛙跳台阶


	//计算1/1-1/2+1/3-1/4+...-1/100的值，打印结果
	//printf("%lf\n", sum1());
	//printf("%lf\n", sum2());

	//比较大小
	//int arr[] = { 1,2,3,4,5,6,7,-8 };
	//int length = sizeof(arr) / sizeof(arr[0]);
	//printf("%d", Max(arr, length));

	//乘法表
	//int n = 0;
	//scanf("%d", &n);
	//chengFaBiao(n);

	//反转字符串
	//char arr[] = "hello";
	//reverseStr1(arr);
	//printf("%s", arr);
	//递归
	//reverseStr2(arr);
	//printf("%s", arr);

	//写一个递归函数，输入一个非负整数，返回组成他的数字之和
	//int a = 0;
	//scanf("%d", &a);
	//printf("%d\n",DigitSum1(a));
	//printf("%d\n",DigitSum2(a));

	//n的k次方
	//int n = 0;
	//int k = 0;
	//scanf("%d %d", &n, &k);
	//printf("%d的%d次方是：%lf", n, k, chengFang(n, k));

	double n = 1/2;

	printf("%lf", n);

	return 0;
}