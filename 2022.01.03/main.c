#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stddef.h>
//#pragma pack(4)
//struct A {
//    int a;
//    short b;
//    int c;
//    char d;
//};
//struct B {
//    int a;
//    short b;
//    char c;
//    int d;
//};
//#pragma pack()
//
//int main() {
//    struct A sa = {0};
//    struct B sb = {0};
//    printf("结构体A的大小是%dbytes\n",sizeof(sa));// 4+2+2+4+1+3=16
//    printf("结构体B的大小是%dbytes\n",sizeof(sb));// 4+2+1+1+4=12
//    return 0;
//}

//int main()
//{
//    struct tagTest1{
//        short a;
//        char d;
//        long b;
//        long c;
//    };
//    struct tagTest2{
//        long b;
//        short c;
//        char d;
//        long a;
//    };
//    struct tagTest3{
//        short c;
//        long b;
//        char d;
//        long a;
//    };
//
//    struct tagTest1 stT1;// 2+1+5+8+8=24
//    struct tagTest2 stT2;// 8+2+1+5+8=24
//    struct tagTest3 stT3;// 2+6+8+1+7+8=32
//
//    printf("%d %d %d\n",sizeof(stT1),sizeof(stT2),sizeof(stT3));
//    return 0;
//}

//#define MAX_SIZE 2+3
//struct _Record_Struct {
//    unsigned char Env_Alarm_Id: 4;
//    unsigned char Paral: 2;
//    unsigned char state;//不是位段成员，单独开辟一个字节
//    unsigned char avail: 1;
//} *Env_Alarm_Record;
////struct _Record_Struct *pointer = (struct _Record_Struct*) malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//int main()
//{
//    printf("%d",sizeof(struct _Record_Struct) * MAX_SIZE);//9
//    return 0;
//}

//int main()
//{
//    unsigned char puc[4];
//    struct tagPIM
//    {
//        unsigned char ucPim1;
//        unsigned char ucData0 : 1;
//        unsigned char ucData1 : 2;
//        unsigned char ucData2 : 3;
//    }*pstPimData;
//    pstPimData = (struct tagPIM*)puc;
//    memset(puc, 0, 4);
//    pstPimData->ucPim1 = 2;
//    pstPimData->ucData0 = 3;
//    pstPimData->ucData1 = 4;
//    pstPimData->ucData2 = 5;
//    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//    //00000010 00101001
//    return 0;
//}

//union Un
//{
//	short s[7];//14
//	int n;//4
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));//14+2=16
//	return 0;
//}

//int main()
//{
//    union
//    {
//        short k;//2
//        char i[2];//2
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;//00111001
//    s->i[1] = 0x38;//00111000
//    printf("%x\n", a.k);//0011100100111000 -> 3839(小端存放)
//    return 0;
//}

//enum ENUM_A
//{
//    X1,//0
//    Y1,//1
//    Z1 = 255,
//    A1,//256
//    B1,//257
//};
//int main()
//{
//    enum ENUM_A enumA = Y1;
//    enum ENUM_A enumB = B1;
//    printf("%d %d\n", enumA, enumB);//1 257
//    return 0;
//}

//哪个变量不是指针
//#define INT_PTR int*
//typedef int* int_ptr;
//INT_PTR a, b;//b不是指针
//int_ptr c, d;
//模拟实现atoi：将字符串转换为整型

