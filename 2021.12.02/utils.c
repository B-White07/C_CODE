#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//����ð���������ڵ�Ԫ�������Ƚϣ����ܵĻ���Ҫ����
void bubbleSort1(int arr[],int length)
{
	//ȷ������
	for (int i = 0; i < length - 1; i++)
	{
		//һ����Ҫ�Ŷ��ٴ�
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
//�Ľ�
void bubbleSort2(int arr[], int length)
{
	//printf("%d", *arr + 1);
	//ȷ������
	for (int i = 0; i < length - 1; i++)
	{
		//һ����Ҫ�Ŷ��ٴ�
		int flag = 1;
		for (int j = 0; j < length - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

