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
	////void(*)(int) signal(int, void(*)(int));	//����д������������������ֵΪ����ָ�룬��*����ͺ�����д��һ��
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

	//qsort������ʹ��:�������򣬿������������͵�����
	//1.ð������
	//int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//print(arr, sz);
	//bubble_sort(arr, sz);
	//print(arr, sz);

	//2.qsort()
	//void qsort( void *base, size_t num, size_t width, int (*compare )(const void *elem1, const void *elem2 ) );
	//4��������
	//	1.base�д�ŵ��Ǵ����������еĵ�һ������ĵ�ַ��void* ���͵�ָ����Խ����������͵�ָ��
	//	2.num������Ԫ�صĸ���
	//	3.size��ÿ��Ԫ�صĴ�С����λ�ֽ�
	//	4.����ָ�룬�ú��������Ƚϴ����������е�����Ԫ�أ�����>0����һ��Ԫ�ش��ڵڶ�����=0����ȣ�<0��һ��Ԫ��С�ڵڶ���
	//test_int();
	//test_struct();
	//ģ��qsortʵ���������͵�ð������
	//test_struct2();


	//9.ָ�������������Ľ���
	//	sizeof(������)�������������������� �� &������ �ֱ��ǽ�����������Ĵ�С �� ȡ����������ĵ�ַ��
	//	����֮�⣬����������������Ԫ�صĵ�ַ
	//int a[] = { 1,2,3,4 };
	//printf("%d\n", sizeof(a));			//	16
	//printf("%d\n", sizeof(a + 0));		//	4	a+0�ǵ�һ��Ԫ�صĵ�ַ
	//printf("%d\n", sizeof(*a));			//	4	a��1�ĵ�ַ��*a��ʾ1
	//printf("%d\n", sizeof(a + 1));		//	4	a+1�ǵڶ���Ԫ�صĵ�ַ
	//printf("%d\n", sizeof(a[1]));		//	4	
	//printf("%d\n", sizeof(&a));			//	4
	//printf("%d\n", sizeof(*&a));		//	16	*&��ʵ�໥������
	//printf("%d\n", sizeof(&a + 1));		//	4	�����ߵĿռ�ĵ�ַ�����ǵ�ַ	*(&a + 1)�ܷ���һ������Ĵ�С
	//printf("%d\n", sizeof(&a[0]));		//	4	����ָ��������ǵ�ַ
	//printf("%d\n", sizeof(&a[0] + 1));	//	4	����ָ��������ǵ�ַ

	//�ַ�����
	//char arr[] = { 'a','b','c','d','e','f' };
	//printf("%d\n", sizeof(arr));			// 6
	//printf("%d\n", sizeof(arr + 0));		// 4
	//printf("%d\n", sizeof(*arr));			// 1
	//printf("%d\n", sizeof(arr[1]));			// 1
	//printf("%d\n", sizeof(&arr));			// 4
	//printf("%d\n", sizeof(&arr + 1));		// 4
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4
	//printf("%d\n", strlen(arr));			// ���
	//printf("%d\n", strlen(arr + 0));		// ���
	//printf("%d\n", strlen(*arr));			// err	��97���ɵ�ַ���������˴���
	//printf("%d\n", strlen(arr[1]));			// err	��98���ɵ�ַ���������˴���
	//printf("%d\n", strlen(&arr));			// ���	char(*)[6] -> char *
	//printf("%d\n", strlen(&arr + 1));		// ��� - 6
	//printf("%d\n", strlen(&arr[0] + 1));	// ��� - 1
	//	strlen���յĲ������ַ�ָ��

	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));			// 7
	//printf("%d\n", sizeof(arr + 0));		// 4
	//printf("%d\n", sizeof(*arr));			// 1
	//printf("%d\n", sizeof(arr[1]));		// 1
	//printf("%d\n", sizeof(&arr));			// 4	char(*)[7]
	//printf("%d\n", sizeof(&arr + 1));		// 4
	//printf("%d\n", sizeof(&arr[0] + 1));	// 4
	//printf("%d\n", strlen(arr));			// 6
	//printf("%d\n", strlen(arr + 0));		// 6
	//printf("%d\n", strlen(*arr));			// err
	//printf("%d\n", strlen(arr[1]));			// err
	//printf("%d\n", strlen(&arr));			// 6
	//printf("%d\n", strlen(&arr + 1));		// ���
	//printf("%d\n", strlen(&arr[0] + 1));	// 5

	//char* p = "abcdef";//pָ���׵�ַ
	//printf("%d\n", sizeof(p));				// 4
	//printf("%d\n", sizeof(p + 1));			// 4
	//printf("%d\n", sizeof(*p));				// 1
	//printf("%d\n", sizeof(p[0]));			// 1		p[0] <=> *(p + 0)
	//printf("%d\n", sizeof(&p));				// 4
	//printf("%d\n", sizeof(&p + 1));			// 4
	//printf("%d\n", sizeof(&p[0] + 1));		// 4
	//printf("%d\n", strlen(p));			// 6
	//printf("%d\n", strlen(p + 1));		// 5
	//printf("%d\n", strlen(*p));			// err *p��a�����ݵ���a��ASCLL��ֵ������
	//printf("%d\n", strlen(p[0]));		// err ���ݵ���a��ASCLL��ֵ������
	//printf("%d\n", strlen(&p));			// ���1
	//printf("%d\n", strlen(&p + 1));		// ���2
	//printf("%d\n", strlen(&p[0] + 1));	// 5	+1�Ӷ��٣���ȡ��������ʲô����

	//int a[3][4] = { 0 };
	//printf("%d\n", sizeof(a));				// 48
	//printf("%d\n", sizeof(a[0][0]));		// 4
	//printf("%d\n", sizeof(a[0]));			// 16	a[0]�������Ϊ��һ����������������ǵ�һ������Ĵ�С����Ϊsizeof������ֻ��������
	//printf("%d\n", sizeof(a[0] + 1));		// 4	������a[0]�ǵ����������ڣ�Ҳû��&����ʾ������Ԫ�ص�ַ������һ�еڶ���Ԫ�صĵ�ַ��+1����һ�����ͼ�a[0] + 1 ��ʾa[0][1]
	//printf("%d\n", sizeof(*(a[0] + 1)));	// 4	*(a[0] + 1))�ǵ�һ�еڶ���Ԫ��
	//printf("%d\n", sizeof(a + 1));			// 4	a�Ƕ�ά����������û��&���ߵ�����sizeof()�ڣ����aΪ��Ԫ�ص�ַ����ά�������Ԫ���ǵ�һ�У�+1����һ�У�Ϊ�ڶ��еĵ�ַ
	//printf("%d\n", sizeof(*(a + 1)));		// 16	(a + 1)Ϊ�ڶ��еĵ�ַ���������ҵ����������ڶ���		*(a + 1) <=> a[1]
	//printf("%d\n", sizeof(&a[0] + 1));		// 4	������һ�еĵ�ַ + 1 = �����ڶ��еĵ�ַ
	//printf("%d\n", sizeof(*(&a[0] + 1)));	// 16	
	//printf("%d\n", sizeof(*a));				// 16	��λ����ĵ�һ��Ԫ��Ϊ��һ�е�һά����		*a <=> *(a + 0) <=> a[0]
	//printf("%d\n", sizeof(a[3]));			// 16	���ʽ���������ԣ�ֵ���Ժ���������	a[3]��������int [4]
	//										//������Ȼû�з���a[3]�����ǿ���֪���������ͣ�Ҳ��֪�������Ĵ�С��a[3] <=> *(a + 3)
	//sizeof(���ʽ)�����ʽ��������㣬���Բ��ᷢ��Խ�����������Ǳ��ʽ�����������֪���ġ�

	//1.
	//int a[5] = { 1,2,3,4,5 };
	//int* ptr = (int*)(&a + 1);
	//printf("%d,%d", *(a + 1), *(ptr - 1));	//	2	5

	//2.ָ�����;�����ָ�������
	//printf("%p\n", p);
	//printf("%p\n", p + 0x1);					//����һ���ṹ���С��0x100000 + 0x000014 = 0x100014
	//printf("%p\n", (unsigned long)p + 0x1);		//��������+���ͣ�0x100000 + 0x1 = 0x100001
	//printf("%p\n", (unsigned int*)p + 0x1);		//����һ�����ʹ�С��0x100000 + 0x000004 = 0x100004
	//��16������Ҳֻ����ͨ�ӷ����ѣ������Ǽӵ�ַ����ַ+��ַ��û������ģ����ָ��+1���ƫ��������ȡ����ָ�������

	//3.
	//int a[4] = { 1,2,3,4 };
	//int* ptr1 = (int*)(&a + 1);	
	//int* ptr2 = (int*)((int)a + 1);
	//printf("%#x,%#x", ptr1[-1], *ptr2);// 4	2000000

	//4.
	//int a[3][2] = { (0,1),(2,3),(4,5) };//���ű��ʽ	1	3	5
	//int* p;
	//p = a[0];
	//printf("%d",p[0]);	// 1

	//5.
	//int a[5][5];// 0 0 0 0 0	0 0 0 0 0	0 0 0 0 0	0 0 0 0 0	0 0 0 0 0
	//int(*p)[4];	// 0 0 0 0		0 0 0 0		0 0 0 0		0 0 0 0		0 0 0 0
	//p = a;		// a:int(*)[5]
	//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//	FFFFFFFC,-4
	//��ַ - ��ַ�õ�������ַ�м��Ԫ�صĸ���
	//-4: 10000000 00000000 00000000 00000100 --> 11111111 11111111 11111111 11111011 --> 11111111 11111111 11111111 11111100
	// --> FF FF FF FC

	//6.
	//int aa[2][5] = { 1,2,3,4,5,6,7,8,9,10 };
	//int* ptr1 = (int*)(&aa + 1);
	//int* ptr2 = (int*)(*(aa + 1));//*(aa+1) <=>aa[1]�����ڶ�����Ԫ�صĵ�ַ����6�ĵ�ַ��
	////������ô��⣬aa��һ������ָ�룬������Ϊint(*)[5]����������õõ���һ������aa[0]�����������������Ԫ�صĵ�ַ����Ϊ��int*
	////���Կ�������ʵptr2����Ҫǿ������ת��
	//printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));//	10,5

	//7.
	//char* a[] = { "study","at","fuda" };//a��һ��ָ�����飬ÿ��Ԫ�ض���char*��Ϊ�ַ�����Ԫ�صĵ�ַ
	//char** pa = a;//paָ��a��Ԫ�أ�a��Ԫ������Ϊchar*
	//pa++;
	//printf("%s\n", *pa);//at

	//8.
	//char* c[] = { "ENTER","NEW","POINT","FIRST" };
	//char** cp[] = { c + 3,c + 2,c + 1,c };
	//char*** cpp = cp;
	//printf("%s\n", **++cpp);		//POINT
	//printf("%s\n", *--* ++cpp + 3);	//ER	ע��--�ǲ�����˭������
	//printf("%s\n", *cpp[-2] + 3);	//ST
	//printf("%s\n", cpp[-1][-1] + 1);//EW


	return 0;
}
