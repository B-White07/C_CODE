#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY 50


void menu();
void game();
//������
void setBomb(char board[ROWS][COLS], int row, int col);
//�����
int checkBomb(char board[ROWS][COLS], int row, int col);

//��ʼ�����
void initBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//��ӡ���
void display(char board[ROWS][COLS], int row, int col);
