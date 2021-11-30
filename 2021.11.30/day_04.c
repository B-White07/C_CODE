#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


#include "utils.h"
//导入静态库
//#pragma comment(lib,"utils.lib")

//静态库生成：右击项目 - 属性 - 常规 - 配置类型 - 静态库 - 应用 - 确定 - 编译，会在debug文件中生成.lib文件，
//将.h文件和.lib文件打包，即可被调用：将.h文件添加到头文件，引用头文件，导入静态库。
int main()
{
	/*
	一、函数
	形参只有在函数被调用的时候才为其分配空间，函数调用结束的时候形参会自动销毁，即生命周期在函数内部，与局部变量一样。
	自定义若不写返回类型，默认为int
	1.库函数			2.自定义函数		3.函数的嵌套调用和链式访问		4.函数的声明和定义
	*/
	//1.库函数	举两个例子
	//strcpy()
	//char arr1[20] = { 0 };
	//char arr2[] = "hello world";
	//strcpy(arr1, arr2);
	//printf("%s", arr1);

	//memset() -- 内存设置
	//char arr[] = "hello world";
	//memset(arr, 'x', 5);//中间的参数需要int型，字符也是int（通过ACSLL码）
	//printf("%s", arr);

	//2.自定义函数
	//交换变量的值
	//int a = 10;
	//int b = 20;
	//swap1(a, b);//传值调用，形参与实参没有联系，形参改变不会影响实参
	//printf("before:a=%d,b=%d\n",a,b);
	//swap2(&a,&b);//传址调用，形参与实参有联系，形参改变可以影响实参
	//printf("after:a=%d,b=%d",a,b);

	//3.函数的嵌套调用和链式访问
	//注意：函数不能嵌套定义。
	//链式访问：把一个函数的返回值作为另外一个函数的参数。
	//char arr1[20] = { 0 };
	//char arr2[] = "hello world";
	//printf("%s\n", strcpy(arr1, arr2));
	//printf("%d", printf("%d", printf("%s","sd1 2")));//printf()返回打印在屏幕上的字符的个数。

	int a = 10;
	int b = 20;
	//函数声明，告诉编译器有这个函数,包括函数名，返回值类型，参数个数和类型。
	//放在函数调用之前，即先声明，后使用。	函数的声明一般放在头文件中,而函数的定义放在.c文件中。
	int Add(int, int);
	printf("%d", Add(a, b));

	return 0;
}

int Add(int x, int y)
{
	return x + y;
}
