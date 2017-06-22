#include"extra.h"
void displayhp(int x, int y, console *p1)
{
	settextstyle(25, 0, _T("Î¢ÈíÑÅºÚ"));
	TCHAR s[] = _T("            ");
	outtextxy(x, y, s);
	char a[9];
	sprintf(a, "HP=%d", p1->hp);
	TCHAR b[10];
	CharToTchar(a, b);
	outtextxy(x, y, b);
	setfillcolor(BLACK);
	fillrectangle(x, y + 25, x + 400, y + 85);
	if (p1->hp >= 60)
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
		fillrectangle(x, y + 25, x + p1->hp * 4, y + 85);
	Sleep(100);
}
void displaymoney(int x, int y, console *p1)
{
	char a[9];
	sprintf(a, "MONEY=%d", p1->money);
	TCHAR b[10];
	CharToTchar(a, b);
	settextstyle(25, 0, _T("Î¢ÈíÑÅºÚ"));
	outtextxy(x, y, b);
	setfillcolor(BLACK);
	fillrectangle(x, y + 25, x + 400, y + 85);
	setlinecolor(RED);
	line(x + 0.67 * 400, y + 25, x + 0.67 * 400, y + 85);
	setfillcolor(YELLOW);
	fillrectangle(x, y + 25, x + p1->money*1.33, y + 85);
}