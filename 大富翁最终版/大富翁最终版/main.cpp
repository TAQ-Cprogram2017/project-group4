#include"extra.h"
void main()
{
	int i, j, step = 0;
	console* p1 = (console*)malloc(sizeof(console));
	srand(time(NULL));
	for (i = 0;1;i++)//i用来记录游戏进行的次数
	{
		ExtractResource(_T("bgm1.mp3"), _T("MP3"), _T("BGM"));
		ExtractResource(_T("bgm2.mp3"), _T("MP3"), _T("BGM2"));
		p1->hp = 100;
		p1->money = 0;
		p1->satan = 0;
		p1->angel = 0;
		p1->revive = 0;//初始化玩家状态
		if (i == 0)//第一次进入游戏时播放背景音乐1并显示开始菜单
		{
			mciSendString(_T("open bgm1.mp3 alias bgm1"), NULL, 0, NULL);
			mciSendString(_T("play bgm1 repeat"), NULL, 0, NULL);//播放资源文件中的背景音乐
			initgraph(1024, 800);
			loadimage(NULL, _T("IMG"), _T("bgp11"), 1024, 800);
			settextstyle(75, 0, _T("微软雅黑"));
			TCHAR s[] = _T("Welcome");
			TCHAR b[] = _T("Press any key to continue");
			outtextxy(400, 150, s);
			settextstyle(50, 0, _T("微软雅黑"));
			outtextxy(300, 450, b);
			_getch();
			mciSendString(_T("stop bgm1"), NULL, 0, NULL);
			mciSendString(_T("close bgm1"), NULL, 0, NULL);
			mciSendString(_T("open bgm2.mp3 alias bgm2"), NULL, 0, NULL);//在玩家选择进入游戏后开始播放背景音乐2
		}
		else
		{
			closegraph();
			initgraph(1024, 800);
			mciSendString(_T("open bgm2.mp3 alias bgm2"), NULL, 0, NULL);//若游戏进行次数超过一次，直接开始游戏，不显示开始画面
		}
		mciSendString(_T("play bgm2 repeat"), NULL, 0, NULL);
		player* head = points();//建立路径
		player* temp = head;
		IMAGE img1, img2, img3, img4;
		map(temp);//显示地图
		loadimage(&img1, _T("IMG"), _T("person"), 60, 60);//在起点显示玩家
		displayhp(0, 0, p1);
		displaymoney(600, 0, p1);//显示金钱及生命

		while (1)
		{
			displayhp(0, 0, p1);
			displaymoney(600, 0, p1);//显示金钱及生命
			step = random(6);//产生随机的移动步数
			_getch();//待玩家按下任意键时开始移动
			head = moveimg(img1, head, step, p1);//移动玩家
			runfunc(head, p1);//触发玩家所处位置的方块
			displayhp(0, 0, p1);
			displaymoney(600, 0, p1);//显示金钱及生命
			if (head == NULL)//到达终点后跳出循环
				break;
			else
			{
				if (p1->satan == 1)//遇到恶魔后跳出循环
					break;
				else
				{
					if (p1->angel == 1)//遇到天使后跳出循环
						break;
					else
					{
						if (p1->hp == 0 && p1->revive == 1)//生命值归零且触发复活则复活后继续游戏
							reviveaction(head, p1);
						else
						{
							if (p1->hp == 0)//生命值归零且没有复活时跳出循环
								break;
						}
					}
				}
			}
		}
		mciSendString(_T("stop bgm2"), NULL, 0, NULL);
		mciSendString(_T("close bgm2"), NULL, 0, NULL);
		DeleteFile(_T("bgm1.mp3"));
		DeleteFile(_T("bgm2.mp3"));
		if ((p1->hp == 0 || p1->money < 200 || p1->satan == 1) && p1->angel != 1)//判断是否失败，失败则显示相关画面和播放音效
		{
			closegraph();
			initgraph(1366, 768);
			loadimage(NULL, _T("IMG"), _T("defeat1"), 1366, 768);
			PlaySound(NULL, NULL, NULL);
			PlaySound(_T("slain"), GetModuleHandle(0), SND_RESOURCE | SND_SYNC);
			fflush(stdin);
		}
		else
		{
			if (p1->angel == 1 || p1->money >= 200)//判断是否胜利，胜利则显示相关画面，并且播放相关音效
			{
				closegraph();
				initgraph(1366, 768);
				loadimage(NULL, _T("IMG"), _T("victor1"), 1366, 768);
				PlaySound(NULL, NULL, NULL);
				PlaySound(_T("victory"), GetModuleHandle(0), SND_RESOURCE | SND_SYNC);
			}
		}
		closegraph();
		initgraph(1024, 800);
		loadimage(NULL, _T("IMG"), _T("bgp11"), 1024, 800);//显示结束菜单
		TCHAR c[] = _T("Try again? (Y/N)");//提示按Y开始下一局，按其它键则退出游戏
		settextstyle(50, 0, _T("微软雅黑"));
		outtextxy(300, 450, c);
		fflush(stdin);
		j = _getch();//获取用户的按键
		while (j == '\r')//防止之前因为误按回车而导致识别错误
		{
			fflush(stdin);
			j = _getch();
		}
		if (j == 'y');//如果是J，则开始下一次循环
		else
			break;	//如果不是，结束游戏	
	}
	DeleteFile(_T("bgm1.mp3"));
	DeleteFile(_T("bgm2.mp3"));
	getchar();
}
