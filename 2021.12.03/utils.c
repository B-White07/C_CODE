#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"

void menu()
{
	printf("********************\n");
	printf("***    1.play    ***\n");
	printf("***    2.exit    ***\n");
	printf("********************\n");
}

void initBoard(char board[ROWS][COLS], int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}

void display(char board[ROWS][COLS], int row, int col)
{
	//打印列号
	printf("--------扫雷--------\n");
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//printf("--------扫雷--------\n");
}

void setBomb(char board[ROWS][COLS], int row, int col)
{
	//雷的个数
	int num = EASY;
	while(num)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			num--;
		}
	}
}

static int aroundNums(int x, int y,char boardSet[ROWS][COLS])
{	// 数字 + '0' = '数字'
	// '数字' - '0' = 数字
	// 实际上，数字和字符可以任意加减，用相对应的控制符输出想要的结果即可（但是结果不能出现复数的情况，因为ACSLL码没有负数，无法转化）
	return boardSet[x - 1][y - 1] +
		boardSet[x - 1][y] +
		boardSet[x - 1][y + 1] +
		boardSet[x][y - 1] +
		boardSet[x][y + 1] +
		boardSet[x + 1][y - 1] +
		boardSet[x + 1][y] +
		boardSet[x + 1][y + 1] - 8 * '0';
}

int checkBomb(char boardSet[ROWS][COLS], char boardShow[ROWS][COLS], int x, int y)
{
	//有雷的位置标记为1
	//坐标不合法返回-1		有雷返回1		没有雷返回0
	int flag = 0;
	if (1 > x || ROW < x || 1 > y || COL < y)
	{
		flag = -1;
		return flag;
	}
	else
	{
		if ('1' == boardSet[x][y])
			flag = 1;
		else
			boardShow[x][y] = aroundNums(x, y, boardSet) + '0';
		return flag;
	}
}

void game()
{
	int count = ROW * COL - EASY;
	char boardSet[ROWS][COLS] = { 0 };
	char boardShow[ROWS][COLS] = { 0 };
	initBoard(boardSet, ROWS, COLS, '0');
	initBoard(boardShow, ROWS, COLS, '*');
	setBomb(boardSet, ROW, COL);
	display(boardShow, ROW, COL);
	display(boardSet, ROW, COL);

	while (1)
	{
		printf("请输入落子位置：");
		int x = 0;
		int y = 0;
rewrite:
		scanf("%d %d", &x, &y);
		//先判断坐标是否合法
		if (-1 != checkBomb(boardSet, boardShow, x, y))
		{
			if (1 == checkBomb(boardSet, boardShow, x, y))
			{
				printf("太遗憾了，你挂了！\n");
				display(boardSet, ROW, COL);
				break;
			}
			else
			{
				display(boardShow, ROW, COL);
				display(boardSet, ROW, COL);
				count--;
				if (count == 0)
				{
					printf("恭喜你，安全拆掉所有雷！\n");
					break;
				}
			}
		}
		else
		{
			printf("请输入有效位置：");
			goto rewrite;
		}
	}
}