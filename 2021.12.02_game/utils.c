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
	printf("��һغϣ����������꣺\n");

	while (1)
	{
		scanf("%d %d", &x, &y);
		//�ж�����Ϸ���
		if (1 <= x && row >= x && 1 <= y && col >= y)
		{
			//�ж������Ƿ�ռ��
			if (' ' == board[x - 1][y - 1])
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�˴��������ӣ������£�\n");
			}
		}
		else
		{
			printf("��������Чλ�ã�\n");
		}
	}
	--count;
	//printf("%d\n", count);
}

void computerMove(char board[ROW][COL], int row, int col)
{
	printf("���Իغϣ�\n");
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
		1.���Ӯ*		2.����Ӯ#		3.ƽ��e		 4.����c
	*/

	//�ж���Ӯ
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')//ע�ⲻ��������a == b == c
				return board[i][0];
	}

	//�ж���Ӯ
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')//ע�ⲻ��������a == b == c
				return board[0][i];
	}

	//���Խ���
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
			return board[0][0];
	}

	//���Խ���
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
			return board[0][2];
	}

	//ƽ��
	if (0 == count)
	{
		return 'e';
	}

	//������Ϸ
	return 'c';
}
	

void game()
{
	//�洢���� -- ��ά����
	char board[ROW][COL];
	//��ʼ������Ϊ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ���̣������Ǵ�ӡ��������
	dispalyBoard(board, ROW, COL);
	char res = '0';
	while (1)
	{
		//�����
		playerMove(board, ROW, COL);
		dispalyBoard(board, ROW, COL);
		//�ж���Ӯ
		res = isWin(board, ROW, COL);
		if ('c' != res)
			break;
			
		//������
		computerMove(board, ROW, COL);
		dispalyBoard(board, ROW, COL);
		res = isWin(board, ROW, COL);
		if ('c' != res)
			break;
	}
	if ('*' == res)
		printf("���ʤ����\n");
	else if ('#' == res)
		printf("����ʤ����\n");
	else
		printf("ƽ�֣�\n");
}

