#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(Contact* pc) {
	pc->sz = 0;
	memset(pc->date,0, sizeof(pc->date));
}
//增加联系人信息
void AddContact(Contact* pc) {
	if (pc->date == MAX) {
		printf("通讯录已满,无法添加\n");
		return;
	}
	//增加一个人的信息
	printf("请输入添加人姓名：>");
	scanf("%s", pc->date[pc->sz].name);
	printf("请输入添加人性别：>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("请输入添加人年龄：>");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("请输入添加人电话：>");
	scanf("%s", pc->date[pc->sz].phone);
	printf("请输入添加人地址：>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n");

}

//显示联系人
void PrintContact(const Contact* pc) {
	int i = 0;
	//打印标题
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	//打印数据
	for (i = 0; i < pc->sz; i++) {
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n",
			pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].age,
			pc->date[i].phone,
			pc->date[i].addr);	
	}
}

static int FindContact(Contact* pc, char name[]) {
	int i = 0;
	for (i = 0; i < pc->sz; i++) {
		if (strcmp(pc->date[i], name) == 0) {
			return i;
		}
	}
	return -1;//查无此人
}
//删除联系人
void DelContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("没有任何联系人，无需删除\n");
		return;
	}
	//查找要删除的人
	printf("请输入要删除的人:>");
	scanf("%s", name);
	int pos=FindContact(pc, name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	int i = 0;
	for (int i = pos; i < pc->sz-1; i++) {
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

//查找联系人
void SeekContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("没有任何联系人，无需查找\n");
		return;
	}
	printf("请输入要查找的人:>");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n",
				pc->date[pos].name,
				pc->date[pos].sex,
				pc->date[pos].age,
				pc->date[pos].phone,
				pc->date[pos].addr);
		printf("查询完成\n");
	}

}

void RecomContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("没有任何联系人，无需修改\n");
		return;
	}
	printf("请输入要修改的人:>");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("查无此人\n");
		return;
	}
	else {
		printf("请输入修改的后人姓名：>");
		scanf("%s", pc->date[pos].name);
		printf("请输入修改的后人性别：>");
		scanf("%s", pc->date[pos].sex);
		printf("请输入修改的后人年龄：>");
		scanf("%d", &(pc->date[pos].age));
		printf("请输入修改的后人人电话：>");
		scanf("%s", pc->date[pos].phone);
		printf("请输入修改的后人人地址：>");
		scanf("%s", pc->date[pos].addr);
		printf("增加成功\n");	
	}
}

void SortContact(Contact* pc) {
	int i = 0;
	int j = 0;
	if (pc->sz == 0) {
		printf("没有任何联系人，无需排序\n");
		return;
	}
	for (i = 0; i < pc->sz - 1; i++) {
		for (j = 0; j < pc->sz - 1 - i; j++) {
			if (strcmp(pc->date[j].name, pc->date[j + 1].name) > 0) {
				PeoInfo swop;
				swop = pc->date[j];
				pc->date[j] = pc->date[j + 1];
				pc->date[j + 1] = swop;

			}
		}
		printf("排序成功\n");
	}
}