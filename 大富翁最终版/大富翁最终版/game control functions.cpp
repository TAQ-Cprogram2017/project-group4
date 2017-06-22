#include"extra.h"
void displayhp(int x, int y, console *p1)//显示HP
{
	settextstyle(25, 0, _T("微软雅黑"));
	TCHAR s[] = _T("            ");//先将用于显示HP的位置清空，防止HP由三位数变两位数的时候最后一位仍然剩下一个0
	outtextxy(x, y, s);
	char a[9];
	sprintf(a, "HP=%d", p1->hp);//用数字显示HP
	TCHAR b[10];
	CharToTchar(a, b);
	outtextxy(x, y, b);
	setfillcolor(BLACK);
	fillrectangle(x, y + 25, x + 400, y + 85);//将血条的位置用黑色条来覆盖，方便后续动态显示HP
	if (p1->hp >= 60)//根据剩余血量的切换血条颜色
		setfillcolor(GREEN);
	else
	{
		if (p1->hp >= 20 && p1->hp<60)
			setfillcolor(YELLOW);
		else
		{
			if (p1->hp<20)
				setfillcolor(RED);
		}
	}
	if (p1->hp >= 100)
		fillrectangle(x, y + 25, x + 400, y + 85);
	else
		fillrectangle(x, y + 25, x + p1->hp * 4, y + 85);//根据剩余HP的量显示血条
	Sleep(100);
}
void displaymoney(int x, int y, console *p1)
{
	char a[9];
	sprintf(a, "MONEY=%d", p1->money);
	TCHAR b[10];
	CharToTchar(a, b);
	settextstyle(25, 0, _T("微软雅黑"));
	outtextxy(x, y, b);
	setfillcolor(BLACK);
	fillrectangle(x, y + 25, x + 400, y + 85);
	setlinecolor(RED);
	line(x + 0.67 * 400, y + 25, x + 0.67 * 400, y + 85);
	setfillcolor(YELLOW);
	fillrectangle(x, y + 25, x + p1->money*1.33, y + 85);
}
void bomb(player *head, console *p1)
{
	IMAGE img1;
	if (head->func > 3 && head->func <= 21)
	{
		p1->hp = p1->hp - random(40);
		if (p1->hp <= 0)
			p1->hp = 0;
		getimage(&img1, 0, 0, 1024, 800);//截取当前游戏界面
		cleardevice();//清屏
		loadimage(NULL, _T("IMG"), _T("boom"), 1024, 768);//显示被炸以后的图片
		PlaySound(_T("bombbgm"), GetModuleHandle(0), SND_RESOURCE | SND_ASYNC);//播放炸弹音效
		Sleep(1500);
		putimage(0, 0, &img1);//将游戏画面恢复
	}
}
void moneyplus(player *head, console *p1)
{
	if (head->func > 21 && head->func <= 44)
	{
		p1->money = p1->money + 35;
		PlaySound(_T("getmoney"), GetModuleHandle(0), SND_RESOURCE | SND_ASYNC);
		Sleep(200);
	}
}
void hpplus(player *head, console *p1)
{
	if (head->func > 44 && head->func <50)
	{
		p1->hp = p1->hp + 10;
		PlaySound(_T("hpup"), GetModuleHandle(0), SND_RESOURCE | SND_SYNC);
		Sleep(100);
	}

}
void angel(player *head, console *p1)
{
	if (head->func == 2)
	{
		p1->angel = 1;
		closegraph();
		initgraph(1600, 900);
		loadimage(NULL, _T("IMG"), _T("heroneverdie"), 1600, 900);
		mciSendString(_T("stop bgm2"), NULL, 0, NULL);//将背景音乐停止
		mciSendString(_T("close bgm2"), NULL, 0, NULL);
		Sleep(1000);
		_getch();
	}
}
void satan(player *head, console *p1)
{
	if (head->func == 3)
	{
		p1->satan = 1;
		closegraph();
		initgraph(672, 444);
		loadimage(NULL, _T("IMG"), _T("meetsatan"), 672, 444);
		mciSendString(_T("stop bgm2"), NULL, 0, NULL);
		mciSendString(_T("close bgm2"), NULL, 0, NULL);
		PlaySound(_T("Lucian"), GetModuleHandle(0), SND_RESOURCE | SND_ASYNC);
		Sleep(2000);
		_getch();
	}
}
void revive(player *head, console *p1)
{
	IMAGE img1;
	if (head->func == 1 || head->func == 50)
	{
		p1->revive = 1;
		loadimage(&img1, _T("IMG"), _T("revive1"), 60, 60);//用图片提示具有复活光环
		putimage(470, 0, &img1);

	}
}
void runfunc(player *head, console *p1)
{
	if (head == NULL)
	{
		return;
	}
	moneyplus(head, p1);
	bomb(head, p1);
	hpplus(head, p1);
	angel(head, p1);
	satan(head, p1);
	revive(head, p1);
}
void reviveaction(player *head, console *p1)
{
	IMAGE img1;
	p1->hp = p1->hp + 100;
	getimage(&img1, 0, 0, 1024, 800);//截取当前游戏界面
	closegraph();
	initgraph(1273, 716);
	loadimage(NULL, _T("IMG"), _T("meetangel"), 1273, 716);//关闭当前窗口并重新开启一个窗口显示复活的图片
	mciSendString(_T("stop bgm2"), NULL, 0, NULL);//停止背景音乐
	PlaySound(_T("neverdie"), GetModuleHandle(0), SND_RESOURCE | SND_SYNC);//播放复活音效
	mciSendString(_T("play bgm2 repeat"), NULL, 0, NULL);//播放背景音乐
	Sleep(100);
	closegraph();
	initgraph(1024, 800);
	putimage(0, 0, &img1);//重新打开游戏窗口，显示游戏界面
	setfillcolor(GREEN);
	fillrectangle(470, 0, 530, 60);//将原本用于显示具有复活光环的部分遮住，避免误会
}
