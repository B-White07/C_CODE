#define _CRT_SECURE_NO_WARNINGS 1
//打印
#include<stdio.h>
void print(unsigned int num)
{
	if (9 < num)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}

//栈溢出
void test(int n)
{
	if (10000 > n)
	{
		test(n + 1);//一直为test()开辟空间，会造成stack overflow栈溢出
	}
}

//模拟实现strlen()
int myStrlen1(char* a)
{
	int count = 0;
	while ('\0' != *a)
	{
		count++;
		a++;
	}
	return count;
}

//改进，不允许创建临时变量，求字符串长度
int myStrlen2(char* a)
{
	if ('\0' != *a)
		return 1 + myStrlen1(a + 1);
	else
		return 0;
}

//求n的阶乘
int jieCheng(int n)
{
	if (1 != n)
	{
		return n*jieCheng(n - 1);
	}
	else
		return 1;
}

//求第n个斐波那契数
int count = 0;
//递归可以求解，但是效率很低
int fib1(int n)
{
	//计算第三个斐波那契数被计算的次数
	//看出效率比较低
	if (3 == n)
	{
		count++;
	}
	if (2 < n)
	{
		return fib1(n - 1) + fib1(n - 2);
	}
	else
	{
		return 1;
	}

}
//迭代的方法，效率高
int fib2(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (2 < n)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

//汉诺塔
void move(char A,char B)
{
	printf("%c --> %c\n",A,B);
	count++;
}
void hanNuo(char A,char B,char C,int num)
{
	if (1 == num)
	{
		move(A, C);
	}
	else
	{
		hanNuo(A, C, B, num - 1);
		move(A, C);
		hanNuo(B, A, C, num - 1);
	}
}

//青蛙跳台阶

//计算1/1-1/2+1/3-1/4+...-1/100的值，打印结果
double sum1()
{
	double sum = 0.0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum -= 1.0 / i;
		else
			sum += 1.0 / i;
	}
	return sum;
}
//改进
double sum2()
{
	double sum = 0;
	int flag = 1;
	for (int i = 1; i <= 100; i++)
	{//需要两个操作数至少有一个是小数才能算出小数,必须写1.0，否则计算过程中会按照整型处理。定义的时候则不需要，定义什么就是什么类型。
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	return sum;
}

//求最大值
int Max(int arr[],int length)
{
	int max = arr[0];//注意不能将max赋值为0，否则负数无法比较
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

//乘法表
void chengFaBiao(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d ", j, i, i * j);//%-2d 左对齐打印两位，%2d则为右对齐
		}
		printf("\n");
	}
}

//倒序字符串
void reverseStr1(char *a)
{
	int right = myStrlen2(a) - 1;
	int left = 0;
	while (left < right)
	{
		char tmp = *(a + left);
		*(a + left) = *(a + right);
		*(a + right) = tmp;
		left++;
		right--;
	}
}
//递归实现
void reverseStr2(char* a)
{
	//int left = 0;
	int len = myStrlen1(a) - 1;
	char tmp = *a;
	*a = *(a + len);
	*(a + len) = '\0';
	//给出递归出口
	if (myStrlen1(a + 1) >= 2)
	{
		reverseStr2(a + 1);
	}
	*(a + len) = tmp;
}

//写一个递归函数，输入一个非负整数，返回组成他的数字之和
int DigitSum1(int num)
{
	int sum = 0;
	int a = num % 10;
	if (num / 10 != 0)
	{
		sum = a + DigitSum1(num / 10);
	}
	else
	{
		sum += a;
	}
	return sum;
}
//改进
int DigitSum2(int num)
{
	if (9 < num)
	{
		return DigitSum2(num / 10) + num % 10;
	}
	else
	{
		return num;
	}
}

//n的k次方
double chengFang(int num, int k)
{
	if (k > 0)
		return num * chengFang(num, k - 1);
	else if (k < 0)
		return 1.0 / chengFang(num, -k);
	else
		return 1.0;
}

