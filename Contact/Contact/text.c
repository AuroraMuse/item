#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void menu(){
	printf("************************************\n");
	printf("*****1.增加联系人   2.删除联系人****\n");
	printf("*****3.查找联系人   4.修改联系人****\n");
	printf("*****5.排序联系人   6.显示联系人****\n");
	printf("**********    0 退出  **************\n");
	printf("************************************\n");
}
int main() {
	int input = 0;
	//创建通讯录
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			//增加联系人
			AddContact(&con);
			break;
		case 2:
			//删除联系人
			DelContact(&con);
			break;
		case 3:
			//查找联系人
			SeekContact(&con);
			break;
		case 4:
			//修改联系人
			RecomContact(&con);
			break;
		case 5:
			//排序
			SortContact(&con);
			break;
		case 6:
			//显示联系人
			PrintContact(&con);
			break;
		default:
			printf("输入错误，请重行输入\n");
			break;
		}
	} while (input);
	return 0;
}