#define _CRT_SECURE_NO_WARNINGS 1
//����ֵ����ֵ����
void swap1(int x,int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

//������ʵ����Ҫ�ı䣬��ָ�롣����ַ����
void swap2(int *pa, int *pb)
{
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

