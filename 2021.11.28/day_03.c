#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	/*
		一、循环语句
		1.while		2.for		3.do while
	*/

	//while：	1.break		2.continue
	//int i = 1;
	//while (i <= 10)
	//{
	//	if (i == 5)
	//		//break;//while循环中的break用于终止循环。
	//		continue;//while循环中的continue：跳过本次循环continue后边的代码，直接回到判断部分，判断否进行下一次循环。
	//	printf("%d ", i);
	//	i++;
	//}

	//getchar()获取一个字符		EOF - end of file - 文件结束标志		ctrl+z	-	getchar读取结束
	//int ch = getchar();
	////printf("%c", ch);
	//putchar(ch);//输出一个字符

	//getchar从缓冲区读取数据，键盘键入的数据放入缓冲区，回车以\n的形式存放在缓冲区内，也算字符，可以被读取。
	//int ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	putchar(ch);
	//}

	//char password[20] = { 1 };//第一项为1，其余为0
	//printf("please input the psw:");
	//scanf("%s", password);//数组名本身就是地址，不需取地址&		此时缓冲区有键入的数据和\n，scanf会取走数据，留下\n
	//						//scanf不读取回车，空格，制表符
	//printf("please confirm the psw(Y/N):");
	////清理缓冲区
	////getchar();//处理'\n'，
	////清理缓冲区中的多个字符
	//int tmp = 0;
	//while ((tmp = getchar()) != '\n')
	//{
	//	;
	//}

	//int ch = getchar();//此时缓冲区有\n，直接被getchar读取
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
	//printf("%c\n", 'ad');	//Q:用''括起来的一串字符的处理
	//putchar(ch);

	//for：1.不可以在循环体内调整循环变量		2.循环控制变量建议采用前闭后开的写法。
	//int i = 0;
	//for (i = 1; i <= 10; i++)
	//{
	//	if (i == 5)
	//		//break;
	//		continue;
	//	printf("%d ", i);
	//}

	//for变种：1.省略表达式（）三个都可省		2.有两个循环控制变量
	//for (; ;)//三个部分都可以省略，但是判断部分的省略会导致死循环
	//{
	//	printf("123 ");
	//}
	//int i = 0;
	//int j = 0;
	//for (; i < 3; i++)
	//{
	//	for (; j < 3; j++)//j每次都没有初始化为0，而是保存为3
	//	{
	//		printf("12\n");
	//	}
	//}
	//int i = 0;
	//int k = 0;
	//for (i = k = 0; k = 0; i++, k++)//判断语句恒为假，一次不也不执行
	//{
	//	k++;
	//}

	//do while：循环体至少执行一次
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
	//1.计算阶乘
	//int n = 0;
	//printf("input a num:");
	//scanf("%d", &n);
	//printf("result:%d",mul(n));

	//2.计算1！+2！+...+10！
	//printf("%d\n", sum1());
	//printf("%d\n", sum2());

	//3.在一个有序数组中查找具体的某个数字n。编写int binsearch(int x,int v[],int n)；功能：在v中查找x。
	//int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//int x = 0;
	//int len = sizeof(arr)/sizeof(arr[0]);//注意！！sizeof不是函数，此时计算的是arr的长度
	//printf("input the num you want: ");
	//scanf("%d", &x);
	//printf("the index of %d is: %d", x, binSearch2(arr,x,len));
	
	//4.演示多个字符从两端移动，向中间汇聚
	/*Welcome to fudan！！！
	* W###################！
	* We################！！
	* ...
	* Welcome to fudan！！！
	*/
	//char arr1[] = "Welcome to fudan!!!";
	//char arr2[] = "###################";
	//int len = sizeof(arr1) / sizeof(arr1[1]);
	//moveChars(arr1, arr2,len);

	//5.模拟用户登录情景，只允许试三次密码，不成功退出程序。
	//printf("psw please:\n");
	//char psw[20] = { 0 };
	//for (int i = 0; i < 3; i++)
	//{
	//	scanf("%s", psw);//数组本身就是地址，无需再&
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

	//6.写一个猜数字游戏	1.自动产生1-100之间的随机数，猜对了就恭喜你，游戏结束；
	//猜错了，告诉你大了还是小了，继续猜，直到猜对为止；游戏可以一直玩，除非退出游戏。
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


	//二、goto语句
//flag:
//	printf("welcome\n");
//	printf("welcome\n");
//	goto flag;

	//关机	shutdown -s -t 60				shutdown -a
	char input[20] = { 0 };
	system("shutdown -s -t 60");
	flag:
	printf("电脑将在一分钟内关机，如果输入：黑白，则取消关机\n");
	scanf("%s", input);	//				Q：scanf  getchar读取空格。		如何将可执行程序添加到服务中
	if (strcmp(input, "黑白") == 0)
		system("shutdown -a");
	else
		goto flag;

	return 0;
}