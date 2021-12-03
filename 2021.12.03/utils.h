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
//设置雷
void setBomb(char board[ROWS][COLS], int row, int col);
//检查雷
int checkBomb(char board[ROWS][COLS], int row, int col);

//初始化面板
void initBoard(char board[ROWS][COLS], int rows, int cols, char ch);
//打印面板
void display(char board[ROWS][COLS], int row, int col);
