#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"
//模拟实现strcpy
int main() 
{
	//const修饰变量，这个变量就被称为常变量，不能被修改，但是本质上还是变量。
	//const int num = 10;
	//int n = 100;
	////num = 20;//err
	////int* p = &num;//这样就可以更改num的值
	//const int* p = &num;//const如果放在*左边，修饰的是*p，表示指针指向的内容不能通过指针来改变，但是指针变量本身是可以修改的
	////*p = 20;
	//p = &n;//*p不能修改，但是p仍可以修改

	//const int num = 10;
	//int n = 100;
	////num = 20;//err
	////int* p = &num;//这样就可以更改num的值
	//int* const p = &num;//const如果放在*右边，修饰的是指针变量p，表示指针变量不能被改变，但是指针指向的内容可以被修改
	//*p = 20;//*p能修改，但是p不可以修改。
	//p = &n;
	//printf("%d", num);
	//int const* const p = &num;//指针本身和指针指向的变量都不可以改

	//char arr1[20] = "xxxxxxxxxx";
	//char arr2[] = "hello";
	//printf("%s\n", myStrcpy2(arr1, arr2));//链式访问
	//printf("%d\n", myStrlen(arr1));

	//编程常见错误：
	//	1.编译型错误	2.链接性错误(无法解析的外部符号，其实就是名字不一样或者没有定义该符号)	
	//	3.运行时错误

	//1的个数
	//int n = -1;
	//printf("%d", numOf1(n));

	//2的n次方
	//if (1 == ncifang(127))
	//	printf("Yes");
	//else
	//	printf("No");

	//不同位的个数
	//printf("%d",dif(22, 33));

	//奇偶位
	//jiOu(10);

	//题
	//语言本身没有输入输出函数，只是规定了语法规则。库函数不属于C语言
	//char arr[100] = { 0 };
	//gets(arr);
	//char* start = arr;
	//char* end = start + myStrlen(arr) - 1;
	//reverse(start, end);
	//reverseWord(arr);
	//printf("%s", arr);



	return 0;
}