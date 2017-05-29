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
typedef struct console
{
	int angel;
	int plus1s;
};
player* creatpoint(int x, int y);
player* add(player *head, player *p);
int random(int x);
player* map();
void moveimg(IMAGE img1, player* head, int steps);