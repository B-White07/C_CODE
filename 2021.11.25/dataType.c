#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
//	/*һ����������
//	1.char �ַ���		2.short ������		3.int ����		4.long ������
//	5.long long ����������		6.float �����ȸ�����		7.double ˫���ȸ�����*/
	//printf("sizeof 'char'	  :%d byte\n", sizeof(char));
	//printf("sizeof 'short'	  :%d byte\n", sizeof(short));
	//printf("sizeof 'int'	  :%d byte\n", sizeof(int));
	//printf("sizeof 'long'	  :%d byte\n", sizeof(long));
	//printf("sizeof 'long long':%d byte\n", sizeof(long long));
	//printf("sizeof 'float'	  :%d byte\n", sizeof(float));
	//printf("sizeof 'double'	  :%d byte\n", sizeof(double));
//
//	/*���������ͳ���
//	������
//		�ֲ������������ڴ������ڲ���	ȫ�ֱ����������ڴ������ⲿ��	���ֳ�ͻʱ���ֲ��������ȡ�
//	������
//		1.���泣��		2.const���εĳ����������ɸ��ģ������Ǳ���(�����鶨�����)
//		3.#define����ı�ʶ��������eg��#define MAX 10000
//		4.ö�ٳ��������ڿ���һһ�оٵĳ���
//*/
////int -- %d;		float -- %f;		double -- %lf;		string -- %s;		char -- %c;
//	float x = 3.14;
//	double y = 3.1415926;
//	int z = 132;
//	printf("%f\n", x); //Ĭ�����С�����6λ��'%.xf'����xλ��		
//	printf("%.8lf\n", y); //Ĭ�����С�����6λ��'%.xlf'����xλ��
//	printf("%d\n", z); //�����÷���Ч��
//	scanf("%f %d", &x, &z);//scanf������������1.ʹ��scanf_s;	2.��Ӷ���#define _CRT_SECURE_NO_WARNINGS 1
//							//scanf_s��VS�������ṩ�ģ�����C���Ա�׼�涨�ģ�������ʹ��
//	printf("%f", x + z);
//
//	int arr[10] = { 0 };
	//const int n = 10;//n���Ǳ������������������ʼ��
	//int arr2[n] = { 0 };
//
//	//ö��
	//enum Week
	//{	//���п���ȡֵ����Щ��ö�ٳ���,Ĭ�ϴ�0��ʼ������1�����Ը���ֵ
	//	Monday = 2,
	//	Tuesday,
	//	Wednesday,
	//	Thursday,
	//	Friday,
	//	Saturday,
	//	Sunday
	//};
	//enum Week week = Monday;
	////Monday = Tuesday;
	//printf("%d\n", week);
	//printf("%d\n", Tuesday);
	//printf("%d\n", Friday);
	//printf("%d\n", Sunday);

	/*�����ַ���+ת���ַ�+ע��
	�ַ�������˫������������һ���ַ���������־��\0��eg��"abcd";
	ת���ַ�����Ҫ�����ַ�ʱʹ�á�		\ddd��ddd��ʾ1-3���˽������֡�
										\xdd��dd��ʾ2��ʮ���������֡�
	*/
	//�ַ�����
	//�ַ�����β������\0���ַ�����Ϊ�ַ����Ľ�����־�����������ȡ�
	//char arr1[] = "abc";
	//char arr2[] = { 'a','b','c' };
	//char arr3[] = { 'b' ,'\0'};
	//printf("arr1��Ԫ�أ�%s\n",arr1);
	//printf("arr2��Ԫ�أ�%s\n",arr2); //�ҵ�\0ʱֹͣ
	//printf("arr3��Ԫ�أ�%s\n",arr3); 
	//printf("arr1���ȣ�%d\n", strlen(arr1));
	//printf("arr1���鳤�ȣ�%d\n", sizeof(arr1) / sizeof(arr1[0]));
	//printf("arr2���ȣ�%d\n", strlen(arr2));//���ֵ���ҵ�\0ʱֹͣ��			Q:Ϊʲô���ֵ��һ���ģ���������ֵ��
	//printf("arr2���鳤�ȣ�%d\n", sizeof(arr2) / sizeof(arr2[0]));
	//printf("arr3���ȣ�%d\n", strlen(arr3));
	//printf("arr3���鳤�ȣ�%d\n", sizeof(arr3) / sizeof(arr3[0]));
	//printf("%c\n", '\101');//A��ASCLLΪ65����Ӧ8���ƣ�101			Q:��Ӧ�����˫���ų��ֵ������
	//printf("%c\n",'\x41');
	//printf("%d\n", strlen("c:\test\328\test.c"));

	/*
		�ġ�ѡ����䣬ѭ�����
	*/
	//int line = 0;
	//while (line < 30000)
	//{
	//	printf("go on work hard :%d\n", line);
	//	line++;
	//}
	//if (line == 30000) 
	//{
	//	printf("success!");
	//}

	
	/*
		�塢����
	*/
	//int num1 = 0;
	//int num2 = 0;
	//scanf("%d", &num1);
	//scanf("%d", &num2);
	//printf("%d\n", Add(num1,num2));

	/*
		�������飺һ����ͬԪ�صļ��ϣ�ͨ���±���ʡ�
	*/
	//int arr[5] = {1,2,3,4,5};
	//char ch[5] = { 'a','b','c' };//����ȫ��ʼ����δ��ʼ����ΪĬ��ֵ0.
	//int i = 0;
	//while (i < 5) {
	//	printf("%d ", arr[i]);
	//	printf("%c ", ch[i]);
	//	++i;
	//}

