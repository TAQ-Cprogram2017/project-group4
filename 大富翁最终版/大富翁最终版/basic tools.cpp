#include"extra.h"
player* creatpoint(int x, int y)//����һ������������ÿһ��·���Ľڵ�
{
	player *q = (player *)malloc(sizeof(player));
	q->next = NULL;
	q->x = x;
	q->y = y;
	q->func = random(50);
	return q;
}
player* add(player *head, player *p)//����һ�����������ڵ㰴���Ⱥ�˳�����ӣ����������
{
	if (head == NULL)
		return p;
	else
	{
		player *temp = head;
		for (;temp->next;temp = temp->next);//�л������һ��Ԫ��
		temp->next = p;
		return head;
	}
}
int random(int x)//��������ɺ���
{
	int number;//variable for the random number
	srand((unsigned)time(NULL)); //use time function to form the random number
	number = 1 + rand() % x;  //make the random number from 1 to 6
	return number;
}
player* map()
{
	player* head;
	head = NULL;
	int x, y,i=0;
	for (x = 100, y =0;x <700;x = x + 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;y < 480;y= y + 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;x > 100;x = x - 60)
	{
		head = add(head, creatpoint(x, y));
	}
	y = y - 60;
	creatpoint(x, y);
	y = y - 60;
	creatpoint(x, y);

	for (;x <460;x = x + 60)
	{
		head = add(head, creatpoint(x, y));
	}
	y = y - 60;
	creatpoint(x, y);
	y = y - 60;
	creatpoint(x, y);
	for (;x >40;x = x - 60)
	{
		head = add(head, creatpoint(x, y));
	}
	while (i < 5)
	{
		y = y + 60;
		creatpoint(x, y);
		i++;
	}
	return head;

}
void moveimg(IMAGE img1,player* head,int steps)//img1��Ҫ�ƶ���ͼƬ
{
	IMAGE img2;
	int i;
	BeginBatchDraw();
	for(i=0;i<=steps;i++)
	{
		getimage(&img2, head->x, head->y, 60, 60);
		putimage(head->x, head->y, &img1);
		FlushBatchDraw();
		Sleep(200);
		putimage(head->x, head->y, &img2);
		head = head->next;
	}
}
void CharToTchar(const char * _char, TCHAR * tchar)
{
	int iLength;
	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}