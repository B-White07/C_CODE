#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	/*
		һ��ѭ�����
		1.while		2.for		3.do while
	*/

	//while��	1.break		2.continue
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		//break;//whileѭ���е�break������ֹѭ����
	//		continue;//whileѭ���е�continue����������ѭ��continue��ߵĴ��룬ֱ�ӻص��жϲ��֣��жϷ������һ��ѭ����
	//	printf("%d ", i);
	//	i++;
	//}

	//getchar()��ȡһ���ַ�		EOF - end of file - �ļ�������־		ctrl+z	-	getchar��ȡ����
	//int ch = getchar();
	////printf("%c", ch);
	//putchar(ch);//���һ���ַ�

	//getchar�ӻ�������ȡ���ݣ����̼�������ݷ��뻺�������س���\n����ʽ����ڻ������ڣ�Ҳ���ַ������Ա���ȡ��
	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	putchar(ch);
	//}

	//char password[20] = { 1 };//��һ��Ϊ1������Ϊ0
	//printf("please input the psw:");
	//scanf("%s", password);//������������ǵ�ַ������ȡ��ַ&		��ʱ�������м�������ݺ�\n��scanf��ȡ�����ݣ�����\n
	//						//scanf����ȡ�س����ո��Ʊ��
	//printf("please confirm the psw(Y/N):");
	////��������
	////getchar();//����'\n'��
	////���������еĶ���ַ�
	//int tmp = 0;
	//while ((tmp = getchar()) != '\n')
	//{
	//	;
	//}

	//int ch = getchar();//��ʱ��������\n��ֱ�ӱ�getchar��ȡ
	//if (ch == 'Y')
	//{
	//	printf("sunccess\n");
	//}
	//else
	//{
	//	printf("fail");
	//}

	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	if (ch < '0' || ch > '9')
	//		continue;
	//	putchar(ch);
	//}

	//int ch = getchar();
	//printf("%c\n", 'ad');	//Q:��''��������һ���ַ��Ĵ���
	//putchar(ch);


	
	return 0;
}