#include "extra.h";
player* initialize(int m, int n)//make a function to make a sheet(m*n)and set points
{
	int i, a, b, c, d,e=1,f=1;
	player *head,*temp;
	printf(" ");//for give a lookful line,give a " "at the first line
	for (i = 0; i <= m; i++)//circlation for the first lined
		printf("______ ");//make the top of the sheet
	printf("\n");//change the line(the same to follow)
	printf("|");//make the first left line of the first row
	for (b = 0; b < n - 1; b++)//circlation for the list
	{
		for (a = 0; a < n; a++)
			printf("      |");//make the first list line for the row
		printf("\n");
		printf("|");//make the left line for the second list line of the row
		for (c = 0; c < n; c++)
			printf("      |");//make the second list line for the row 
		printf("\n");
		printf("|");//make the left line for the third list line of the row
		for (d = 0; d < n; d++)
			printf("______|");//make the third list line for the row
		printf("\n");
		printf("|");//make the left line for the first line of the next row
	}
	if (b = n - 1)//we don't need the left line after the last line
	{
		for (a = 0; a < n; a++)
			printf("      |");
		printf("\n");
		printf("|");
		for (c = 0; c < n; c++)
			printf("      |");
		printf("\n");
		printf("|");
		for (d = 0; d < n; d++)
			printf("______|");
		printf("\n");//the same as up
	}
	head = NULL;
	e = 1;
	f = 1;
		//建立环状路径
		for (;f <= n;f++)//建立第一列的路径点
		{
			head = add(head, creatpoint(e, f));
		}
		for (e++,f--;e <= m; e++)//建立最后一行的路径点
		{
			head = add(head, creatpoint(e, f));
		}
		for (e--,f--;f >= 1;f--)//从最后一行倒退回第一行，并沿途建立路径
		{
			head = add(head, creatpoint(e, f));

		}
		for (f++,e--;e >= 1;e--)//从最后一列倒回第一列，并沿途建立路径
		{
			head = add(head, creatpoint(e, f));
		}
		temp = head;
		while (temp->next != NULL)//将最后一个路径点的下一个指向第一个，使整个路径封闭
			temp = temp->next;
		temp->next = head;
		return head;
}
void gotoxy(int x, int y)
{
	COORD coord = { 8+7*(x-1)-4 , 1+y*3-2 };
	/*COORD是Windows PI中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：

	typedef struct _COORD {

	SHORT X; // horizontal coordinate

	SHORT Y; // vertical coordinate
	} COORD;*/

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
player* creatpoint(int x, int y)//定义一个函数，创建每一个路径的节点
{
	player *q = (player *)malloc(sizeof(player));
	q->next = NULL;
	q->x = x;
	q->y = y;
	return q;
}
player* add(player *head, player *p)//定义一个函数，将节点按照先后顺序连接，先输的先连
{
	if (head == NULL)
		return p;
	else
	{
		player *temp = head;
		for (;temp->next;temp = temp->next);//切换到最后一个元素
		temp->next = p;
		return head;
	}
}
void jump(player *head,int order)//让玩家跳到指定地点
{
	int i;//计数变量
	player *temp_1 = head;//temp_1 is to print the position of the player
	player *temp_2 = head;//temp_2 is to delete(cover) the former position
	gotoxy(temp_1->x, temp_1->y);//goto the first point
	printf("@");//print the player
	Sleep(200);
	for(i=1;i<order;i++)
	{
		temp_1 = temp_1->next;//防止输入的是最后一个而导致对空指针进行操作而使程序崩溃
		if (temp_1 == NULL)
			return;
		else
		{
			gotoxy(temp_1->x, temp_1->y);//goto the next position
			printf("@");//print a new player
			Sleep(200);
			gotoxy(temp_2->x, temp_2->y);//return to the former position
			printf(" ");//use "___"to cover last player
			temp_2 = temp_2->next;
		}
		}
		
}
int suiji(int x)//随机数生成函数
{
	int number;//variable for the random number
	srand((unsigned)time(NULL)); //use time function to form the random number
	number = 1 + rand() % x;  //make the random number from 1 to 6
	return number;
}
void delline()//暴力删除一行中光标之后所有内容= = 并使光标回到行首
{
	printf("\r                                                                                                                                                                              \r");
}
void runfunction(int *hp,int *money)
{
	int i = suiji(2);
	switch (i)
	{
	case 1:
		bomb(hp, money);
	default:
		return;
	}
}