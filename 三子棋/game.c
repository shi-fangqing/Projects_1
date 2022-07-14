#include"game.h"
void Init_board(char board[ROW][COL],int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{//初始化棋盘
		for(j=0;j<col;j++)
		{
			board[i][j]=' ';
		}
	}
}

void Display_board(char board[ROW][COL],int row,int col)
{//打印棋盘的方格，布局
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{ //打印一行数据
			printf(" %c ",board[i][j]);
			if(j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");

		//打印分割行                                                   
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				printf("---");
				if(j<col-1)
				{
					printf("|");
				}
			}   
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x;
	int y;
	
	printf("玩家下(请输入相应地坐标）：");
	while(1)
	{
	scanf("%d%d",&x,&y);
	if(x>=1&&x<=row && y>=1&&y<=col)
	{
		if(board[x-1][y-1]==' ')
		{//该位置为空时，填入玩家的棋子
			board[x-1][y-1]='*'; 
			break;
		}
		else
			printf("该坐标被占用,请重新输入：");
	}
	else
		printf("坐标非法，请重新输入：");
	}
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("电脑下：\n");
	while(1)
	{
		x=rand()%row;
		y=rand()%col;  //电脑随机生成出要下的位置
		if(board[x][y]==' ')
		{//该位置为空时，填入电脑的棋子
			board[x][y]='#';
			break;
		}
	}
	
}

char Win(char board[ROW][COL],int row,int col)
{
	int i;
	for(i=0;i<row;i++)
	{
		//横三行
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
			return board[i][0];
	}
	for(i=0;i<col;i++)
	{
		//竖三列
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' ')
			return board[0][i];
	}
	//两个对角线
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
		return board[0][0];
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=' ')
		return board[0][2];
	//判断是否平局
	if(Full(board,ROW,COL)==1)
		return 'Q';
	else
		return 'C';
}

int Full(char board[ROW][COL],int row,int col)
{
	int i;
	int j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
				return 0;  //没满
		}
	}
	return 1;    //满了
}

