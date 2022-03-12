#include"Settings.h"
#include "MoveAction.h"


//�����¼�����
void KeyEvent() {
	int key = 0;
	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));//���300ms�ڼ��̻���
	key = getch();
	if (key == 224)//������ı�����ʱ�����224�룬ԭ����
		key = getch();
	//��ȡ���̰��� ��72 ��80 ��75 ��77

	switch (key)
	{
	case 72:
		MoveUp();
		break;
	case 80:
		MoveDown();
		break;
	case 75:
		MoveLeft();
		break;
	case 77:
		MoveRight();
		break;
	default:
		break;
	}
}

//�ƶ�
void MoveUp() {

	printf("Up\n");
	for (int i = 0; i < GRID_NUM; i++)//�б����
	{
		for (int beg = 1, temp = 0; beg < GRID_NUM; beg++)
		{
			if (g_map[beg][i] != 0) //Ѱ�ҷ����beg
			{
				if (g_map[temp][i] == 0) //tempΪ�գ���beg�ƶ���tempλ����
				{
					g_map[temp][i] = g_map[beg][i];
					g_map[beg][i] = 0;
				}
				else if (g_map[temp][i] == g_map[beg][i]) //temp��beg��ͬ����temp�ӱ���beg���
				{
					g_map[temp][i] = g_map[temp][i] * 2;
					g_Score = g_Score + g_map[temp][i];
					g_map[beg][i] = 0;
					temp++;
				}
				else //temp��beg��ͬ��
				{
					g_map[temp + 1][i] = g_map[beg][i];
					if (temp + 1 != beg) {
						g_map[beg][i] = 0;
					}
					++temp;
				}
			}
		}
	}
}
void MoveDown() {
	printf("Down\n");
	for (int i = 0; i < GRID_NUM; i++)
	{
		int temp = GRID_NUM - 1;
		for (int beg = GRID_NUM - 2; beg >= 0; beg--)
		{
			if (g_map[beg][i] != 0)
			{
				if (g_map[temp][i] == 0)
				{
					g_map[temp][i] = g_map[beg][i];
					g_map[beg][i] = 0;
				}
				else if (g_map[temp][i] == g_map[beg][i]) {
					g_map[temp][i] = g_map[temp][i] * 2;
					g_Score = g_Score + g_map[temp][i];
					g_map[beg][i] = 0;
					temp--;
				}
				else
				{
					g_map[temp - 1][i] = g_map[beg][i];
					if (temp - 1 != beg) {
						g_map[beg][i] = 0;
					}
					temp--;
				}
			}
		}
	}
}
void MoveLeft() {
	printf("Left\n");
	for (int i = 0; i < GRID_NUM; i++)
	{
		for (int beg = 1, temp = 0; beg < GRID_NUM; beg++)
		{
			if (g_map[i][beg] != 0)
			{
				if (g_map[i][temp] == 0)
				{
					g_map[i][temp] = g_map[i][beg];
					g_map[i][beg] = 0;
				}
				else if (g_map[i][temp] == g_map[i][beg])
				{
					g_map[i][temp] = g_map[i][temp] * 2;
					g_Score = g_Score + g_map[i][temp];
					g_map[i][beg] = 0;
					temp++;
				}
				else
				{
					g_map[i][temp + 1] = g_map[i][beg];
					if (temp + 1 != beg) {
						g_map[i][beg] = 0;
					}
					++temp;
				}
			}
		}
	}
}
void MoveRight() {
	printf("Right\n");
	for (int i = 0; i < GRID_NUM; i++)
	{
		int temp = GRID_NUM - 1;
		for (int beg = GRID_NUM - 2; beg >= 0; beg--)
		{
			if (g_map[i][beg] != 0)
			{
				if (g_map[i][temp] == 0)
				{
					g_map[i][temp] = g_map[i][beg];
					g_map[i][beg] = 0;
				}
				else if (g_map[i][temp] == g_map[i][beg]) {
					g_map[i][temp] = g_map[i][temp] * 2;
					g_Score = g_Score + g_map[i][temp];
					g_map[i][beg] = 0;
					temp--;
				}
				else
				{
					g_map[i][temp - 1] = g_map[i][beg];
					if (temp - 1 != beg) {
						g_map[i][beg] = 0;
					}
					temp--;
				}
			}
		}
	}
}


