#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu() {
	printf("************************************\n");
	printf("**********   1 ��ʼ��Ϸ   **********\n");
	printf("**********   0 �ر���Ϸ   **********\n");
	printf("************************************\n");
}
void game() {
	//�洢����
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	char ret = 0;
	while (1) {
		//�������
		PlayerMore(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Compare(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//��������
		ComputerMore(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Compare(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '*') {
		printf("���ʤ�� \n");
		DisplayBoard(board, ROW, COL);
	}
	else if (ret == '#') {
		printf("����ʤ�� \n");
		DisplayBoard(board, ROW, COL);
	}
	else {
		printf("ƽ�� \n");
	}
}
int main() {
	int input;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��->:");
		scanf("%d", &input);
		switch (input) {
		case 0 :
			printf("�ر���Ϸ \n");
			break;
		case 1 :
			game();
			break;
		default :
			printf("ѡ�����������ѡ�� \n");
			break;
		}
	
	} while (input);

		return 0;
}