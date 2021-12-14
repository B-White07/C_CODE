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

	//qsort函数的使用:快速排序，可以排任意类型的数据
	//1.冒泡排序
	//int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//print(arr, sz);
	//bubble_sort(arr, sz);
	//print(arr, sz);

	//2.qsort()
	//void qsort( void *base, size_t num, size_t width, int (*compare )(const void *elem1, const void *elem2 ) );
	//4个参数：
	//	1.base中存放的是待排序数据中的第一个对象的地址，void* 类型的指针可以接收任意类型的指针
	//	2.num是数据元素的个数
	//	3.size是每个元素的大小，单位字节
	//	4.函数指针，该函数用来比较待排序数据中的两个元素，返回>0，第一个元素大于第二个；=0，相等；<0第一个元素小于第二个
	//test_int();
	//test_struct();
	//模仿qsort实现任意类型的冒泡排序
	//test_struct2();


	//9.指针和数组面试题的解析
	//	sizeof(数组名)数组名单独放在括号内 和 &数组名 分别是结算整个数组的大小 和 取出整个数组的地址。
	//	除此之外，所有数组名都是首元素的地址
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));			//	16
	//printf("%d\n", sizeof(a + 0));		//	4	a+0是第一个元素的地址
	//printf("%d\n", sizeof(*a));			//	4	a是1的地址，*a表示1
	//printf("%d\n", sizeof(a + 1));		//	4	a+1是第二个元素的地址
	//printf("%d\n", sizeof(a[1]));		//	4	
	//printf("%d\n", sizeof(&a));			//	4
	//printf("%d\n", sizeof(*&a));		//	16	*&其实相互抵消了
	//printf("%d\n", sizeof(&a + 1));		//	4	数组后边的空间的地址，都是地址	*(&a + 1)能访问一个数组的大小
	//printf("%d\n", sizeof(&a[0]));		//	4	无论指向哪里，都是地址
	//printf("%d\n", sizeof(&a[0] + 1));	//	4	无论指向哪里，都是地址

	//字符数组
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));			// 6
	//printf("%d\n", sizeof(arr + 0));		// 4
	//printf("%d\n", sizeof(*arr));			// 1
	//printf("%d\n", sizeof(arr[1]));			// 1
	//printf("%d\n", sizeof(&arr));			// 4
	//printf("%d\n", sizeof(&arr + 1));		// 4
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4
	//printf("%d\n", strlen(arr));			// 随机
	//printf("%d\n", strlen(arr + 0));		// 随机
	//printf("%d\n", strlen(*arr));			// err	将97当成地址处理，发生了错误
	//printf("%d\n", strlen(arr[1]));			// err	将98当成地址处理，发生了错误
	//printf("%d\n", strlen(&arr));			// 随机	char(*)[6] -> char *
	//printf("%d\n", strlen(&arr + 1));		// 随机 - 6
	//printf("%d\n", strlen(&arr[0] + 1));	// 随机 - 1
	//	strlen接收的参数是字符指针

	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));			// 7
	//printf("%d\n", sizeof(arr + 0));		// 4
	//printf("%d\n", sizeof(*arr));			// 1
	//printf("%d\n", sizeof(arr[1]));		// 1
	//printf("%d\n", sizeof(&arr));			// 4	char(*)[7]
	//printf("%d\n", sizeof(&arr + 1));		// 4
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4
	//printf("%d\n", strlen(arr));			// 6
	//printf("%d\n", strlen(arr + 0));		// 6
	//printf("%d\n", strlen(*arr));			// err
	//printf("%d\n", strlen(arr[1]));			// err
	//printf("%d\n", strlen(&arr));			// 6
	//printf("%d\n", strlen(&arr + 1));		// 随机
	//printf("%d\n", strlen(&arr[0] + 1));	// 5

	//char* p = "abcdef";//p指向首地址
	//printf("%d\n", sizeof(p));				// 4
	//printf("%d\n", sizeof(p + 1));			// 4
	//printf("%d\n", sizeof(*p));				// 1
	//printf("%d\n", sizeof(p[0]));			// 1		p[0] <=> *(p + 0)
	//printf("%d\n", sizeof(&p));				// 4
	//printf("%d\n", sizeof(&p + 1));			// 4
	//printf("%d\n", sizeof(&p[0] + 1));		// 4
	//printf("%d\n", strlen(p));			// 6
	//printf("%d\n", strlen(p + 1));		// 5
	//printf("%d\n", strlen(*p));			// err *p是a，传递的是a的ASCLL码值，出错
	//printf("%d\n", strlen(p[0]));		// err 传递的是a的ASCLL码值，出错
	//printf("%d\n", strlen(&p));			// 随机1
	//printf("%d\n", strlen(&p + 1));		// 随机2
	//printf("%d\n", strlen(&p[0] + 1));	// 5	+1加多少，看取出来的是什么类型

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));				// 48
	//printf("%d\n", sizeof(a[0][0]));		// 4
	//printf("%d\n", sizeof(a[0]));			// 16	a[0]可以理解为第一行数组名，计算的是第一行数组的大小，因为sizeof括号内只有数组名
	//printf("%d\n", sizeof(a[0] + 1));		// 4	数组名a[0]非单独在括号内，也没有&，表示数组首元素地址，即第一行第二个元素的地址，+1跳过一个整型即a[0] + 1 表示a[0][1]
	//printf("%d\n", sizeof(*(a[0] + 1)));	// 4	*(a[0] + 1))是第一行第二个元素
	//printf("%d\n", sizeof(a + 1));			// 4	a是二维数组名，但没有&或者单独在sizeof()内，因此a为首元素地址，二维数组的首元素是第一行，+1跳过一行，为第二行的地址
	//printf("%d\n", sizeof(*(a + 1)));		// 16	(a + 1)为第二行的地址，解引用找到的是整个第二行		*(a + 1) <=> a[1]
	//printf("%d\n", sizeof(&a[0] + 1));		// 4	整个第一行的地址 + 1 = 整个第二行的地址
	//printf("%d\n", sizeof(*(&a[0] + 1)));	// 16	
	//printf("%d\n", sizeof(*a));				// 16	二位数组的第一个元素为第一行的一维数组		*a <=> *(a + 0) <=> a[0]
	//printf("%d\n", sizeof(a[3]));			// 16	表达式的两个属性：值属性和类型属性	a[3]的类型是int [4]
	//										//这里虽然没有访问a[3]，但是可以知道它的类型，也就知道了它的大小。a[3] <=> *(a + 3)
	//sizeof(表达式)：表达式并不会计算，所以不会发生越界的情况，但是表达式结果的类型是知道的。

	//1.
	//int a[5] = { 1,2,3,4,5 };
	//int* ptr = (int*)(&a + 1);
	//printf("%d,%d", *(a + 1), *(ptr - 1));	//	2	5

	//2.指针类型决定了指针的运算
	//printf("%p\n", p);
	//printf("%p\n", p + 0x1);					//跳过一个结构体大小：0x100000 + 0x000014 = 0x100014
	//printf("%p\n", (unsigned long)p + 0x1);		//就是整型+整型：0x100000 + 0x1 = 0x100001
	//printf("%p\n", (unsigned int*)p + 0x1);		//跳过一个整型大小：0x100000 + 0x000004 = 0x100004
	//加16进制数也只是普通加法而已，并不是加地址，地址+地址是没有意义的，因此指针+1后的偏移量还是取决于指针的类型

	//3.
	//int a[4] = { 1,2,3,4 };
	//int* ptr1 = (int*)(&a + 1);	
	//int* ptr2 = (int*)((int)a + 1);
	//printf("%#x,%#x", ptr1[-1], *ptr2);// 4	2000000

	//4.
	//int a[3][2] = { (0,1),(2,3),(4,5) };//逗号表达式	1	3	5
	//int* p;
	//p = a[0];
	//printf("%d",p[0]);	// 1

	//5.
	//int a[5][5];// 0 0 0 0 0	0 0 0 0 0	0 0 0 0 0	0 0 0 0 0	0 0 0 0 0
	//int(*p)[4];	// 0 0 0 0		0 0 0 0		0 0 0 0		0 0 0 0		0 0 0 0
	//p = a;		// a:int(*)[5]
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//	FFFFFFFC,-4
	//地址 - 地址得到两个地址中间的元素的个数
	//-4: 10000000 00000000 00000000 00000100 --> 11111111 11111111 11111111 11111011 --> 11111111 11111111 11111111 11111100
	// --> FF FF FF FC

	//6.
	//int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* ptr1 = (int*)(&aa + 1);
	//int* ptr2 = (int*)(*(aa + 1));//*(aa+1) <=>aa[1]，即第二行首元素的地址，即6的地址；
	////或者这么理解，aa是一个数组指针，其类型为int(*)[5]，对其解引用得到了一个数组aa[0]，这个数组又是其首元素的地址类型为：int*
	////可以看出，其实ptr2不需要强制类型转换
	//printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//	10,5

	//7.
	//char* a[] = { "study","at","fuda" };//a是一个指针数组，每个元素都是char*，为字符串首元素的地址
	//char** pa = a;//pa指向a首元素，a首元素类型为char*
	//pa++;
	//printf("%s\n", *pa);//at

	//8.
	//char* c[] = { "ENTER","NEW","POINT","FIRST" };
	//char** cp[] = { c + 3,c + 2,c + 1,c };
	//char*** cpp = cp;
	//printf("%s\n", **++cpp);		//POINT
	//printf("%s\n", *--* ++cpp + 3);	//ER	注意--是操作在谁的身上
	//printf("%s\n", *cpp[-2] + 3);	//ST
	//printf("%s\n", cpp[-1][-1] + 1);//EW


	return 0;
}
