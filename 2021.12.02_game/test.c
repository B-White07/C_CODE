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
		printf("��ѡ��ģʽ�� ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			printf("�����˳���Ϸ\n");
			break;
		default:
			printf("�޴�ѡ�������ѡ��\n");
			break;
		}
	} while (2!=input);
	return 0;
}