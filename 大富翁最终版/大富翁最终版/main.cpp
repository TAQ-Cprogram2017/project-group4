#include"extra.h"
void main()
{
	int i, j, step = 0;
	console* p1 = (console*)malloc(sizeof(console));
	srand(time(NULL));
	for (i = 0;1;i++)//i������¼��Ϸ���еĴ���
	{
		ExtractResource(_T("bgm1.mp3"), _T("MP3"), _T("BGM"));
		ExtractResource(_T("bgm2.mp3"), _T("MP3"), _T("BGM2"));
		p1->hp = 100;
		p1->money = 0;
		p1->satan = 0;
		p1->angel = 0;
		p1->revive = 0;//��ʼ�����״̬
		if (i == 0)//��һ�ν�����Ϸʱ���ű�������1����ʾ��ʼ�˵�
		{
			mciSendString(_T("open bgm1.mp3 alias bgm1"), NULL, 0, NULL);
			mciSendString(_T("play bgm1 repeat"), NULL, 0, NULL);//������Դ�ļ��еı�������
			initgraph(1024, 800);
			loadimage(NULL, _T("IMG"), _T("bgp11"), 1024, 800);
			settextstyle(75, 0, _T("΢���ź�"));
			TCHAR s[] = _T("Welcome");
			TCHAR b[] = _T("Press any key to continue");
			outtextxy(400, 150, s);
			settextstyle(50, 0, _T("΢���ź�"));
			outtextxy(300, 450, b);
			_getch();
			mciSendString(_T("stop bgm1"), NULL, 0, NULL);
			mciSendString(_T("close bgm1"), NULL, 0, NULL);
			mciSendString(_T("open bgm2.mp3 alias bgm2"), NULL, 0, NULL);//�����ѡ�������Ϸ��ʼ���ű�������2
		}
		else
		{
			closegraph();
			initgraph(1024, 800);
			mciSendString(_T("open bgm2.mp3 alias bgm2"), NULL, 0, NULL);//����Ϸ���д�������һ�Σ�ֱ�ӿ�ʼ��Ϸ������ʾ��ʼ����
		}
		mciSendString(_T("play bgm2 repeat"), NULL, 0, NULL);
		player* head = points();//����·��
		player* temp = head;
		IMAGE img1, img2, img3, img4;
		map(temp);//��ʾ��ͼ
		loadimage(&img1, _T("IMG"), _T("person"), 60, 60);//�������ʾ���
		displayhp(0, 0, p1);
		displaymoney(600, 0, p1);//��ʾ��Ǯ������

		while (1)
		{
			displayhp(0, 0, p1);
			displaymoney(600, 0, p1);//��ʾ��Ǯ������
			step = random(6);//����������ƶ�����
			_getch();//����Ұ��������ʱ��ʼ�ƶ�
			head = moveimg(img1, head, step, p1);//�ƶ����
			runfunc(head, p1);//�����������λ�õķ���
			displayhp(0, 0, p1);
			displaymoney(600, 0, p1);//��ʾ��Ǯ������
			if (head == NULL)//�����յ������ѭ��
				break;
			else
			{
				if (p1->satan == 1)//������ħ������ѭ��
					break;
				else
				{
					if (p1->angel == 1)//������ʹ������ѭ��
						break;
					else
					{
						if (p1->hp == 0 && p1->revive == 1)//����ֵ�����Ҵ��������򸴻�������Ϸ
							reviveaction(head, p1);
						else
						{
							if (p1->hp == 0)//����ֵ������û�и���ʱ����ѭ��
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
		if ((p1->hp == 0 || p1->money < 200 || p1->satan == 1) && p1->angel != 1)//�ж��Ƿ�ʧ�ܣ�ʧ������ʾ��ػ���Ͳ�����Ч
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
			if (p1->angel == 1 || p1->money >= 200)//�ж��Ƿ�ʤ����ʤ������ʾ��ػ��棬���Ҳ��������Ч
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
		loadimage(NULL, _T("IMG"), _T("bgp11"), 1024, 800);//��ʾ�����˵�
		TCHAR c[] = _T("Try again? (Y/N)");//��ʾ��Y��ʼ��һ�֣������������˳���Ϸ
		settextstyle(50, 0, _T("΢���ź�"));
		outtextxy(300, 450, c);
		fflush(stdin);
		j = _getch();//��ȡ�û��İ���
		while (j == '\r')//��ֹ֮ǰ��Ϊ�󰴻س�������ʶ�����
		{
			fflush(stdin);
			j = _getch();
		}
		if (j == 'y');//�����J����ʼ��һ��ѭ��
		else
			break;	//������ǣ�������Ϸ	
	}
	DeleteFile(_T("bgm1.mp3"));
	DeleteFile(_T("bgm2.mp3"));
	getchar();
}
