#define _CRT_SECURE_NO_WARNINGS 1
//#define MAX 1000
//#define M 1

//define�����
/*#define ADD(X,Y) ((X)+(Y))	*/	//ע������ţ�ADD�ǽ����ʽX��Yֱ���滻�����ô���
#include<stdio.h>

//typedef unsigned int u_int;

//void test() {
//	static int a = 1;//�����١�
//	a++;
//	printf("%d ", a);
//}

//extern �����ⲿ����
//extern int g_val;

//��������
//extern int Add(int, int);

//struct Stu
//{
//	char name[20];//��Ա
//	int age;
//	double score;
//};
//
//struct Book
//{
//	char name[20];
//	float price;
//	char id[30];
//};

int main()
{
/*
	һ���ؼ��֣�1.C�����ṩ�ģ������Զ���
				2.�ؼ��ֲ�������������
				3.�����ؼ��֣�
					1.auto(�Զ����������٣��ֲ�����ǰ���У�ֻ�Ǳ�ʡ��)	2.break		3.case		4.const		5.continue	
					6.default	7.do	8.else		9.enum	10.extern(�����ⲿ����)	11.for		12.goto		13.if		
					14.register(�Ĵ����ؼ���)	15.return	16.signed(�з���)	17.unsigned(�޷���)	18.static(��̬)	
					19.struct(�ṹ��)	20.switch	21.typedef(����������)	22.union(������/������)	23.sizeof	24.void		
					25.volatile		26.while
					define��include���ǹؼ��֣���Ԥ����ָ��
				����������ݿ��Դ洢����1.�Ĵ���	2.���ٻ���	3.�ڴ�	4.Ӳ��	5.���̡�������ν��ͣ��ٶ�Խ�����ռ�Խ��
*/
	//����Ƶ����ʹ�õ����ݣ�����ڼĴ����У�����Ч�ʡ���ǰ��������жϴӶ��Զ��ŵ��Ĵ����У���˴˹ؼ������岻��
	//register int num = 100;//����numֵ����ڼĴ�����

	//typedef
	//unsigned int num = 100;
	//u_int num2 = 100;

	//static	1.���ξֲ�����		2.����ȫ�ֱ���		3.���κ���
	//1.static���ξֲ��������ı��˾ֲ��������������ڣ��������Ǹı��˱����Ĵ洢���ͣ�����̬������ȫ�ֱ�����������һ�������򲻽����Ͳ����١�
	//ע��ֻ���޸����������ڣ����ǲ��ɸ��ġ�
	//�ڴ滮��Ϊ��������1.ջ������žֲ������������Ĳ���		2.��������̬�ڴ����		��̬����ȫ�ֱ�����static���εľ�̬����
	//int i = 0;
	//while (i < 10) {
	//	test();
	//	i++;
	//}

	//2.static����ȫ�ֱ�����ʹ�ô�ȫ�ֱ���ֻ�����Լ����ڵ�Դ�ļ��ڲ�����ʹ�ã�����Դ�ļ�����ʹ�á�
	//ȫ�ֱ���������Դ�ļ��ڲ����Ա�ʹ�ã�����Ϊ������ⲿ�������ԣ���static���κ󣬾ͱ�����ڲ��������ԣ�����Դ�ļ��Ͳ������ӵ������̬��ȫ�ֱ����ˡ�
	//printf("%d\n",g_val);

	//3.static���κ�����ʹ�ú���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ�ã�����������Դ�ļ��ڲ�ʹ�á�
	//�����ϣ�static�ǽ��������ⲿ�������Ա�����ڲ��������ԣ�ͬstatic����ȫ�ֱ�������
	//int a = 10;
	//int b = 20;
	//printf("%d\n",Add(a,b));


/*
	����#define���峣���ͺ�
	define��һ��Ԥ����ָ�1.define������ų���	#define MAX 10000
							2.define����꣬���滻��
*/
	////printf("%d", MAX);
	//printf("%d\n", ADD(2, 3));
	//printf("%d\n", 4*ADD(2, 3));//���궨�崦��������4*2+3=11


/*
	����ָ��,���ǵ�ַ
	1.�ڴ�����ô��ŵģ�
		32λ -- 32����ַ�� -- ������ -- ͨ�� -- 1/0		�����ź�ת���������źţ�1��0��ɵĶ���������
		00000000 00000000 00000000 00000000
		....
		11111111 11111111 11111111 11111111		��2^32����ַ���ڴ浥Ԫ��
	2.һ���ڴ浥Ԫ�Ƕ��ռ䣺һ���ֽ�					Q:����
*/
	//int a = 10;//a���ڴ��������4���ֽڡ�
	//printf("a�ĵ�ַ��%p\n", &a);//%pר��������ӡ��ַ��
	//int *pa = &a;//pa������ŵ�ַ����C�����н�ָ�������
	//// * ˵��pa��ָ�������int˵��paָ��Ķ�����int���͵ġ�
	//*pa = 20;// * �����ò�����*pa����ͨ��pa�еĵ�ַ�ҵ�a��
	//printf("ͨ��ָ���޸�a��ֵ��%d\n", *pa);
	//++pa;
	//printf("������ĵ�ַ��%p\n",pa);//����4���ֽ�

	//char ch = 'q';
	//char *pc = &ch;
	//printf("ch�ĵ�ַ��%p\n", pc);
	//printf("ch����һ����ַ��%p\n", ++pc);

	////ָ��Ĵ�С����ͬ�ģ�ָ��ʽ������ŵ�ַ�ģ�ָ����Ҫ���ռ�ȡ���ڵ�ַ�Ĵ洢��Ҫ���ռ�
	//printf("%d\n", sizeof(char*));
	//printf("%d\n", sizeof(short*));
	//printf("%d\n", sizeof(int*));
	//printf("%d\n", sizeof(long*));
	//printf("%d\n", sizeof(long long*));
	//printf("%d\n", sizeof(float*));
	//printf("%d\n", sizeof(double*));


/*
	�ġ��ṹ�壬������C���Դ������µ�����

*/
	//struct Stu s = { "����",20,99.9 };//�����ṹ��ͳ�ʼ��
	//printf("1��%s %d %.2lf\n", s.name, s.age, s.score);//�ṹ��.��Ա����
	//struct Stu* sp = &s;
	//printf("2��%s %d %.2lf\n", (*sp).name, (*sp).age, (*sp).score);
	//printf("3��%s %d %.2lf\n", sp->name, sp->age, sp->score);// "->"�÷����ṹ��ָ��->��Ա��


/*
	�塢��֧����ѭ�����
	1.��֧��䣨ѡ��ṹ����if		switch
	2.ѭ����䣺while	for		do while
	3.goto���
*/
	//int age = 30;
	//if (age < 18)
	//	printf("δ����");
	////else if (18 <= age < 26)//���߼�����	18<=age -- 1	1<60 - 1
	////	printf("����");
	//else if (age >= 26 && age < 40)
	//	printf("����");

	//int a = 0;
	//int b = 2;
	//if (a == 1)
	//	if (b == 2)
	//		printf("QQQ\n");
	//	else
	//		printf("AAA\n");	//else�������ifƥ��!

	int day = 0;
	scanf("%d", &day);
	switch (day)//������Ϊ���ͱ��ʽ���ַ�Ҳ�У���Ϊ�ַ��ײ���ASCLLֵ��
	{
	case 1://case��Ϊ���ͳ������ʽ���ַ�Ҳ�У���Ϊ�ַ��ײ���ASCLLֵ��
		printf("��һ\n");
		break;//breakֻ�����������ڵ�switch-case���
	case 2:
		printf("�ܶ�\n");
		break;
	case 3:
		printf("����\n");
		break;
	case 4:
		printf("����\n");
		break;
	case 5:
		printf("����\n");
		break;
	case 6:
		printf("����\n");
		break;
	case 7:
		printf("����\n");
		break;
	default:
		printf("��������");
		break;
	}

	return 0;
}

