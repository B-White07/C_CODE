#define _CRT_SECURE_NO_WARNINGS 1
#include "utils.h"
int main()
{
	//1.
	//int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	//int k = 7;
	//int x = 3;
	//int y = 3;
	////&x��&y��1.����ֵ		2.���ؽ��
	//if (1 == yangFind2(a, &x, &y, k))
	//	printf("�ҵ��ˣ���ַ�ǣ�%d %d", x, y);
	//else
	//	printf("û�ҵ���");

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

	//�����ַ���+�ڴ溯���Ľ���
	//	1.�ַ�������strlen		2.���Ȳ������Ƶ��ַ�������strcpy��strcat��strcmp	3.���������Ƶ��ַ����������ܣ�strncpy��strncat��strncmp
	//	4.�ַ�������strstr��strtok		5.������Ϣ����strerror		6.�ַ�����
	//	7.�ڴ��������memcpy��memmove��memset��memcmp

	//1.strlen --	1.�����'\0'֮ǰ��		2.���ݵ��ַ�����Ҫ��'\0'		3.����ֵ��size_t�����޷�����
	//����3.
	//if (strlen("abc") - strlen("abcdef") > 0)
	//	printf(">");// 3 - 6 = -3	����-3�������޷�����������ʱ-3�Ĳ��������ԭ�룬��һ���ܴ�����֣�4294967293������ �޷����� +- �޷����� = �޷�����	
	//else
	//	printf("<=");
	//printf("%u ", strlen("abc") - strlen("abcdef"));//4294967293


	//2.1strcpy	-- 1.�������ַ�����Ҫ����\0���Ὣ'\0'һͬ������ȥ		2.������ȥ�Ŀռ�Ҫ�㹻��	3.Ŀ��ռ����ɱ�
	//char arr[20] = "##########";
	////arr = "hello";//err		arr��һ����ַ������Ҳ����һ����ţ���˲��ܷ���arr�У���Ӧ�ô�ŵ�һ�������ռ��С�
	//char* p = "hello";//�ַ������ݵ����׵�ַ
	//char arr2[] = { 'a','b','c' };
	//strcpy(arr, arr2);//err��������û��'\0'���Ҳ���������־
	//strcpy(arr, "hello");//����'\0'���Ὣ'\0'һͬ������ȥ��Ȼ����ֹ����

	//char arr[5] = "####";
	//char* p = "hello world";
	//strcpy(arr, p);//�´����ȥ�����ǳ�������
	//printf("%s", arr);

	//char* str = "xxxxxxx";
	//char* p = "hello world";
	//strcpy(str, p);//Ŀ��ռ��ǳ����ַ��������ɱ䣬�������
	//printf("%s", str);
	//printf("%c","123456"[3]);//4	˵��"" ��ʾ����ʵ������Ԫ�صĵ�ַ


	//2.2strcat�ַ���׷��	1.Ŀ��ռ�Ҫ���㹻�ռ�		2.�Ḳ��Ŀ��ռ��\0�����Լ���\0�ᱻ����ȥ�������Ҫ\0		3.Ŀ��ռ���޸�
	//char arr1[20] = "hello \0##########";
	//char arr2[] = "world";
	//strcat(arr1, arr2);//�ַ���׷�ӣ����ӣ�
	//printf("%s", arr1);
	//ģ��ʵ��
	//char arr1[20] = "hello ";
	//char arr2[] = "world";
	//printf("%s", myStrcat(arr1, arr2));//�ַ���׷�ӣ����ӣ�
	//Ϊʲô�����Լ�׷���Լ����Լ���\0�������ˣ��Ҳ���\0����˱���


	//2.3strcmp�Ƚ��ַ������ַ���������> < =�Ƚϣ��������߱ȽϱȽϵ�������Ԫ�صĵ�ַ������ַ���������ģ���˱Ƚ�û������
	//strcmp�Ƚ϶�Ӧλ�õ�ACSLL��ֵ��ֱ�������˲�һ�����ַ�����ô���ASCLLΪ������\0ֹͣ�Ƚ�
	//char* p = "obc";
	//char* q = "abcdef";
	//printf("%d\n", strcmp(p, q));
	//printf("%d\n", strcmp("abc", "abcdef"));
	//ģ��ʵ��
	//char* p = "obc";
	//char* q = "abcdef";
	//int ret = myStrcmp(p, q);//û�иı�p��q��ָ��
	//if (0 < ret)
	//	printf("p > q\n");
	//else if(0 > ret)
	//	printf("p < q\n");
	//else
	//	printf("p == q\n");


	//3.1strncpy
	//char arr1[20] = "abcdefghi";
	//char arr2[] = "qwer";
	//strncpy(arr1, arr2, 6);//��������\0��
	//printf("%s", arr1);//qwer

	//3.2strncat
	//char arr1[20] = "hello ";
	//char arr2[] = "world";
	//strncat(arr1, arr2, 2);//����\0�ͽ���׷�ӣ�����ʱҲ�����\0
	//printf("%s", arr1);//hello wo

	//3.3strncmp
	//char arr1[20] = "abcde";
	//char arr2[] = "abcdefgh";
	//printf("%d", strncmp(arr1, arr2, 3));//�Ƚϸ����ĸ���


	//4.1strstr�����Ӵ������з��ص�һ�γ��ֵĵ�ַ���Ҳ������ؿ�ָ��
	//char arr1[] = "abbbcdefghijk";
	//char arr2[] = "bbc";
	////char* ret = strstr(arr1, arr2);//��arr1����arr2
	//char* ret = myStrstr(arr1, arr2);//��arr1����arr2
	//if (ret == NULL)
	//	printf("û�ҵ�\n");
	//else
	//	printf("�ҵ��ˣ�%s\n", ret);

	//4.2strtok�и��ַ�������ı䱻�и��ַ��������ݣ�����Ǹ�Ϊ\0�������������ǵ�λ��
	//strtok��һ����������NULL���Ӵ����λ�ÿ�ʼ�ң��ҵ���Ǻ󽫱�Ǹ�Ϊ\0������¼���λ��
	//strtok��һ��������NULL������һ����¼��λ�ÿ�ʼ�ң��ҵ���Ǻ󽫱�Ǹ�Ϊ\0������¼���λ��
	//char* strtok(char* str,const char* sep)
	//char arr[] = "fudan@daxue.com";
	//char* p = "@.";
	//char tmp[20] = { 0 };//��ֹ���и��ַ������ı�
	//strcpy(tmp, arr);
	//char* ret = NULL;
	//for (ret = strtok(tmp, p); ret != NULL; ret = strtok(NULL, p))
	//	printf("%s\n", ret);

	//printf("%s\n", strtok(tmp, p));
	//printf("%s\n", strtok(NULL, p));
	//printf("%s\n", strtok(NULL, p));


	//5.������Ϣ����strerror
	//�ڵ��ÿ⺯��ʧ�ܵ�ʱ�򣬶������ô����룬�˺����������뷭��ɴ�����Ϣ���������������Ϣ���׵�ַ
	//c������һ��ȫ�ֱ�������������룺int errno;
	//char* strerror(int errnum)	errnumΪ������
	//printf("%s\n",strerror(0));
	//printf("%s\n",strerror(1));
	//printf("%s\n",strerror(2));
	//printf("%s\n",strerror(3));
	//printf("%s\n",strerror(4));
	//printf("%s\n",strerror(5));
	//FILE* pf = fopen("test.txt", "r");
	//if (pf == NULL)//����NULL��ʾ���ļ�ʧ��
	//{
	//	printf("%s\n", strerror(errno));//ʧ�ܣ������뱣����errno�У����ú��������ӡʧ�ܵ�ԭ��
	//	return 1;
	//}
	//fclose(pf);
	//pf = NULL;
	//	

	return 0;
}