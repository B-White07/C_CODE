#define _CRT_SECURE_NO_WARNINGS 1

//��һ���������ڴ��ж�����λΪ1�ĸ���
int	numOfBin(int n)
{
	int count = 0;
	int flag = 1;
	int b = 0;
	for (int i = 0; i < 32; i++)
	{
		flag = (n >> i) & 1;
		if (1 == flag)
			count++;
	}
	return count;
}