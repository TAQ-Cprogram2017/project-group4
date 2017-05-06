#include "extra.h"
//后续添加的操作函数最好都按照下列各式进行编写
void bomb(int *hp,int*money)
{
	int i = *hp;
	*hp = i - suiji(50);
	if (*hp <= 0)
		*hp = 0;
	//文字提示触发炸弹，并将提示在屏幕上保留一秒后清除
	gotoxy(7, 3);
	printf("You are booooombed!!!\a");
	Sleep(1000);
	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                                               ");
}
