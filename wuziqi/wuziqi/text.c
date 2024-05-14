#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu() {
	printf("************************************\n");
	printf("**********   1 开始游戏   **********\n");
	printf("**********   0 关闭游戏   **********\n");
	printf("************************************\n");
}
void game() {
	//存储数据
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1) {
		//玩家下棋
		PlayerMore(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Compare(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		ComputerMore(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Compare(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("玩家胜利 \n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#') {
		printf("电脑胜利 \n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("平局 \n");
	}
}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择->:");
		scanf("%d", &input);
		switch (input) {
		case 0 :
			printf("关闭游戏 \n");
			break;
		case 1 :
			game();
			break;
		default :
			printf("选择错误，请重新选择 \n");
			break;
		}
	
	} while (input);

		return 0;
}