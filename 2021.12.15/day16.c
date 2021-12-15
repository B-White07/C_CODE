#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
int main()
{
	//1.
	//int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//int k = 7;
	//int x = 3;
	//int y = 3;
	////&x，&y：1.传递值		2.带回结果
	//if (1 == yangFind2(a, &x, &y, k))
	//	printf("找到了，地址是：%d %d", x, y);
	//else
	//	printf("没找到。");

	//2.
	//char a[10] = "ABCDEF";
	//int n = 2;
	//strRotate2(a, n);
	//printf("%s", a);

	//3.
	//char arr1[20] = "AABCD";
	//char arr2[] = "BCD";
	//if (1 == isStrRotate2(arr1, arr2))
	//	printf("Y");
	//else
	//	printf("N");

	//三、字符串+内存函数的介绍
	//	1.字符串长度strlen		2.长度不受限制的字符串函数strcpy、strcat、strcmp	3.长度受限制的字符串函数介绍：strncpy、strncat、strncmp
	//	4.字符串查找strstr、strtok		5.错误信息报告strerror		6.字符操作
	//	7.内存操作函数memcpy、memmove、memset、memcmp

	//1.strlen --	1.算的是'\0'之前的		2.传递的字符串需要有'\0'		3.返回值是size_t，即无符号数
	//关于3.
	//if (strlen("abc") - strlen("abcdef") > 0)
	//	printf(">");// 3 - 6 = -3	但是-3被当作无符号数处理，此时-3的补码就是其原码，是一个很大的数字（4294967293），即 无符号数 +- 无符号数 = 无符号数	
	//else
	//	printf("<=");
	//printf("%u ", strlen("abc") - strlen("abcdef"));//4294967293


	//2.1strcpy	-- 1.拷贝的字符串需要包含\0，会将'\0'一同拷贝过去		2.拷贝过去的空间要足够大	3.目标空间必须可变
	//char arr[20] = "##########";
	////arr = "hello";//err		arr是一个地址常量，也就是一个编号，因此不能放入arr中，而应该存放到一个变量空间中。
	//char* p = "hello";//字符串传递的是首地址
	//char arr2[] = { 'a','b','c' };
	//strcpy(arr, arr2);//err，数组中没有'\0'，找不到结束标志
	//strcpy(arr, "hello");//遇到'\0'，会将'\0'一同拷贝过去，然后中止拷贝

	//char arr[5] = "####";
	//char* p = "hello world";
	//strcpy(arr, p);//会拷贝过去，但是程序会崩溃
	//printf("%s", arr);

	//char* str = "xxxxxxx";
	//char* p = "hello world";
	//strcpy(str, p);//目标空间是常量字符串，不可变，程序崩溃
	//printf("%s", str);
	//printf("%c","123456"[3]);//4	说明"" 表示的其实就是首元素的地址


	//2.2strcat字符串追加	1.目标空间要有足够空间		2.会覆盖目标空间的\0，且自己的\0会被带过去，因此需要\0		3.目标空间可修改
	//char arr1[20] = "hello \0##########";
	//char arr2[] = "world";
	//strcat(arr1, arr2);//字符串追加（连接）
	//printf("%s", arr1);
	//模拟实现
	//char arr1[20] = "hello ";
	//char arr2[] = "world";
	//printf("%s", myStrcat(arr1, arr2));//字符串追加（连接）
	//为什么不能自己追加自己：自己的\0被覆盖了，找不到\0，因此崩溃


	//2.3strcmp比较字符串，字符串不能用> < =比较，用这三者比较比较的是其首元素的地址，而地址是随机分配的，因此比较没有意义
	//strcmp比较对应位置的ACSLL码值，直到出现了不一样的字符，那么大的ASCLL为大，遇到\0停止比较
	//char* p = "obc";
	//char* q = "abcdef";
	//printf("%d\n", strcmp(p, q));
	//printf("%d\n", strcmp("abc", "abcdef"));
	//模拟实现
	//char* p = "obc";
	//char* q = "abcdef";
	//int ret = myStrcmp(p, q);//没有改变p和q的指向
	//if (0 < ret)
	//	printf("p > q\n");
	//else if(0 > ret)
	//	printf("p < q\n");
	//else
	//	printf("p == q\n");


	//3.1strncpy
	//char arr1[20] = "abcdefghi";
	//char arr2[] = "qwer";
	//strncpy(arr1, arr2, 6);//不够的用\0补
	//printf("%s", arr1);//qwer

	//3.2strncat
	//char arr1[20] = "hello ";
	//char arr2[] = "world";
	//strncat(arr1, arr2, 2);//遇到\0就结束追加，结束时也会加上\0
	//printf("%s", arr1);//hello wo

	//3.3strncmp
	//char arr1[20] = "abcde";
	//char arr2[] = "abcdefgh";
	//printf("%d", strncmp(arr1, arr2, 3));//比较给定的个数


	//4.1strstr，找子串，若有返回第一次出现的地址；找不到返回空指针
	//char arr1[] = "abbbcdefghijk";
	//char arr2[] = "bbc";
	////char* ret = strstr(arr1, arr2);//在arr1中找arr2
	//char* ret = myStrstr(arr1, arr2);//在arr1中找arr2
	//if (ret == NULL)
	//	printf("没找到\n");
	//else
	//	printf("找到了，%s\n", ret);

	//4.2strtok切割字符串，会改变被切割字符串的内容，将标记改为\0，并保存这个标记的位置
	//strtok第一个参数不是NULL：从传入的位置开始找，找到标记后将标记改为\0，并记录这个位置
	//strtok第一个参数是NULL：从上一个记录的位置开始找，找到标记后将标记改为\0，并记录这个位置
	//char* strtok(char* str,const char* sep)
	//char arr[] = "fudan@daxue.com";
	//char* p = "@.";
	//char tmp[20] = { 0 };//防止被切割字符串被改变
	//strcpy(tmp, arr);
	//char* ret = NULL;
	//for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
	//	printf("%s\n", ret);

	//printf("%s\n", strtok(tmp, p));
	//printf("%s\n", strtok(NULL, p));
	//printf("%s\n", strtok(NULL, p));


	//5.错误信息报告strerror
	//在调用库函数失败的时候，都会设置错误码，此函数将错误码翻译成错误信息，返回这个错误信息的首地址
	//c语言有一个全局变量来保存错误码：int errno;
	//char* strerror(int errnum)	errnum为错误码
	//printf("%s\n",strerror(0));
	//printf("%s\n",strerror(1));
	//printf("%s\n",strerror(2));
	//printf("%s\n",strerror(3));
	//printf("%s\n",strerror(4));
	//printf("%s\n",strerror(5));
	//FILE* pf = fopen("test.txt", "r");
	//if (pf == NULL)//返回NULL表示打开文件失败
	//{
	//	printf("%s\n", strerror(errno));//失败，错误码保存在errno中，调用函数翻译打印失败的原因
	//	return 1;
	//}
	//fclose(pf);
	//pf = NULL;
	//	

	return 0;
}