#include"Random.h"
#include"Settings.h"
#include"MoveAction.h"
#include"Window.h"

//�洢����
int g_map[GRID_NUM][GRID_NUM] = {};
int g_Score = 0;

int main() {
	//�������������
	srand(time(NULL));
	//��������
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

