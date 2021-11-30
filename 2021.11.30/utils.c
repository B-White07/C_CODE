#define _CRT_SECURE_NO_WARNINGS 1
//交换值，传值调用
void swap1(int x,int y)
{
	int tmp = 0;
	tmp = x;
	x = y;
	y = tmp;
}

//更正：实参需要改变，传指针。即传址调用
void swap2(int *pa, int *pb)
{
	int tmp = 0;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

