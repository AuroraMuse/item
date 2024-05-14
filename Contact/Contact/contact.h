#pragma once
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_PHONE 20
#define MAX_ADDR 20 
#define MAX 1000

typedef struct PeoInfo {
	char name[MAX_NAME];  //名字
	char sex[MAX_SEX];    //性别
	int age;              //年龄
	char phone[MAX_PHONE];//电话
	char addr[MAX_ADDR];  //地址
}PeoInfo;

typedef struct Contact {
	PeoInfo date[MAX];//存放添加人的信息
	int sz; //记录当前通讯录中有效性息个数
}Contact;

void InitContact(Contact* pc);
//增加联系人信息
void AddContact(Contact* pc);

//显示联系人信息
void PrintContact(const Contact* pc);

//删除联系人
void DelContact(Contact* pc);

//查找联系人
void SeekContact(Contact* pc);

//修改联系人
void RecomContact(Contact* pc);

//排序
void SortContact(Contact* pc);

