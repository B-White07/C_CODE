#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"

void menu()
{
	printf("********************\n");
	printf("***    1.play    ***\n");
	printf("***    2.exit    ***\n");
	printf("********************\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			board[i][j] = ' ';
	}
}

void dispalyBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		for (int j = 0; j < col; j++)
		{
			if (i < row - 1)
				printf("--- ");
		}
		printf("\n");
	}
}

void playerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家回合，请输入坐标：\n");

	while (1)
	{
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (1 <= x && row >= x && 1 <= y && col >= y)
		{
			//判断坐标是否被占用
			if (' ' == board[x - 1][y - 1])
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("此处已有棋子，请重下：\n");
			}
		}
		else
		{
			printf("请输入有效位置：\n");
		}
	}
	--count;
	//printf("%d\n", count);
}

void computerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑回合：\n");
	while (1)
	{
		int x = rand() % 3;
		int y = rand() % 3;
		if (' ' == board[x][y])
		{
			board[x][y] = '#';
			break;
		}
	}
	--count;
	//printf("%d\n", count);
}

char isWin(char board[ROW][COL], int row, int col)
{
	/*
		1.玩家赢*		2.电脑赢#		3.平局e		 4.继续c
	*/

	//判断列赢
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')//注意不能用连等a == b == c
				return board[i][0];
	}

	//判断列赢
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')//注意不能用连等a == b == c
				return board[0][i];
	}

	//副对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
			return board[0][0];
	}

	//主对角线
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
			return board[0][2];
	}

	//平局
	if (0 == count)
	{
		return 'e';
	}

	//继续游戏
	return 'c';
}
	

void game()
{
	//存储数据 -- 二维数组
	char board[ROW][COL];
	//初始化棋盘为空格
	InitBoard(board, ROW, COL);
	//打印棋盘，本质是打印数组内容
	dispalyBoard(board, ROW, COL);
	char res = '0';
	while (1)
	{
		//玩家走
		playerMove(board, ROW, COL);
		dispalyBoard(board, ROW, COL);
		//判断输赢
		res = isWin(board, ROW, COL);
		if ('c' != res)
			break;
			
		//电脑走
		computerMove(board, ROW, COL);
		dispalyBoard(board, ROW, COL);
		res = isWin(board, ROW, COL);
		if ('c' != res)
			break;
	}
	if ('*' == res)
		printf("玩家胜利！\n");
	else if ('#' == res)
		printf("电脑胜利！\n");
	else
		printf("平局！\n");
}

