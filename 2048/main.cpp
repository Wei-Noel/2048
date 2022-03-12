#include"Random.h"
#include"Settings.h"
#include"MoveAction.h"
#include"Window.h"

//存储数字
int g_map[GRID_NUM][GRID_NUM] = {};
int g_Score = 0;

int main() {
	//设置随机数种子
	srand(time(NULL));
	//创建窗口
	createWindow();
	while (true)
	{
		init();
		BarDraw();
		GridDraw();
		KeyEvent();
		GridDraw();
		Sleep(300);
	}

	getchar();
	return 0;
}

