#pragma once
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
//���ŵĶ���
#define ROW 7
#define COL 7

//����������
//��ʼ������
void InitBoard(char board[ROW][COL], int row , int col);
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row , int col);
//�������
void PlayerMore(char board[ROW][COL], int row , int col);
//��������
void ComputerMore(char board[ROW][COL],int row ,int col);
//�ж�ʤ��
char Compare(char board[ROW][COL],int row ,int col);




