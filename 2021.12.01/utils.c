#define _CRT_SECURE_NO_WARNINGS 1
//��ӡ
#include<stdio.h>
void print(unsigned int num)
{
	if (9 < num)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}

//ջ���
void test(int n)
{
	if (10000 > n)
	{
		test(n + 1);//һֱΪtest()���ٿռ䣬�����stack overflowջ���
	}
}

//ģ��ʵ��strlen()
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

//�Ľ�������������ʱ���������ַ�������
int myStrlen2(char* a)
{
	if ('\0' != *a)
		return 1 + myStrlen1(a + 1);
	else
		return 0;
}

//��n�Ľ׳�
int jieCheng(int n)
{
	if (1 != n)
	{
		return n*jieCheng(n - 1);
	}
	else
		return 1;
}

//���n��쳲�������
int count = 0;
//�ݹ������⣬����Ч�ʺܵ�
int fib1(int n)
{
	//���������쳲�������������Ĵ���
	//����Ч�ʱȽϵ�
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
//�����ķ�����Ч�ʸ�
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

//��ŵ��
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
		num--;
	}
}

//������̨��

//����1/1-1/2+1/3-1/4+...-1/100��ֵ����ӡ���
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
//�Ľ�
double sum2()
{
	double sum = 0;
	int flag = 1;
	for (int i = 1; i <= 100; i++)
	{//��Ҫ����������������һ����С���������С��,����д1.0�������������лᰴ�����ʹ��������ʱ������Ҫ������ʲô����ʲô���͡�
		sum += flag * 1.0 / i;
		flag = -flag;
	}
	return sum;
}

//�����ֵ
int Max(int arr[],int length)
{
	int max = arr[0];//ע�ⲻ�ܽ�max��ֵΪ0���������޷��Ƚ�
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

//�˷���
void chengFaBiao(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%-3d ", j, i, i * j);//%-2d ������ӡ��λ��%2d��Ϊ�Ҷ���
		}
		printf("\n");
	}
}

//�����ַ���
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
//�ݹ�ʵ��
void reverseStr2(char* a)
{
	//int left = 0;
	int len = myStrlen1(a) - 1;
	char tmp = *a;
	*a = *(a + len);
	*(a + len) = '\0';
	//�����ݹ����
	if (myStrlen1(a + 1) >= 2)
	{
		reverseStr2(a + 1);
	}
	*(a + len) = tmp;
}

//дһ���ݹ麯��������һ���Ǹ����������������������֮��
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
//�Ľ�
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

//n��k�η�
double chengFang(int num, int k)
{
	if (k > 0)
		return num * chengFang(num, k - 1);
	else if (k < 0)
		return 1.0 / chengFang(num, -k);
	else
		return 1.0;
}