/*
	�ߡ���������������������+	-	*	/	%	��	ע��/��������������һ��ΪС�������ΪС��������ȡ��
				��λ��������>>	<<	��	�ƶ����Ƕ�����λ
				λ��������&��λ��	 |��λ��	 ^��λ���		~��λȡ��	��
				��ֵ��������=	+=	*=	%=	<<=	��	
				��Ŀ��������++	--	��	ǿ������ת��	&	sizeof�ȣ�ע�������Ǻ�����������Ϊ����ʱ����ʡ�����ţ�Ϊ�������Ͳ���ʡ�ԡ�
				��ϵ��������==	!=	>=	<=
				�߼���������&&	||
				������������exp1 ? exp2 : exp3;
				���ű��ʽ��exp1,exp2,exp3,...,expn;�����������μ��㣬���ʽ���Ϊ���һ�����ʽ�Ľ����
				�±����á��������úͽṹ��Ա��������[]���������Ԫ��	()��ʵ���ϣ���������ߵ�Բ���ž��ǲ�����
													.	->

*/
	//float res = 9 / 2;
	//printf("%f", res);//4
	//int a = 2;
	//int b = a << 2;
	//printf("%d", b);

	//int arr[10];
	//printf("%d\n", sizeof(arr));
	//printf("%d\n", sizeof(arr[0]));
	//printf("%d\n", sizeof(arr) / sizeof(arr[0])); //��������Ԫ�ظ�����

	//int a = 0;
	//printf("%d\n",~a);//-1 �������ڴ��д洢���ǲ��롣�����Ķ����Ʊ�ʾ��ԭ�룬���룬���롣��������һ����
	////%d��ӡ��������ԭ�룬�轫�ڴ��еĲ���ת��Ϊ��Ӧ��ԭ���ӡ��
	////00000000000000000000000000000000 -> 11111111111111111111111111111111
	////-1��
	////ԭ�룺10000000000000000000000000000001
	////����(����λ����)��11111111111111111111111111111110
	////���룺11111111111111111111111111111111

	//int a = (int)3.14;
	//printf("%d",a);
	if (1 & 2) {
		printf("true");
	}
	else {
		printf("false");
	}
	//int a = 0;
	//int b = 3;
	//int c = 5;
	//int d = (a = b + 2, c = a - 4, b = c + 2);
	//printf("%d", d);

	return 0;
}

//int Add(int x, int y) {
//	return x + y;
//}