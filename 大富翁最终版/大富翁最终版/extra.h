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
typedef struct user //����һ���ṹ�壬������Ϊ·������Ľڵ�
{
	int x;
	int y;//��ʾ�����λ��
	int func;//��ʾ���������
	struct user *next;//��һ���ڵ��ָ��
}player;
typedef struct cons//�����洢���״̬�Ľṹ��
{
	int revive;//���ڼ��Ӹ���״̬
	int satan;//���ڼ��Ӷ�ħ״̬
	int angel;//���ڼ�����ʹ״̬
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