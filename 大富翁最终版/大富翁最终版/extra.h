#pragma once
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct user //定义一个结构体，用来设置玩家的路径
{
	int x;
	int y;
	int func;
	struct user *next;
}player;
typedef struct cons
{
	int revive;//用于监视复活状态
	int satan;//用于监视恶魔状态
	int angel;//用于监视天使状态
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