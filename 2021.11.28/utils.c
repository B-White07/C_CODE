#define _CRT_SECURE_NO_WARNINGS 1
//����n�Ľ׳�
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

//����1��+2��+...+10��
int sum1()
{
	int i = 0;
	int j = 0;
	int sum1 = 0;

	for (i = 1; i <= 3; i++)
	{
		int sum2 = 1;//ע���ʼ����λ�ã��ڼ���ÿһ�ν׳�֮ǰ
		for (j = i; j > 0; j--)
		{
			sum2 *= j;	
		}
		sum1 += sum2;
	}
	return sum1;
}

//�Ľ�����1��+2��+...+10��
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

//���ֲ���
int binSearch(int arr[],int n,int length)
{
	int low = 0;
	//int size = sizeof(arr) / sizeof(arr[0]);//������Ϊ�������ݹ�����ʵ���ϴ�����һ��ָ�룬
	//��ʱͨ��sizeof�޷���ȡ������ĳ��ȣ���ֻ��ָ�����͵Ĵ�С�������Ҫ������ĳ�����Ϊ�������ݹ����������������
	int high = length - 1;//��̬��������Ԫ�ظ���
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

//���ֲ��ҸĽ�
int binSearch2(int arr[], int num, int length)
{
	int flag = -1;//û�ҵ�����-1
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
			return mid;//�ҵ���������
		}

	}
	return flag;
}

//��ʾ�ַ�
void moveChars(char arr1[],char arr2[],int len)
{
	int i = 0;
	int j = len - 2;
	int mid = (i + j) / 2;
	for (i = 0, j = len - 2; i <= j ; i++, j--)//ע��forѭ���ж������Ŀ����߼�
	{
		arr2[i] = arr1[i];
		arr2[j] = arr1[j];
		Sleep(300);//˯��1s
		system("cls");//����
		printf("%s\n", arr2);	
	}
	return 0;
}

//��ʾ�ַ�2
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
	//if ("123546" == psw)//�����ַ����Ƚϲ���ʹ��==��==�Ƚ��ַ����ȵ������ַ��ĵ�ַ��
	if (strcmp(psw, "123456") == 0) //Ӧʹ��strcmp()����ȷ���0����ʵ�����ǰ�λ�Ƚ�acsllֵ�������ֲ�һ����ascll���Ϊ��
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
	//1.�����������rand()����0-32767֮�����������Ҫ���srand()ʹ��
	//ʱ�� -- ʱ���
	//srand((unsigned int)time(NULL));//��Ҫ��rand֮ǰ���ã����ǲ���Ҫÿ�ζ����ã�����̫�����ܻ����һ����ֵ��
	int random = rand() % 100 + 1;
	//printf("%d\n", random);

	//2.������
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

//���Լ��
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
//շת�����
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
	//}		//��һ�ζ�û��Ҫ
		
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
	}//��С������ = a*b/���Լ��
	return b;
}

//��������֮�������
void suShu(int x, int y)
{
	int high = 0;
	int low = 0;
	(x > y) ? (high = x) : (high = y);
	(high == x) ? (low = y) : (low = x);
	for (int i = low; i <= high; i++)
	{
		int j = 0;
		for (j = 2; j <= sqrt(i); j++)//ע��int j
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