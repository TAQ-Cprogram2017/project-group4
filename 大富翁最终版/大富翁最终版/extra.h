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