//测试三子棋

#include "game.h"
void menu()
{
	printf("*******************************\n");
	printf("*****1.play      0.exit********\n");
	printf("*******************************\n");
}
void game()
{
	char board[ROW][COL]={0};
	int ret;
	//棋盘初始化
	Init_board(board,ROW,COL);
	//打印棋盘
	Display_board(board,ROW,COL);
    //下棋
	while(1)
	{
		PlayerMove(board,ROW,COL);
		Display_board(board,ROW,COL);
		ret=Win(board,ROW,COL);
		if(ret!='C')
		{//返回'C'继续下棋，否则停止下棋；跳出循环，判断结果
			break;
		}
		ComputerMove(board,ROW,COL);
		Display_board(board,ROW,COL);
		ret=Win(board,ROW,COL);
		if(ret!='C')
		{//返回'C'继续下棋，否则停止下棋；跳出循环，判断结果
			break;
		}
	}
	if(ret=='*')
		printf("玩家赢\n\n");
	else if(ret=='#')
		printf("电脑赢\n\n");
	else
		printf("平局\n\n");
}
void test()
{
	int input=0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game(); //进入游戏
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}while(input);
}
int main()
{
	test();
	return 0;
}
