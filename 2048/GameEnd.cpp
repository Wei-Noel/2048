#include"Settings.h"
#include "GameEnd.h"
#include <graphics.h> 
void End_Win() {
	initgraph(323, 150);
	setbkcolor(RGB(255, 255, 255));//���ñ�����ɫ
	cleardevice();//������Ļ�������ñ�����������Ļ��

	IMAGE win_image;
	loadimage(&win_image,"you-win.jpg",150,150,true);
	putimage(86, 0,150,150, &win_image,0,0, SRCCOPY);

}
void End_Lost() {
	initgraph(323, 150);
	setbkcolor(RGB(0,0,0));
	cleardevice();

	IMAGE win_image;
	loadimage(&win_image, "you-lost.jpg", 150, 88, true);
	putimage(86, 0, 150, 88, &win_image, 0, 0, SRCCOPY);
}
