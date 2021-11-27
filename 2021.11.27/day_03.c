#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

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


	
	return 0;
}