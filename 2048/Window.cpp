#include "Settings.h"
#include "Window.h"
#include"Color.h"
//����λ�þ��м��㺯��
int HorSpace(char text[]) {
	int horSpace = (GRID_WIDTH - textwidth(text)) / 2;
	return horSpace;
}
//����λ�þ��м��㺯��
int VecSpace(char text[]) {
	int vecSpace = (GRID_WIDTH - textheight(text)) / 2;
	return vecSpace;
}
//����״̬��
void BarDraw() {
	setfillcolor(RGB(187, 173, 160));
	setlinecolor(RGB(187, 173, 160));
	setbkmode(TRANSPARENT);
	fillrectangle(0, 0, GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL, STATUS_BAR_HEIGHT);
	ScoreDraw(g_Score);
}
void ScoreDraw(int score) {
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(30, 0, "Microsoft Yahei");//�����С����ʽ
	RECT r = { 0, 0, GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL, STATUS_BAR_HEIGHT };
	char score_ch[20];
	char score_text[20] = "Score:";
	sprintf(score_ch, "%d", score);
	strcat(score_text, score_ch);
	drawtext(score_text, &r, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//���Ƹ���
void GridDraw() {
	for (int row = 0; row < GRID_NUM; row++)
	{
		for (int columns = 0; columns < GRID_NUM; columns++)
		{
			//����
			int x = columns * GRID_WIDTH + (columns + 1) * INTERVAL;
			int y = row * GRID_WIDTH + (row + 1) * INTERVAL + STATUS_BAR_HEIGHT;

			//���������ɫ
			int colorIndex = log2(g_map[row][columns]);
			setfillcolor(color[colorIndex]);
			//��Բ�Ǿ��Σ��Ľǣ�Բ��̶�
			solidroundrect(x, y, x + GRID_WIDTH, y + GRID_WIDTH, 50, 50);

			if (g_map[row][columns]) {
				//�ڸ�������ʾ����
				//���������ʽ
				settextcolor(RGB(119, 110, 101));
				setbkmode(TRANSPARENT);//���屳��͸��
				settextstyle(50, 0, "Microsoft Yahei");//�����С����ʽ

				char text[10] = { 0 };
				sprintf(text, "%d", g_map[row][columns]);
				outtextxy(x + HorSpace(text), y + VecSpace(text), text);//����λ�ú��������
			}
		}
	}
}
void createWindow() {
	//����ͼ�δ���
	initgraph(GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL, GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL + STATUS_BAR_HEIGHT, EW_SHOWCONSOLE);
	//���崰�ڳ��������һ��������ʾ��ͼ�ν�����ʾ��ͬʱ��ʾ����̨

	//���ñ�����ɫ
	setbkcolor(color[12]);
	cleardevice();//������Ļ�������ñ�����������Ļ��

}
