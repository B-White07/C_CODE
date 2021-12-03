#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"


int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	do
	{
	{
		menu();
		printf("请选择模式：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("游戏即将退出\n");
			break;
		default:
			printf("请输入有效选项：\n");
			break;
		}
	} while (2 != input);

	return 0;
}