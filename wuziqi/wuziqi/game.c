#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
}
}
//棋盘的实现
void DisplayBoard(char board[ROW][COL], int row, int col) {
	int j = 0;
	for (int i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if(j < col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}

}
//玩家下棋
void PlayerMore(char board[ROW][COL], int row, int col) {
		printf("玩家：>\n");
		int i, j;
		while (1) {
			printf("请输入下棋位置：\n");
			scanf("%d %d", &i, &j);
			if (i >= 1 && i <= row && j >= 1 && j <= col) {
				if (board[i-1][j-1] == ' ') {
					board[i-1][j-1] = '*';
					break;
				}
				else {
					printf("该位置已有棋子，请重新输入：\n");
				}
			}
			else {
				printf("坐标错误,请从新输入:\n");
		}			
	}
}
//电脑下棋
void ComputerMore(char board[ROW][COL], int row, int col) {
	printf("电脑走:\n");
	int x, y;
	/*int x = rand() % row;
	int y = rand() % col;*/
	do {
		 x = rand() % row;
		 y = rand() % col;
	} while (board[x][y] != ' ');
	board[x][y] = '#';
	/*while (1) {
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}*/
}
//判断棋盘是否占满
int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}
//判断游戏胜负
char Compare(char board[ROW][COL], int row, int col) {
	int i, j;
	for (i = 0; i < row; i++) {
		//检查水平方向
		for (j = 0; j < col - 1; j++) {
			if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] ==
				board[i][j + 3] && board[i][j] == board[i][j + 4] && board[i][j] != ' ') {
				return board[i][j];

			}
		}
	}

	//检查垂直方向
	for (i = 0; i < row - 4; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] ==
				board[i + 3][j] && board[i][j] == board[i + 4][j] && board[i][j] != ' ') {
				return board[i][j];
			}
		}
	}
	//检查左上到右下方向
	for (i = 0; i < row - 4; i++) {
		for (j = 0; j < col - 4; j++) {
			if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] ==
				board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4] && board[i][j] != ' ') {
				return board[i][j];
			}
		}
	}
	//检查右上到左下方向
	for (i = row - 4; i >= 0; i--) {
		for (j = col + 4; j >= 0; j--) {
			if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] ==
				board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4] && board[i][j] != ' ') {
				return board[i][j];
			}
		}
	}
	//判断平局
	int set=IsFull(board, row, col);
	if (set == 1) {
		return 'Q';
	}
	return 'C';
}