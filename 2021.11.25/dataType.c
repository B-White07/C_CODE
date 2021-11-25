#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
//	/*一、数据类型
//	1.char 字符型		2.short 短整型		3.int 整形		4.long 长整型
//	5.long long 更长的整形		6.float 单精度浮点数		7.double 双精度浮点数*/
	//printf("sizeof 'char'	  :%d byte\n", sizeof(char));
	//printf("sizeof 'short'	  :%d byte\n", sizeof(short));
	//printf("sizeof 'int'	  :%d byte\n", sizeof(int));
	//printf("sizeof 'long'	  :%d byte\n", sizeof(long));
	//printf("sizeof 'long long':%d byte\n", sizeof(long long));
	//printf("sizeof 'float'	  :%d byte\n", sizeof(float));
	//printf("sizeof 'double'	  :%d byte\n", sizeof(double));
//
//	/*二、变量和常量
//	变量：
//		局部变量：定义在大括号内部；	全局变量：定义在大括号外部。	名字冲突时，局部变量优先。
//	常量：
//		1.字面常量		2.const修饰的常变量，不可更改，但仍是变量(用数组定义测试)
//		3.#define定义的标识符常量，eg：#define MAX 10000
//		4.枚举常量，用于可以一一列举的常量
//*/
////int -- %d;		float -- %f;		double -- %lf;		string -- %s;		char -- %c;
//	float x = 3.14;
//	double y = 3.1415926;
//	int z = 132;
//	printf("%f\n", x); //默认输出小数点后6位，'%.xf'保留x位。		
//	printf("%.8lf\n", y); //默认输出小数点后6位，'%.xlf'保留x位。
//	printf("%d\n", z); //上述用法无效。
//	scanf("%f %d", &x, &z);//scanf报错解决方法：1.使用scanf_s;	2.添加定义#define _CRT_SECURE_NO_WARNINGS 1
//							//scanf_s是VS编译器提供的，不是C语言标准规定的，不建议使用
//	printf("%f", x + z);
//
//	int arr[10] = { 0 };
	//const int n = 10;//n仍是变量，不可用于数组初始化
	//int arr2[n] = { 0 };
//
//	//枚举
	//enum Week
	//{	//所有可能取值，这些是枚举常量,默认从0开始，递增1，可以赋初值
	//	Monday = 2,
	//	Tuesday,
	//	Wednesday,
	//	Thursday,
	//	Friday,
	//	Saturday,
	//	Sunday
	//};
	//enum Week week = Monday;
	////Monday = Tuesday;
	//printf("%d\n", week);
	//printf("%d\n", Tuesday);
	//printf("%d\n", Friday);
	//printf("%d\n", Sunday);

	/*三、字符串+转义字符+注释
	字符串：用双引号括起来的一串字符，结束标志：\0。eg："abcd";
	转义字符：需要特殊字符时使用。		\ddd：ddd表示1-3个八进制数字。
										\xdd：dd表示2个十六进制数字。
	*/
	//字符数组
	//字符串结尾隐藏了\0的字符，作为字符串的结束标志，不算做长度。
	//char arr1[] = "abc";
	//char arr2[] = { 'a','b','c' };
	//char arr3[] = { 'b' ,'\0'};
	//printf("arr1中元素：%s\n",arr1);
	//printf("arr2中元素：%s\n",arr2); //找到\0时停止
	//printf("arr3中元素：%s\n",arr3); 
	//printf("arr1长度：%d\n", strlen(arr1));
	//printf("arr1数组长度：%d\n", sizeof(arr1) / sizeof(arr1[0]));
	//printf("arr2长度：%d\n", strlen(arr2));//随机值，找到\0时停止。			Q:为什么随机值是一样的，真的是随机值吗？
	//printf("arr2数组长度：%d\n", sizeof(arr2) / sizeof(arr2[0]));
	//printf("arr3长度：%d\n", strlen(arr3));
	//printf("arr3数组长度：%d\n", sizeof(arr3) / sizeof(arr3[0]));
	//printf("%c\n", '\101');//A的ASCLL为65，对应8进制：101			Q:对应后边是双引号出现的情况？
	//printf("%c\n",'\x41');
	//printf("%d\n", strlen("c:\test\328\test.c"));

	/*
		四、选择语句，循环语句
	*/
	//int line = 0;
	//while (line < 30000)
	//{
	//	printf("go on work hard :%d\n", line);
	//	line++;
	//}
	//if (line == 30000) 
	//{
	//	printf("success!");
	//}

	
	/*
		五、函数
	*/
	//int num1 = 0;
	//int num2 = 0;
	//scanf("%d", &num1);
	//scanf("%d", &num2);
	//printf("%d\n", Add(num1,num2));

	/*
		六、数组：一组相同元素的集合，通过下标访问。
	*/
	//int arr[5] = {1,2,3,4,5};
	//char ch[5] = { 'a','b','c' };//不完全初始化，未初始化项为默认值0.
	//int i = 0;
	//while (i < 5) {
	//	printf("%d ", arr[i]);
	//	printf("%c ", ch[i]);
	//	++i;
	//}

/*
	七、操作符：算术操作符：+	-	*	/	%	等	注意/，操作数至少有一个为小数，结果为小数，否则取商
				移位操作符：>>	<<	等	移动的是二进制位
				位操作符：&按位与	 |按位或	 ^按位异或		~按位取反	等
				赋值操作符：=	+=	*=	%=	<<=	等	
				单目操作符：++	--	！	强制类型转换	&	sizeof等，注意他不是函数，括号内为变量时，可省略括号，为数据类型不可省略。
				关系操作符：==	!=	>=	<=
				逻辑操作符：&&	||
				条件操作符：exp1 ? exp2 : exp3;
				逗号表达式：exp1,exp2,exp3,...,expn;从左向右依次计算，表达式结果为最后一个表达式的结果。
				下标引用、函数调用和结构成员操作符：[]：数组访问元素	()：实际上，函数名后边的圆括号就是操作符
													.	->

*/
	//float res = 9 / 2;
	//printf("%f", res);//4
	//int a = 2;
	//int b = a << 2;
	//printf("%d", b);

	//int arr[10];
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr[0]));
	//printf("%d\n", sizeof(arr) / sizeof(arr[0])); //计算数组元素个数。

	//int a = 0;
	//printf("%d\n",~a);//-1 整数在内存中存储的是补码。整数的二进制表示：原码，反码，补码。正数三个一样。
	////%d打印出来的是原码，需将内存中的补码转换为对应的原码打印。
	////00000000000000000000000000000000 -> 11111111111111111111111111111111
	////-1：
	////原码：10000000000000000000000000000001
	////反码(符号位不变)：11111111111111111111111111111110
	////补码：11111111111111111111111111111111

	//int a = (int)3.14;
	//printf("%d",a);
	if (1 & 2) {
		printf("true");
	}
	else {
		printf("false");
	}
	//int a = 0;
	//int b = 3;
	//int c = 5;
	//int d = (a = b + 2, c = a - 4, b = c + 2);
	//printf("%d", d);

	return 0;
}

//int Add(int x, int y) {
//	return x + y;
//}