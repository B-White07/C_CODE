#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

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

	//for��1.��������ѭ�����ڵ���ѭ������		2.ѭ�����Ʊ����������ǰ�պ󿪵�д����
	//int i = 0;
	//for (i = 1; i <= 10; i++)
	//{
	//	if (i == 5)
	//		//break;
	//		continue;
	//	printf("%d ", i);
	//}

	//for���֣�1.ʡ�Ա��ʽ������������ʡ		2.������ѭ�����Ʊ���
	//for (; ;)//�������ֶ�����ʡ�ԣ������жϲ��ֵ�ʡ�Իᵼ����ѭ��
	//{
	//	printf("123 ");
	//}
	//int i = 0;
	//int j = 0;
	//for (; i < 3; i++)
	//{
	//	for (; j < 3; j++)//jÿ�ζ�û�г�ʼ��Ϊ0�����Ǳ���Ϊ3
	//	{
	//		printf("12\n");
	//	}
	//}
	//int i = 0;
	//int k = 0;
	//for (i = k = 0; k = 0; i++, k++)//�ж�����Ϊ�٣�һ�β�Ҳ��ִ��
	//{
	//	k++;
	//}

	//do while��ѭ��������ִ��һ��
	//int i = 1;
	//do
	//{
	//	if (i == 5)
	//		//break;
	//		continue;
	//	printf("%d ", i);
	//	i++;
	//} while (i <= 10);

	//test
	//1.����׳�
	//int n = 0;
	//printf("input a num:");
	//scanf("%d", &n);
	//printf("result:%d",mul(n));

	//2.����1��+2��+...+10��
	//printf("%d\n", sum1());
	//printf("%d\n", sum2());

	//3.��һ�����������в��Ҿ����ĳ������n����дint binsearch(int x,int v[],int n)�����ܣ���v�в���x��
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int x = 0;
	//int len = sizeof(arr)/sizeof(arr[0]);//ע�⣡��sizeof���Ǻ�������ʱ�������arr�ĳ���
	//printf("input the num you want: ");
	//scanf("%d", &x);
	//printf("the index of %d is: %d", x, binSearch2(arr,x,len));
	
	//4.��ʾ����ַ��������ƶ������м���
	/*Welcome to fudan������
	* W###################��
	* We################����
	* ...
	* Welcome to fudan������
	*/
	//char arr1[] = "Welcome to fudan!!!";
	//char arr2[] = "###################";
	//int len = sizeof(arr1) / sizeof(arr1[1]);
	//moveChars(arr1, arr2,len);

	//5.ģ���û���¼�龰��ֻ�������������룬���ɹ��˳�����
	//printf("psw please:\n");
	//char psw[20] = { 0 };
	//for (int i = 0; i < 3; i++)
	//{
	//	scanf("%s", psw);//���鱾����ǵ�ַ��������&
	//	if (login(psw) == 1)
	//	{
	//		printf("success!");
	//		break;
	//	}
	//	else
	//	{
	//		printf("err,input again:\n");
	//		//scanf("%s", psw);
	//		//login(psw);
	//	}
	//}

	//6.дһ����������Ϸ	1.�Զ�����1-100֮�����������¶��˾͹�ϲ�㣬��Ϸ������
	//�´��ˣ���������˻���С�ˣ������£�ֱ���¶�Ϊֹ����Ϸ����һֱ�棬�����˳���Ϸ��
	//int input = 0;
	//srand((unsigned int)time(NULL));
	//do
	//{
	//	menu();
	//	printf("input a num please:");
	//	scanf("%d", &input);
	//	switch (input)
	//	{
	//	case 1:
	//		game();
	//		break;
	//	case 2:
	//		printf("goodbye");
	//		return 0;
	//	default:
	//		printf("choose again please.\n");
	//		break;
	//	}
	//} while (input !=2 );

	//int x = 0;
	//int y = 0;
	//printf("input two nums:\n");
	//scanf("%d %d", &x, &y);
	//if(maxPub2(x,y) != 0)
	//	printf("the maxPub is:%d ", maxPub2(x, y));
	//else
	//	printf("none");
	//int x = 0;
	//int y = 0;
	//scanf("%d %d", &x, &y);
	//suShu(x, y);


	//����goto���
//flag:
//	printf("welcome\n");
//	printf("welcome\n");
//	goto flag;

	//�ػ�	shutdown -s -t 60				shutdown -a
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	flag:
	printf("���Խ���һ�����ڹػ���������룺�ڰף���ȡ���ػ�\n");
	scanf("%s", input);	//				Q��scanf  getchar��ȡ�ո�		��ν���ִ�г�����ӵ�������
	if (strcmp(input, "�ڰ�") == 0)
		system("shutdown -a");
	else
		goto flag;

	return 0;
}