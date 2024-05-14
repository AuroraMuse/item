#pragma once
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 20
#define MAX_PHONE 20
#define MAX_ADDR 20 
#define MAX 1000

typedef struct PeoInfo {
	char name[MAX_NAME];  //����
	char sex[MAX_SEX];    //�Ա�
	int age;              //����
	char phone[MAX_PHONE];//�绰
	char addr[MAX_ADDR];  //��ַ
}PeoInfo;

typedef struct Contact {
	PeoInfo date[MAX];//�������˵���Ϣ
	int sz; //��¼��ǰͨѶ¼����Ч��Ϣ����
}Contact;

void InitContact(Contact* pc);
//������ϵ����Ϣ
void AddContact(Contact* pc);

//��ʾ��ϵ����Ϣ
void PrintContact(const Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SeekContact(Contact* pc);

//�޸���ϵ��
void RecomContact(Contact* pc);

//����
void SortContact(Contact* pc);

