#pragma once
#define ROW 3
#define COL 3
//头文件的包含
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;

void menu();
void game();
void InitBoard(char board[ROW][COL], int row, int col);
void dispalyBoard(char board[ROW][COL], int row, int col);
void playerMove(char board[ROW][COL], int row, int col);
void computerMove(char board[ROW][COL], int row, int col);
char isWin(char board[ROW][COL], int row, int col);