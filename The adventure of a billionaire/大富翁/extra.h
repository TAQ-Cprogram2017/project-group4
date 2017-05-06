#pragma once
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include <conio.h>
#include <time.h>
void gotoxy(int x, int y);
typedef struct user //定义一个结构体，用来设置玩家的路径
{
	int x;
	int y;
	struct user *next;

}player;
//typedef void(*fun)(int *,int*);
player* creatpoint(int x, int y);
player* add(player *head, player *p);
void jump(player *head,int oredr);
player* initialize(int m, int n);
int suiji(int x);//随机数生成函数
void bomb(int *hp, int*money);
void delline();
player* sheet(int m, int n);
void moneyup(int *hp, int*money);
void runfunction(int *hp, int *money);
void fullenergy(int *hp, int*money);