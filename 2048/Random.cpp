#include"Settings.h"
#include "Random.h"
#include"GameEnd.h"


int rando2Or4() //���������2��4
{

	if (rand() % 5 == 4) //20%��������4
	{
		return 4;
	}
	else
	{
		return 2;
	}
}
//����������������
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
//����2�������
void init() {
	if (IsZero() < 2) {
		printf("��Ϸ����");
		End_Lost();
		getchar();
	}
	else {
		CreateNumber();
		CreateNumber();
	}

}