#include<stdio.h>
#include"game.h"
#include<stdlib.h>
#include<time.h>
//��������
void reset(char board[row][col])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
int isfull(char board[row][col]) {
	int a,b;
	for (a = 0; a < row; a++) {
		for (b = 0; b < col; b++) {
			if (board[a][b] == ' ') {
				return 0;
			}
		}
	} 
	return 1;
}
//�ж���Ӯ
char iswin(char board[row][col]) {
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1]&& board[i][1] == board[i][2] && board[i][i] != ' ') {
			return board[i][i];
		}
	}
	for (i = 0; i < row; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[i][i] != ' ') {
			return board[i][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (1 == isfull(board)) {
		return 'p';
	}else return 'j';
}
void qipan(char board[row][col])
{
	int i = 0, j = 0; 
	int p;
	for (; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		for (p = 0; p < j; p++) {
			if (row > i+1) {
				printf("�� ");
			}
		}
		printf("\n");
	}
}
//��Ϸ����
void playermove(char board[row][col]) {
	int x, y;
	printf("����ƶ�\n");
	printf("����������\n");
	while (1) {
		scanf_s("%d%d", &x,&y);

		if (x<=row&&x>=0&&y>=0&&y<=col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("��������������\n");
			}
		}
		else {
			printf("��������������\n");
		}
	}
}
void computermove(char board[row][col])
{
	int x = 0;
	int y = 0;
	srand((unsigned int)time(NULL));
	printf("�����ƶ�\n");
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (x <= row && x >= 0 && y >= 0 && y <= col) {
			if (board[x][y] == ' ') {
				board[x][y] = '@';
				break;
			}
			else {
				printf("");
			}
		}
		else {
			printf("");
		}
	}
}
//��Ϸ�㷨ʵ��
void game() 
{
	char board[row][col] = {0};
	char ret;
	reset(board);
	qipan(board);
	while (1) {
		playermove(board);
		qipan(board);
		ret=iswin(board);
		if (ret == 'p') {
			printf("ƽ��\n");
			break;
		}
		else if (ret == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (ret == '@') {
			printf("����Ӯ\n");
			break;
		}
		computermove(board);
		qipan(board);
		ret = iswin(board);
		if (ret == 'p') {
			printf("ƽ��\n");
			break;
		}
		else if (ret == '*') {
			printf("���Ӯ\n");
			break;
		}
		else if (ret == '@') {
			printf("����Ӯ\n");
			break;
		}
	}
}
void meun()
{
	printf("******************\n");
	printf("**1:play  2:exit**\n");
	printf("******************\n");
}
void test()
{
	int input=0;
	do { 
		meun();
		printf("��ѡ��\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:printf("��Ϸ��ʼ\n");
			game();
			break;
		case 2:printf("�˳���Ϸ\n");
			break;
		default:printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (input!=2);
}
int main()
{
	test();
	return 0;
}