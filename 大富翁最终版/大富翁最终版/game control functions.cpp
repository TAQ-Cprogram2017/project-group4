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
