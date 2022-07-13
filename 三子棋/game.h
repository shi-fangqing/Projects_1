#include<stdio.h>
#define ROW 3
#define COL 3
void Init_board(char board[ROW][COL],int row,int col);
void Display_board(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
#include<time.h>
#include<stdlib.h>
void ComputerMove(char board[ROW][COL],int row,int col);
char Win(char board[ROW][COL],int row,int col);
