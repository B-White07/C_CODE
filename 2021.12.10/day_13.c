#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
int main()
{
	/*
		ָ��
		1.�ַ�ָ��		2.ָ������		3.����ָ��		4.���鴫�κ�ָ�봫��		5.����ָ��
		6.����ָ������	7.ָ����ָ�������ָ��		8.�ص�����		9.ָ�������������Ľ���
	*/
	//4.���鴫�κ�ָ�봫��
	//	3.һ��ָ�봫��
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* p = arr;
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//print(p, sz);

	//char ch = 'w';
	//char* p1 = &ch;
	//test(&ch);
	//test(p1);
	//	4.����ָ�봫��
	//int a = 10;
	//int* pa = &a;//pa��һ��ָ��
	//int* *ppa = &pa;//ppa�Ƕ���ָ��
	////���ݶ���ָ��
	//test2(ppa);//������ָ��
	//test2(&pa);//��һ��ָ������ĵ�ַ
	//int* arr[10] = { 0 };
	//test2(arr);//��һ��ָ������
	//printf("%d", a);


	//5.����ָ�룺ָ������ָ�룬����ź�����ַ��ָ��		&��������ȡ�ľ��Ǻ����ĵ�ַ
	//������ != &������			������ == &������
	//void (*pt)(char*) = &test3;
	//printf("%p\n", &Add);
	//printf("%p\n", Add);
	//int (*pf)(int, int) = &Add;//pf����һ������ָ�����
	//int (*pf)(int, int) = Add;//Add <==> pf
	//printf("%d\n",(**pf)(3, 5));//�Ժ���ָ������������ú�������ʵ*�����壬д��������		1
	//printf("%d\n",Add(3, 5));	//		2
	//printf("%d\n",pf(3, 5)); //�����еȼ�			3			1 <==> 2 <==> 3

	//��
	//1.
	//(*(void(*)())0)();//����0��ַ���ĺ������ú����޲Σ�����������void
	////void(*)()			 - ����ָ������
	////(void(*)())0		 - ��0ǿ������ת��Ϊ������ַ
	////*(void(*)())0		 - ��0��ַ���н����ò���
	////(*(void(*)())0)()  - ����0��ַ���ĺ���
	////2.
	//void (*signal(int, void(*)(int)))(int);
	////signal�Ⱥ�()��ϣ�˵��signal�Ǻ�����
	////signal�����ĵ�һ��������������int�ͣ��ڶ��������������Ǻ���ָ�룬��ָ��ָ��һ������Ϊint����������Ϊvoid�ĺ���
	////signal�����ķ���������һ������ָ�룬��ָ��ָ��һ������Ϊint����������Ϊvoid�ĺ���
	////signal��һ������������
	////����ʱ��ȥ���������Ͳ�����Ϊ��������		����ȥ�����ֺ�[]ʣ�µļ�Ϊ����
	////void(*)(int) signal(int, void(*)(int));	//����д��������������������ֵΪ����ָ�룬��*����ͺ�����д��һ��
	////typedef �����ͽ����ض���
	//typedef void (*pfun_t)(int);//�Ժ���ָ������������Ϊpfun_t��ע��pfun_t�����*д��һ�������typedef void (*)(int) pfun_t
	//pfun_t signal(int, pfun_t);


	////6.����ָ�����飺��ź���ָ�������
	//int (*pf1)(int, int) = Add;
	//int (*pf2)(int, int) = Sub;
	//int (*pfArr[2])(int, int) = { pf1,Sub };//pfArrΪ����ָ������

	//���������������͵ļӼ��˳�
	//int input = 0;
	//do
	//{
	//	menu();
	//	scanf("%d", &input);
	//	//ת�Ʊ� - ����ָ������
	//	int (*pArr[4])(int, int) = { Add,Sub,Mul,Div };

	//	if ((input-1) >= 0 && (input-1) <= 3)
	//	{
	//		int x = 0;
	//		int y = 0;
	//		printf("������������������\n");
	//		scanf("%d %d", &x, &y);
	//		printf("%d\n", pArr[input - 1](x, y));
	//	}
	//	else if (input == 0)
	//	{
	//		printf("�����˳�\n");
	//		break;
	//	}
	//	else
	//		printf("��������������ѡ��\n");
	//} while (input);


	//7.ָ����ָ�������ָ��
	//int(*p)(int, int);//����ָ��
	//int(*pArr[10])(int, int);//����ָ�������
	//int(*(*pa)[10])(int, int);//pa��ָ����ָ�������ָ��

	//8.�ص��������ص���������һ��ͨ������ָ����õĺ����������Ѻ�����ָ��(��ַ)��Ϊ�������ݸ���һ��������
	//�����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص��������ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�
	//������������ʱ�������һ�����õģ����ڶԸ��¼�������������Ӧ��
	//�ص�����ʵ�ּ�����
	//int input = 0;
	//do
	//{
	//	menu();
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		printf("%d\n",Cacl(Add));
	//		break;
	//	case 2:
	//		printf("%d\n", Cacl(Sub));
	//		break;
	//	case 3:
	//		printf("%d\n", Cacl(Mul));
	//		break;
	//	case 4:
	//		printf("%d\n", Cacl(Div));
	//		break;
	//	case 0:
	//		printf("�����˳�\n");
	//		break;
	//	default:
	//		printf("��������Чѡ��\n");
	//		break;
	//	}
	//} while (input);



	return 0;
}