#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"
void InitContact(Contact* pc) {
	pc->sz = 0;
	memset(pc->date,0, sizeof(pc->date));
}
//������ϵ����Ϣ
void AddContact(Contact* pc) {
	if (pc->date == MAX) {
		printf("ͨѶ¼����,�޷����\n");
		return;
	}
	//����һ���˵���Ϣ
	printf("�����������������>");
	scanf("%s", pc->date[pc->sz].name);
	printf("������������Ա�>");
	scanf("%s", pc->date[pc->sz].sex);
	printf("��������������䣺>");
	scanf("%d", &(pc->date[pc->sz].age));
	printf("����������˵绰��>");
	scanf("%s", pc->date[pc->sz].phone);
	printf("����������˵�ַ��>");
	scanf("%s", pc->date[pc->sz].addr);
	pc->sz++;
	printf("���ӳɹ�\n");

}

//��ʾ��ϵ��
void PrintContact(const Contact* pc) {
	int i = 0;
	//��ӡ����
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	//��ӡ����
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
	return -1;//���޴���
}
//ɾ����ϵ��
void DelContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("û���κ���ϵ�ˣ�����ɾ��\n");
		return;
	}
	//����Ҫɾ������
	printf("������Ҫɾ������:>");
	scanf("%s", name);
	int pos=FindContact(pc, name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	int i = 0;
	for (int i = pos; i < pc->sz-1; i++) {
		pc->date[i] = pc->date[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

//������ϵ��
void SeekContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("û���κ���ϵ�ˣ��������\n");
		return;
	}
	printf("������Ҫ���ҵ���:>");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	else {
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-20s\n",
				pc->date[pos].name,
				pc->date[pos].sex,
				pc->date[pos].age,
				pc->date[pos].phone,
				pc->date[pos].addr);
		printf("��ѯ���\n");
	}

}

void RecomContact(Contact* pc) {
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0) {
		printf("û���κ���ϵ�ˣ������޸�\n");
		return;
	}
	printf("������Ҫ�޸ĵ���:>");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1) {
		printf("���޴���\n");
		return;
	}
	else {
		printf("�������޸ĵĺ���������>");
		scanf("%s", pc->date[pos].name);
		printf("�������޸ĵĺ����Ա�>");
		scanf("%s", pc->date[pos].sex);
		printf("�������޸ĵĺ������䣺>");
		scanf("%d", &(pc->date[pos].age));
		printf("�������޸ĵĺ����˵绰��>");
		scanf("%s", pc->date[pos].phone);
		printf("�������޸ĵĺ����˵�ַ��>");
		scanf("%s", pc->date[pos].addr);
		printf("���ӳɹ�\n");	
	}
}

void SortContact(Contact* pc) {
	int i = 0;
	int j = 0;
	if (pc->sz == 0) {
		printf("û���κ���ϵ�ˣ���������\n");
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
		printf("����ɹ�\n");
	}
}