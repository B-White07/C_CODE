#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"
//ģ��ʵ��strcpy
int main() 
{
	//const���α�������������ͱ���Ϊ�����������ܱ��޸ģ����Ǳ����ϻ��Ǳ�����
	//const int num = 10;
	//int n = 100;
	////num = 20;//err
	////int* p = &num;//�����Ϳ��Ը���num��ֵ
	//const int* p = &num;//const�������*��ߣ����ε���*p����ʾָ��ָ������ݲ���ͨ��ָ�����ı䣬����ָ����������ǿ����޸ĵ�
	////*p = 20;
	//p = &n;//*p�����޸ģ�����p�Կ����޸�

	//const int num = 10;
	//int n = 100;
	////num = 20;//err
	////int* p = &num;//�����Ϳ��Ը���num��ֵ
	//int* const p = &num;//const�������*�ұߣ����ε���ָ�����p����ʾָ��������ܱ��ı䣬����ָ��ָ������ݿ��Ա��޸�
	//*p = 20;//*p���޸ģ�����p�������޸ġ�
	//p = &n;
	//printf("%d", num);
	//int const* const p = &num;//ָ�뱾���ָ��ָ��ı����������Ը�

	//char arr1[20] = "xxxxxxxxxx";
	//char arr2[] = "hello";
	//printf("%s\n", myStrcpy2(arr1, arr2));//��ʽ����
	//printf("%d\n", myStrlen(arr1));

	//��̳�������
	//	1.�����ʹ���	2.�����Դ���(�޷��������ⲿ���ţ���ʵ�������ֲ�һ������û�ж���÷���)	
	//	3.����ʱ����

	//1�ĸ���
	//int n = -1;
	//printf("%d", numOf1(n));

	//2��n�η�
	//if (1 == ncifang(127))
	//	printf("Yes");
	//else
	//	printf("No");

	//��ͬλ�ĸ���
	//printf("%d",dif(22, 33));

	//��żλ
	//jiOu(10);

	//��
	//���Ա���û���������������ֻ�ǹ涨���﷨���򡣿⺯��������C����
	//char arr[100] = { 0 };
	//gets(arr);
	//char* start = arr;
	//char* end = start + myStrlen(arr) - 1;
	//reverse(start, end);
	//reverseWord(arr);
	//printf("%s", arr);



	return 0;
}