#define _CRT_SECURE_NO_WARNINGS 1
#include"utils.h"
extern count = ROW * COL;
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		count = ROW * COL;
		menu();
		printf("请选择模式： ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("即将退出游戏\n");
			break;
		default:
			printf("无此选项，请重新选择\n");
			break;
		}
	} while (2!=input);
	return 0;
}