//enum STATE {
//    INVALID,
//    VALID,
//} state = INVALID;
//int myAtoi(const char *string) {
//    int flag = 1;
////    assert(string);
//
////检测空指针
//    if (NULL == string)
//        return 0;
////    检测空字符串
//    if (*string == '\0')
//        return 0;
////    跳过空白字符
//    while (isspace(*string))
//        string++;
////    正负号的判定
//    if (*string == '-')
//    {
//        flag = -1;
//        string++;
//    }
//    else if (*string == '+')
//    {
//        string++;
//    }
////    正常情况
//    long long n = 0;
//    while (isdigit(*string)) {
//        n = 10 * n + flag * (*string - '0');
////        数字过大
//        if (n > INT_MAX || n < INT_MIN)
//            return 0;
//        string++;
//    }
////    是否为正常结束while循环
//    if (*string == '\0') {
//        state = VALID;
//        return (int) n;
//    } else
//        return (int) n;
//}
//int main() {
//    const char *p = "-1234";
////    int num = atoi(p);
//    int num = myAtoi(p);
//    if (state == VALID)
//        printf("正常转换，结果为%d\n", num);
//    else
//        printf("异常转换，结果为%d\n", num);
//
//    return 0;
//}

//一个数组中只有两个数字出现一次，其他所有数字都出现了两次，编写一个函数找出这两个只出现一次的数字
//一个数组中只有一个数字出现一次，其他所有数字都出现了两次，编写一个函数找出这个只出现一次的数字：异或即可
//1234561234

//void Find(int arr[], int size, int *px, int *py) {
//    int tmp = 0;
//    for (int i = 0; i < size; i++) {
//        //将全部元素异或，得到的数字非5非6，也不是0，这个数字为1的为代表5和6不同的位，根据这个分组（011，后两位均是1，根据后两位哪一个分组都可以）
//        tmp ^= arr[i];
//    }
//    //计算哪一位为1，发现就可以，不需要全部找到。用pos记录为1的位置
//    int pos = 0;
//    while ((tmp & 1) != 1) {
//        tmp >> 1;
//        pos++;
//    }
//
//    //分组，按照pos位的数字为1或0分
//    for (int i = 0; i < size; i++) {
//        if ((arr[i] >> pos) & 1 == 1) {
//            *px ^= arr[i];//直接异或，将结果带回
//        } else {
//            *py ^= arr[i];
//        }
//    }
//
//
//}
//int main() {
//    int arr[] = {1, 2, 3, 4, 5, 6, 1, 2, 3, 4};
//    //101
//    //110
//    //011
//    //1^2^3^4^5^6^1^2^3^4 = 5^6 = 3 != 0
//    //
//    //1 3 1 3 5
//    //2 4 2 4 6
//    //1. 分组
//    //2. 分组的要点：5和6必须在不同的组
//    //找出这两个组出现一次的数字
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    int x = 0;
//    int y = 0;
//    //传进去x,y的地址
//    //返回型参数
//    Find(arr, sz, &x, &y);
//    printf("%d %d\n", x, y);
//    return 0;
//}

//头文件包含的内容：头文件的包含，类型的定义，函数的声明。      全局变量的定义和声明都放在头文件中，可能会导致重复定义的错误，不可取

//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换
#define SWAP(N) (((N&0xaaaaaaaa)>>1) + ((N&0x55555555)<<1))
//偶数位按位与0xaaaaaaaa后右移一位，奇数位按位与0x55555555后左移一位，结束后相加，得到的其实就是交换后的结果
//int main() {
//    int a = 10;
//    printf("%d\n", SWAP(a));
//    return 0;
//}

//写一个宏模拟实现offsetof，即计算结构体中某变量相对于首地址的偏移
struct A {
    int a;
    short b;
    int c;
    char d;
};
#define OFFSETOF(struct_name, men_name) (int)&(((struct_name*)0)->men_name)
//将0看作是结构体的起始地址，这样访问其成员再取地址，取到的地址就可以看作是偏移量，将其转换为int即可
//这只是一种假设，实际上并不会操作实际地址为0处的空间

int main() {
//    printf("%d\n",offsetof(struct A,a));
//    printf("%d\n",offsetof(struct A,b));
//    printf("%d\n",offsetof(struct A,c));
//    printf("%d\n",offsetof(struct A,d));
    printf("%d\n", OFFSETOF(struct A, a));
    printf("%d\n", OFFSETOF(struct A, b));
    printf("%d\n", OFFSETOF(struct A, c));
    printf("%d\n", OFFSETOF(struct A, d));
    return 0;
}



