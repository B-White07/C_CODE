#define _CRT_SECURE_NO_WARNINGS 1
//计算n的阶乘
#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int mul(int x)
{
	int i = 0;
	int res = 1;
	for (i = x; i > 0; i--)
	{
		res *= i;
	}
	return res;
}

//计算1！+2！+...+10！
int sum1()
{
	int i = 0;
	int j = 0;
	int sum1 = 0;

	for (i = 1; i <= 3; i++)
	{
		int sum2 = 1;//注意初始化的位置，在计算每一次阶乘之前
		for (j = i; j > 0; j--)
		{
			sum2 *= j;	
		}
		sum1 += sum2;
	}
	return sum1;
}

//改进计算1！+2！+...+10！
int sum2()
{
	int i = 0;
	int mul = 1;
	int res = 0;
	for (int i = 1; i <= 3; i++)
	{
		mul *= i;
		res += mul;
	}
	return res;
}

//二分查找
int binSearch(int arr[],int n,int length)
{
	int low = 0;
	//int size = sizeof(arr) / sizeof(arr[0]);//数组作为参数传递过来，实际上传递了一个指针，
	//此时通过sizeof无法获取到数组的长度，而只是指针类型的大小，因此需要将数组的长度作为参数传递过来而非在这里计算
	int high = length - 1;//动态计算数组元素个数
	int index = (low + high) / 2;
	while (n != arr[index])
	{
		if (n < arr[index])
		{
			high = index - 1;
			index = (low + high) / 2;
		}
		else
		{
			low = index + 1;
			index = (low + high) / 2;
		}
	}
	return index;
}

//二分查找改进
int binSearch2(int arr[], int num, int length)
{
	int flag = -1;//没找到返回-1
	int low = 0;
	int high = length - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (num < arr[mid])
		{
			high = mid - 1;
		}
		else if (num > arr[mid])
		{
			low = mid + 1;
		}
		else if (num == arr[mid])
		{ 
			flag = 1;
			return mid;//找到返回索引
		}

	}
	return flag;
}

//显示字符
void moveChars(char arr1[],char arr2[],int len)
{
	int i = 0;
	int j = len - 2;
	int mid = (i + j) / 2;
	for (i = 0, j = len - 2; i <= j ; i++, j--)//注意for循环判断条件的控制逻辑
	{
		arr2[i] = arr1[i];
		arr2[j] = arr1[j];
		Sleep(300);//睡眠1s
		system("cls");//清屏
		printf("%s\n", arr2);	
	}
	return 0;
}

//显示字符2
void moveChars2(char arr1[], char arr2[], int len)
{
	int i = 0;
	int j = len - 2;
	while (i <= j)
	{
		arr2[i] = arr1[i];
		arr2[j] = arr1[j];
		Sleep(1000);
		printf("%s\n", arr2);
		++i;
		--j;
	}
	return 0;
}

//login
int login(char psw[])
{
	int flag = 0;
	//if ("123546" == psw)//错误，字符串比较不能使用==，==比较字符串比的是首字符的地址。
	if (strcmp(psw, "123456") == 0) //应使用strcmp()，相等返回0。（实际上是按位比较acsll值，若出现不一样，ascll大的为大）
	{
		flag = 1;
		return flag;
	}
	else
	{
		return flag;
	}
}

//game
void menu()
{
	printf("******************\n");
	printf("**    1.play    **\n");
	printf("**    2.exit    **\n");
	printf("******************\n");
}
void game()
{
	//1.生成随机数，rand()返回0-32767之间的整数，需要配合srand()使用
	//时间 -- 时间戳
	//srand((unsigned int)time(NULL));//需要在rand之前调用，但是不需要每次都调用，距离太近可能会产生一样的值。
	int random = rand() % 100 + 1;
	//printf("%d\n", random);

	//2.猜数字
	int guess = 0;
	printf("guess please:");
	while (1)
	{
		scanf("%d", &guess);
		if (guess < random)
		{
			printf("less,try again:");
		}
		else if (guess > random)
		{
			printf("more,try again:");
		}
		else
		{
			printf("Congratulations!\n\n");
			break;
		}
	}
}

//最大公约数
int maxPub(int a, int b)
{
	int less = 0;
	(a < b) ? (less = a) : (less = b);
	for (int i = less; i > 0; i--)
	{
		if (a % i == 0 && b % i == 0)
			return i;
	}
	return 0;
}
//辗转相除法
int maxPub2(int a, int b)
{
	//int less = 0;
	//int greater = 0;
	//if (a > b)
	//{
	//	greater = a;
	//	less = b;
	//}
	//else
	//{
	//	greater = b;
	//	less = a;
	//}		//这一段儿没必要
		
	//while (1)
	//{
	//	if ((a % b) != 0)
	//	{
	//		int tmp = a;
	//		a = b;
	//		b = (tmp % b);
	//	}
	//	else
	//	{
	//		return b;
	//	}
	//}

	int tmp = 0;
	while (tmp = (a % b))
	{
		a = b;
		b = tmp;
	}//最小公倍数 = a*b/最大公约数
	return b;
}

//求两个数之间的素数
void suShu(int x, int y)
{
	int high = 0;
	int low = 0;
	(x > y) ? (high = x) : (high = y);
	(high == x) ? (low = y) : (low = x);
	for (int i = low; i <= high; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)//注意int j
		{
			if (i % j == 0)
				break;
		}
		if (i == j)
		{
			printf("%d ", i);
		}
	}
}