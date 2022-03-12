#include"Settings.h"
#include "Random.h"
#include"GameEnd.h"


int rando2Or4() //生成随机数2或4
{

	if (rand() % 5 == 4) //20%几率生成4
	{
		return 4;
	}
	else
	{
		return 2;
	}
}
//在数组中填充随机数
void CreateNumber() {
	while (true) {
		int r = rand() % GRID_NUM;
		int c = rand() % GRID_NUM;
		if (g_map[r][c] == 0) {
			g_map[r][c] = rando2Or4();
			break;
		}
	}
}

int IsZero() {
	int flag = 0;
	for (int i = 0; i < GRID_NUM; i++)
	{
		for (int j = 0; j < GRID_NUM; j++)
		{
			if (g_map[i][j] == 0) {
				flag++;
			}
			else if (g_map[i][j] > 1024) {
				End_Win();
				getchar();
			}
		}
	}
	return flag;
}
//生成2个随机数
void init() {
	if (IsZero() < 2) {
		printf("游戏结束");
		End_Lost();
		getchar();
	}
	else {
		CreateNumber();
		CreateNumber();
	}

}