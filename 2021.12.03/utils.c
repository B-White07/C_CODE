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
	//��ӡ�к�
	printf("--------ɨ��--------\n");
	for (int i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	//printf("--------ɨ��--------\n");
}

void setBomb(char board[ROWS][COLS], int row, int col)
{
	//�׵ĸ���
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
{	// ���� + '0' = '����'
	// '����' - '0' = ����
	// ʵ���ϣ����ֺ��ַ���������Ӽ��������Ӧ�Ŀ��Ʒ������Ҫ�Ľ�����ɣ����ǽ�����ܳ��ָ������������ΪACSLL��û�и������޷�ת����
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
	//���׵�λ�ñ��Ϊ1
	//���겻�Ϸ�����-1		���׷���1		û���׷���0
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
		printf("����������λ�ã�");
		int x = 0;
		int y = 0;
rewrite:
		scanf("%d %d", &x, &y);
		//���ж������Ƿ�Ϸ�
		if (-1 != checkBomb(boardSet, boardShow, x, y))
		{
			if (1 == checkBomb(boardSet, boardShow, x, y))
			{
				printf("̫�ź��ˣ�����ˣ�\n");
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
					printf("��ϲ�㣬��ȫ��������ף�\n");
					break;
				}
			}
		}
		else
		{
			printf("��������Чλ�ã�");
			goto rewrite;
		}
	}
}