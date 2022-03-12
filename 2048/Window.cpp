#include "Settings.h"
#include "Window.h"
#include"Color.h"
//字体位置居中计算函数
int HorSpace(char text[]) {
	int horSpace = (GRID_WIDTH - textwidth(text)) / 2;
	return horSpace;
}
//字体位置居中计算函数
int VecSpace(char text[]) {
	int vecSpace = (GRID_WIDTH - textheight(text)) / 2;
	return vecSpace;
}
//绘制状态栏
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
	settextstyle(30, 0, "Microsoft Yahei");//字体大小和样式
	RECT r = { 0, 0, GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL, STATUS_BAR_HEIGHT };
	char score_ch[20];
	char score_text[20] = "Score:";
	sprintf(score_ch, "%d", score);
	strcat(score_text, score_ch);
	drawtext(score_text, &r, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
}
//绘制格子
void GridDraw() {
	for (int row = 0; row < GRID_NUM; row++)
	{
		for (int columns = 0; columns < GRID_NUM; columns++)
		{
			//坐标
			int x = columns * GRID_WIDTH + (columns + 1) * INTERVAL;
			int y = row * GRID_WIDTH + (row + 1) * INTERVAL + STATUS_BAR_HEIGHT;

			//设置填充颜色
			int colorIndex = log2(g_map[row][columns]);
			setfillcolor(color[colorIndex]);
			//画圆角矩形：四角，圆润程度
			solidroundrect(x, y, x + GRID_WIDTH, y + GRID_WIDTH, 50, 50);

			if (g_map[row][columns]) {
				//在格子中显示数字
				//设置字体格式
				settextcolor(RGB(119, 110, 101));
				setbkmode(TRANSPARENT);//字体背景透明
				settextstyle(50, 0, "Microsoft Yahei");//字体大小和样式

				char text[10] = { 0 };
				sprintf(text, "%d", g_map[row][columns]);
				outtextxy(x + HorSpace(text), y + VecSpace(text), text);//字体位置和输出内容
			}
		}
	}
}
void createWindow() {
	//创建图形窗口
	initgraph(GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL, GRID_NUM * GRID_WIDTH + (GRID_NUM + 1) * INTERVAL + STATUS_BAR_HEIGHT, EW_SHOWCONSOLE);
	//定义窗口长，宽，最后一个参数表示在图形界面显示的同时显示控制台

	//设置背景颜色
	setbkcolor(color[12]);
	cleardevice();//清理屏幕（先设置背景在清理屏幕）

}
