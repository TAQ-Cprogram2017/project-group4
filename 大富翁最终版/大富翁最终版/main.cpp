#include"extra.h"
void main()
{
	initgraph(800, 600);
	player* head = map();
	player* temp = head;
	IMAGE img1;
	loadimage(&img1, _T("1.jpg"),60,60);
	moveimg(img1, temp, 6);
	getchar();

}