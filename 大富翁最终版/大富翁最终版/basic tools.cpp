#include"extra.h"
player* creatpoint(int x, int y)//定义一个函数，路径的节点
{
	player *q = (player *)malloc(sizeof(player));
	q->next = NULL;
	q->x = x;
	q->y = y;
	q->func = random(50);
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
player* points()//建立路径，并将路径链表的首届点返回
{
	player* head;
	head = NULL;
	int x, y,i=0,temp=0;
	head = add(head, creatpoint(240, 100));
	for (x = 300, y =100;x <300+10*60;x = x + 60)
	{
			
		head = add(head, creatpoint(x, y));
		
	}
	for (;y < 100+10*60;y= y + 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;x > 900-10*60;x = x - 60)
	{

		head = add(head, creatpoint(x, y));
	}
	for (;y > 700 - 3 * 60;y = y - 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;x <300+3*60;x = x + 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;y > 520-2*60;y = y - 60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;x >480-6*60;x = x -60)
	{
		head = add(head, creatpoint(x, y));
	}
	for (;y <400+6*60;y = y + 60)
	{
		head = add(head, creatpoint(x, y));
		
	}
	head = add(head, creatpoint(60, 700));
	check(head);
	return head;

}
player* moveimg(IMAGE img1, player* head, int steps, console *p1)//img1是要移动的图片，输入的是要开始移动的链表节点，返回的是玩家移动后所处的链表节点
{
	player* temp = head;
	IMAGE img2, img3;
	IMAGE angel, bomb, satan, hpup, moneyplus, revive, start, end;
	loadimage(&angel, _T("IMG"), _T("angel1"), 60, 60);
	loadimage(&bomb, _T("IMG"), _T("bomb1"), 60, 60);
	loadimage(&satan, _T("IMG"), _T("satan1"), 60, 60);
	loadimage(&hpup, _T("IMG"), _T("HP1"), 60, 60);
	loadimage(&moneyplus, _T("IMG"), _T("money1"), 60, 60);
	loadimage(&revive, _T("IMG"), _T("revive1"), 60, 60);
	loadimage(&start, _T("IMG"), _T("start1"), 60, 60);
	loadimage(&end, _T("IMG"), _T("end1"), 60, 60);
	int i;
	putimage(head->x, head->y, &img1);//在第一个位置显示要移动的图片
	Sleep(100);
	
	for (i = 0;i<steps&&head != NULL;i++)
	{
		head = head->next;
		if (head == NULL)//防止链表越界导致程序崩溃
			return NULL;
		putimage(head->x, head->y, &img1);//在第二个位置显示指定的图片
		Sleep(100);
		if (temp->func == 1 || temp->func == 50)
		{
			putimage(temp->x, temp->y, &revive);
		}
		else
		{
			if (temp->func == 2)
			{
				putimage(temp->x, temp->y, &angel);
			}
			else
			{
				if (temp->func == 3)
				{
					putimage(temp->x, temp->y, &satan);
				}
				else
				{
					if (temp->func > 3 && temp->func <= 21)
					{
						putimage(temp->x, temp->y, &bomb);
					}
					else
					{
						if (temp->func > 21 && temp->func <= 44)
						{
							putimage(temp->x, temp->y, &moneyplus);
						}
						else
						{
							if (temp->func > 44 && temp->func <= 49)
							{
								putimage(temp->x, temp->y, &hpup);
							}
						}
					}
				}
			}
		}//以上从第一个if开始全部是在恢复第一个位置的图像
		Sleep(100);
		temp = temp->next;
	}

	return head;
}
void map(player* head)
{
	loadimage(NULL, _T("IMG"),_T("bgp1") ,1024,800);
	player* temp = head;
	IMAGE angel, bomb, satan, hpup, moneyplus, revive,start,end;
	loadimage(&angel, _T("IMG"),_T("angel1"), 60, 60);//将资源文件中的图片读取到内存中
	loadimage(&bomb, _T("IMG"),_T("bomb1"), 60, 60);
	loadimage(&satan,_T("IMG") ,_T("satan1"), 60, 60);
	loadimage(&hpup, _T("IMG"),_T("HP1"), 60, 60);
	loadimage(&moneyplus,_T("IMG"), _T("money1"), 60, 60);
	loadimage(&revive,_T("IMG") ,_T("revive1"), 60, 60);
	loadimage(&start,_T("IMG") ,_T("start1"), 60, 60);
	loadimage(&end,_T("IMG") ,_T("end1"), 60, 60);
	int i;
	putimage(temp->x, temp->y, &start);//显示起点图片
	temp = temp->next;
	while (temp->next)
	{
		if (temp->func == 1||temp->func==50)
		{
			putimage(temp->x, temp->y, &revive);
		}
		else
		{
			if (temp->func == 2)
			{
				putimage(temp->x, temp->y, &angel);//在坐标为（0,0）的地方显示指定图片
			}
			else
			{
				if (temp->func == 3)
				{
					putimage(temp->x, temp->y, &satan);
				}
				else
				{
					if (temp->func > 3 &&temp->func <= 21)
					{
						putimage(temp->x, temp->y, &bomb);
					}
					else
					{
						if (temp->func > 21 &&temp->func <= 44)
						{
							putimage(temp->x, temp->y, &moneyplus);
						}
						else
						{
							if (temp->func > 44 && temp->func <= 49)
							{
								putimage(temp->x, temp->y, &hpup);
							}
						}
					}
				}
			}
		}//根据方块类型显示对应图片
		temp = temp->next;

	}
	putimage(temp->x, temp->y, &end);//显示终点图片
}
void check(player *head)//保证路径中只有一个天使一个恶魔
{
	int i = 0,j=0,k=0;
	player *temp = head;
	while (temp)
	{
		if (temp->func == 2)
			j++;
		while (temp->func == 2 && j>1)
			temp->func = random(50);
		if (temp->func == 3)
			k++;
		while (temp->func == 3 && k >1)
			temp->func = random(50);
		temp = temp->next;
	}
}
bool ExtractResource(LPCTSTR strDstFile, LPCTSTR strResType, LPCTSTR strResName)//将资源文件中的MP3音乐读取至内存中
{
	// 创建文件
	HANDLE hFile = ::CreateFile(strDstFile, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_TEMPORARY, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;

	// 查找资源文件中、加载资源到内存、得到资源大小
	HRSRC	hRes = ::FindResource(NULL, strResName, strResType);
	HGLOBAL	hMem = ::LoadResource(NULL, hRes);
	DWORD	dwSize = ::SizeofResource(NULL, hRes);

	// 写入文件
	DWORD dwWrite = 0;  	// 返回写入字节
	::WriteFile(hFile, hMem, dwSize, &dwWrite, NULL);
	::CloseHandle(hFile);

	return true;
}
void CharToTchar(const char * _char, TCHAR * tchar)//实现char转换为TCHAR
{
	int iLength;
	iLength = MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, NULL, 0);
	MultiByteToWideChar(CP_ACP, 0, _char, strlen(_char) + 1, tchar, iLength);
}
int random(int x)//随机数生成函数
{
	int number;//variable for the random number
			   //use time function to form the random number
	number = 1 + rand() % x;  //make the random number from 1 to 6
	return number;
}