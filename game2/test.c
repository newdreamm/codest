#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("****************************\n");
	printf("******  1. play      *******\n");
	printf("******  0. exit      *******\n");
	printf("****************************\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放排查雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的类的信息
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//DisplayBoard(mine, ROW, COL);
	
	//设置雷
	SetMine(mine ,ROW,COL);
	DisplayBoard(show, ROW, COL);
	DisplayBoard(mine, ROW, COL);


	//排查雷
	FindMine(mine, show, ROW, COL);

	

}
int main()
{
	int input = 0;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误\n");
				break;
		}
	} while (input);
	return 0;
}