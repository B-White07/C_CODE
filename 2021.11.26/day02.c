#define _CRT_SECURE_NO_WARNINGS 1
//#define MAX 1000
//#define M 1

//define定义宏
/*#define ADD(X,Y) ((X)+(Y))	*/	//注意加括号，ADD是将表达式X和Y直接替换到调用处。
#include<stdio.h>

//typedef unsigned int u_int;

//void test() {
//	static int a = 1;//不销毁。
//	a++;
//	printf("%d ", a);
//}

//extern 声明外部符号
//extern int g_val;

//声明函数
//extern int Add(int, int);

//struct Stu
//{
//	char name[20];//成员
//	int age;
//	double score;
//};
//
//struct Book
//{
//	char name[20];
//	float price;
//	char id[30];
//};

int main()
{
/*
	一、关键字：1.C语言提供的，不能自定义
				2.关键字不能做变量名。
				3.常见关键字：
					1.auto(自动创建和销毁，局部变量前都有，只是被省略)	2.break		3.case		4.const		5.continue	
					6.default	7.do	8.else		9.enum	10.extern(声明外部符号)	11.for		12.goto		13.if		
					14.register(寄存器关键字)	15.return	16.signed(有符号)	17.unsigned(无符号)	18.static(静态)	
					19.struct(结构体)	20.switch	21.typedef(类型重命名)	22.union(联合体/共用体)	23.sizeof	24.void		
					25.volatile		26.while
					define、include不是关键字，是预处理指令
				计算机中数据可以存储到：1.寄存器	2.高速缓存	3.内存	4.硬盘	5.网盘。造价依次降低，速度越慢，空间越大。
*/
	//大量频繁被使用的数据，想放在寄存器中，提升效率。当前计算机会判断从而自动放到寄存器中，因此此关键字意义不大。
	//register int num = 100;//建议num值存放在寄存器中

	//typedef
	//unsigned int num = 100;
	//u_int num2 = 100;

	//static	1.修饰局部变量		2.修饰全局变量		3.修饰函数
	//1.static修饰局部变量，改变了局部变量的生命周期（本质上是改变了变量的存储类型），静态变量和全局变量生命周期一样，程序不结束就不销毁。
	//注意只是修改了生命周期，并非不可更改。
	//内存划分为几个区域：1.栈区：存放局部变量，函数的参数		2.堆区：动态内存分配		静态区：全局变量，static修饰的静态变量
	//int i = 0;
	//while (i < 10) {
	//	test();
	//	i++;
	//}

	//2.static修饰全局变量，使得此全局变量只能在自己所在的源文件内部可以使用，其他源文件不能使用。
	//全局变量在其他源文件内部可以被使用，是因为其具有外部链接属性，被static修饰后，就变成了内部链接属性，其他源文件就不能链接到这个静态的全局变量了。
	//printf("%d\n",g_val);

	//3.static修饰函数，使得函数只能在自己所在的源文件内部使用，不能在其他源文件内部使用。
	//本质上，static是将函数的外部链接属性变成了内部链接属性（同static修饰全局变量）。
	//int a = 10;
	//int b = 20;
	//printf("%d\n",Add(a,b));


/*
	二、#define定义常量和宏
	define是一个预处理指令：1.define定义符号常量	#define MAX 10000
							2.define定义宏，是替换。
*/
	////printf("%d", MAX);
	//printf("%d\n", ADD(2, 3));
	//printf("%d\n", 4*ADD(2, 3));//若宏定义处无括号则4*2+3=11


/*
	三、指针,就是地址
	1.内存是怎么编号的：
		32位 -- 32跟地址线 -- 物理线 -- 通电 -- 1/0		即电信号转换成数字信号：1和0组成的二进制序列
		00000000 00000000 00000000 00000000
		....
		11111111 11111111 11111111 11111111		共2^32个地址（内存单元）
	2.一个内存单元是多大空间：一个字节					Q:计算
*/
	//int a = 10;//a在内存中需分配4个字节。
	//printf("a的地址：%p\n", &a);//%p专门用来打印地址。
	//int *pa = &a;//pa用来存放地址，在C语言中叫指针变量。
	//// * 说明pa是指针变量，int说明pa指向的对象是int类型的。
	//*pa = 20;// * 解引用操作，*pa就是通过pa中的地址找到a。
	//printf("通过指针修改a的值：%d\n", *pa);
	//++pa;
	//printf("自增后的地址：%p\n",pa);//自增4个字节

	//char ch = 'q';
	//char *pc = &ch;
	//printf("ch的地址：%p\n", pc);
	//printf("ch的下一个地址：%p\n", ++pc);

	////指针的大小是相同的：指针式用来存放地址的，指针需要多大空间取决于地址的存储需要多大空间
	//printf("%d\n", sizeof(char*));
	//printf("%d\n", sizeof(short*));
	//printf("%d\n", sizeof(int*));
	//printf("%d\n", sizeof(long*));
	//printf("%d\n", sizeof(long long*));
	//printf("%d\n", sizeof(float*));
	//printf("%d\n", sizeof(double*));


/*
	四、结构体，可以让C语言创建出新的类型

*/
	//struct Stu s = { "张三",20,99.9 };//创建结构体和初始化
	//printf("1：%s %d %.2lf\n", s.name, s.age, s.score);//结构体.成员变量
	//struct Stu* sp = &s;
	//printf("2：%s %d %.2lf\n", (*sp).name, (*sp).age, (*sp).score);
	//printf("3：%s %d %.2lf\n", sp->name, sp->age, sp->score);// "->"用法：结构体指针->成员名


/*
	五、分支语句和循环语句
	1.分支语句（选择结构）：if		switch
	2.循环语句：while	for		do while
	3.goto语句
*/
	//int age = 30;
	//if (age < 18)
	//	printf("未成年");
	////else if (18 <= age < 26)//有逻辑错误	18<=age -- 1	1<60 - 1
	////	printf("青年");
	//else if (age >= 26 && age < 40)
	//	printf("中年");

	//int a = 0;
	//int b = 2;
	//if (a == 1)
	//	if (b == 2)
	//		printf("QQQ\n");
	//	else
	//		printf("AAA\n");	//else和最近的if匹配!

	int day = 0;
	scanf("%d", &day);
	switch (day)//括号内为整型表达式（字符也行，因为字符底层是ASCLL值）
	{
	case 1://case后为整型常量表达式（字符也行，因为字符底层是ASCLL值）
		printf("周一\n");
		break;//break只能跳出其所在的switch-case语句
	case 2:
		printf("周二\n");
		break;
	case 3:
		printf("周三\n");
		break;
	case 4:
		printf("周四\n");
		break;
	case 5:
		printf("周五\n");
		break;
	case 6:
		printf("周六\n");
		break;
	case 7:
		printf("周日\n");
		break;
	default:
		printf("输入有误");
		break;
	}

	return 0;
}

