#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu(){
	printf("************************************\n");
	printf("*****1.������ϵ��   2.ɾ����ϵ��****\n");
	printf("*****3.������ϵ��   4.�޸���ϵ��****\n");
	printf("*****5.������ϵ��   6.��ʾ��ϵ��****\n");
	printf("**********    0 �˳�  **************\n");
	printf("************************************\n");
}
int main() {
	int input = 0;
	//����ͨѶ¼
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			//������ϵ��
			AddContact(&con);
			break;
		case 2:
			//ɾ����ϵ��
			DelContact(&con);
			break;
		case 3:
			//������ϵ��
			SeekContact(&con);
			break;
		case 4:
			//�޸���ϵ��
			RecomContact(&con);
			break;
		case 5:
			//����
			SortContact(&con);
			break;
		case 6:
			//��ʾ��ϵ��
			PrintContact(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}