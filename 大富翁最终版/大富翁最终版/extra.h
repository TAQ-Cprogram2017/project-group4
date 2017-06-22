#pragma once
#include<afx.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"resource.h"
#include <iostream>
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib") 
typedef struct user //定义一个结构体，用来作为路径链表的节点
{
	int x;
	int y;//表示方块的位置
	int func;//表示方块的类型
	struct user *next;//下一个节点的指针
}player;
typedef struct cons//用来存储玩家状态的结构体
{
	int revive;//用于监视复活状态
	int satan;//用于监视恶魔状态
	int angel;//用于监视天使状态
	int hp;
	int money;
}console;
player* creatpoint(int x, int y);
player* add(player *head, player *p);
int random(int x);
player* points();
player* moveimg(IMAGE img1, player* head, int steps, console *p1);
void map(player* head);
//void check(player *head);
void CharToTchar(const char * _char, TCHAR * tchar);
void displayhp(int x, int y, console *p1);
void displaymoney(int x, int y, console *p1);
void moneyplus(player *head, console *p1);
void bomb(player *head, console *p1);
void hpplus(player *head, console *p1);
void angel(player *head, console *p1);
void satan(player *head, console *p1);
void revive(player *head, console *p1);
void runfunc(player *head, console *p1);
void reviveaction(player *head, console *p1);
void check(player *head);
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName);