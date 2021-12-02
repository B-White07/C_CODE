#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//升序冒泡排序：相邻的元素两两比较，可能的话需要交换
void bubbleSort1(int arr[],int length)
{
	//确定趟数
	for (int i = 0; i < length - 1; i++)
	{
		//一趟需要排多少次
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
//改进
void bubbleSort2(int arr[], int length)
{
	//printf("%d", *arr + 1);
	//确定趟数
	for (int i = 0; i < length - 1; i++)
	{
		//一趟需要排多少次
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

