#include<easyx.h>

enum Color
{
	twoTO0 = RGB(205, 193, 180),	//0的颜色
	twoTO1 = RGB(238, 228, 218),	//2的颜色
	twoTO2 = RGB(237, 224, 200),	//4的颜色
	twoTO3 = RGB(242, 177, 121),	//8的颜色
	twoTO4 = RGB(245, 149, 99),		//16的颜色
	twoTO5 = RGB(246, 124, 95),		//32的颜色
	twoTO6 = RGB(246, 94, 59),		//64的颜色
	twoTO7 = RGB(242, 177, 121),	//128的颜色
	twoTO8 = RGB(237, 204, 97),		//256的颜色
	twoTO9 = RGB(244, 96, 108),		//512的颜色
	twoTO10 = RGB(103, 105, 251),	//1024的颜色
	twoTO11 = RGB(128, 78, 229),	//2048的颜色
	back = RGB(187, 173, 160),		//背景的颜色
};
Color color[13] = { twoTO0,twoTO1,twoTO2 ,twoTO3,twoTO4 ,twoTO5 ,twoTO6 ,twoTO7 ,twoTO8 ,twoTO9 ,twoTO10 ,twoTO11,back };