#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

void print1(int arr[3][5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
void print2(int (*p)[5], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%d ", *(*(p + i) + j));
		printf("\n");
	}
}

//计算Sn = a + aa + aaa + aaaa + aaaaa的前n项之和，不考虑溢出
int Sn(int a, int n)
{
	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = res * 10 + a;
		sum += res;
	}
	return sum;
}

//打印1-100000之间的自幂数
void isZiMi()
{
	for (int i = 0; i < 100000; i++)
	{
		int tmp1 = i;
		int bit = 1;
		while (tmp1 / 10)//判断多少位
		{
			bit++;
			tmp1 /= 10;
		}

		int sum = 0;
		int tmp2 = i;
		for (int j = 0; j < bit; j++)//每一位求和
		{
			sum += pow(tmp2 % 10, bit);
			tmp2 /= 10;
		}

		if (sum == i)//判断输出
			printf("%d ", i);
	}
}

//1瓶汽水1元，2个空瓶子可以换一瓶汽水，20元可以买多少汽水
int drink(int money)
{
	int drink = money;
	int empty = drink;
	int total = drink;
	while (empty >= 2)
	{
		drink = empty / 2;
		empty = drink + empty % 2;
		total += drink;
	}
	return total;
}

//将数组中奇数放在前，偶数放在后
void change(int arr[], int len)
{
	int* left = arr;
	int* right = arr + len - 1;
	while (left < right)
	{
		while (1 == (*left) % 2 && (left < right))//判断left和right防止越界
		{
			left++;
		}
		while (0 == (*right) % 2 && (left < right))
		{
			right--;
		}
		int tmp = *left;
		*left = *right;
		*right = tmp;
	}
}
void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

//杨辉三角
void yangHui()
{
	int arr[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0 || i == j)
				arr[i][j] = 1;
			//if (i >= 2 && j >= 1)
			else
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%-3d ", arr[i][j]);
		}
		printf("\n");
	}
}

//三个真话一个假话
//A：不是我		B：是C		C：是D		D：C在胡说
char whoIsKiller()
{
	char killer = 'A';
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if (3 == (killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D'))
			return killer;
	}
}

//5位运动员参加了10米台跳水比赛，有人让他们 预测比赛结果
//A：B第二，我第三；
//B：我第二，E第四；
//C：我第一，D第二；
//D：C最后，我第三；
//E：我第四，A第一。
//四人中每人说对了一半，请确定名次
void order()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if((b==2)^(a==3)
							&& (b == 2) ^ (e == 4)
							&& (c == 1) ^ (d == 2)
							&& (c == 5) ^ (d == 3)
							&& (e == 4) ^ (a == 1))
							if(120 == a*b*c*d*e)
								printf("a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
					}
				}
			}
		}
	}

}
