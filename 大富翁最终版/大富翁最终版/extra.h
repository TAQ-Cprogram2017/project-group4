#pragma once
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct user //����һ���ṹ�壬����������ҵ�·��
{
	int x;
	int y;
	int func;
	struct user *next;
}player;
typedef struct cons
{
	int revive;//���ڼ��Ӹ���״̬
	int satan;//���ڼ��Ӷ�ħ״̬
	int angel;//���ڼ�����ʹ״̬
	int hp = 100;
	int money = 0;
}console;
player* creatpoint(int x, int y);
player* add(player *head, player *p);
int random(int x);
player* map();
void moveimg(IMAGE img1, player* head, int steps);
void CharToTchar(const char * _char, TCHAR * tchar);
void displayhp(int x, int y, console *p1);
void displaymoney(int x, int y, console *p1);