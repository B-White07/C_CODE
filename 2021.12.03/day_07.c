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
		printf("��ѡ��ģʽ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("��Ϸ�����˳�\n");
			break;
		default:
			printf("��������Чѡ�\n");
			break;
		}
	} while (2 != input);

	return 0;
}