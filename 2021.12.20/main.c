#include "utils.h"
#include <stddef.h>

struct Book {
    char name[20];
    int price;
} b4, b5, b6 = {"C", 30};      //b4,b5,b6  是全局的对象,其中b6已经初始化了

//匿名结构体类型，不完全声明，只能使用一次
struct {
    char c;
    int i;
    char ch;
    double;
} s;
struct {
    char c;
    int i;
    char ch;
    double;
} *ps;

//  2.结构体自引用:能够找他和他同类型的下一个结构体-->链表
struct A {
    char a;
    int i;
};
struct B {
    struct A a;//结构体内部可以有其他结构体
//    struct B b;//但是不可以有自己
    int i;
};
//struct Node
//{
//    int data;
//    struct Node* next;//结构体自引用:结构体中包含同类型结构体的指针，注意不是同类型的结构体
//};

//typedef struct
//{
//    int data;
//    Node* next;
//}Node;//err,无法解决先后问题

typedef struct Node {
    int data;
    struct Node *next;//不能直接使用Node*
} Node;//这样定义可以，因为已经有了struct Node类型，可以重命名

//#pragma pack(2)//更改默认对齐数为2
struct S {
    char c1;
    int i;
    char c2;
};
//#pragma pack()//改回默认对齐数

struct S2 {
    char c;
    int i;
    double d;
};
struct S3 {
    char c1;
    char c2;
    int i;
};
struct S4 {
    double d;
    char c;
    int i;
};
struct S5 {
    char c1;
    struct S4 s4;
    double d;
};

struct C {
    //先开辟4个字节，即32个bit
    int _a: 2;//    _a需要2个bit位  32 - 2 = 30
    int _b: 5;//    _b需要5个bit位  30 - 5 = 25
    int _c: 10;//   _c需要10个bit位 25 - 10 = 15
    //不够了，在开辟4个字节 ?? 32bit，前边剩余的空间，C语言没有规定要不要使用
    int _d: 30;//   _d需要30个bit位
    //注意，不能超过其类型的最大限度，如int后边的数字不能超过32
};
struct D {
    //先开辟4个字节，即32个bit
    char a: 3;
    char b: 4;
    char c: 5;
    char d: 4;
};

//
//#define RED 3
//#define BLUE 5
//#define GREEN 7
//能用枚举就用枚举：1.增加了代码的可读性和维护性      2.和#define定义的标识符比较，枚举有类型检查，更严谨
//               3.防止了命名污染（枚举是封装在内部的，而#define是全局的）              4.便与调试         5.使用方便，一次可以定义多个常量
//test.c ->  编译（预编译 -> 编译 -> 汇编） ->  链接  ->  test.exe
enum Color {
    RED = 3,//枚举类型的可能取值，是常量
    BLUE,
    GREEN
};


int main() {
/*
 * 自定义类型
 * 一、结构体
 *  1结构体类型的声明       2结构体的自引用        3结构体变量的定义和初始化
 *  4结构体内存对齐        5结构体传参      6结构体实现位段（位段的填充&可移植性）
 *
 * 二、枚举
 * 1枚举类型的定义     2枚举的优点      3枚举的使用
 *
 * 三、联合
 * 1联合类型的定义     2联合的特点      3联合大小的计算
 */

//一、结构体
//  1.结构体类型的声明
//  b1 - b3是局部对象
//    struct Book b1;
//    struct Book b2;
//    struct Book b3;
//    ps = &s;//err，这两个结构体变量会被理解为不同的结构体类型

//  3.结构体变量的定义和初始化  ---见1，两种创建方法
//    struct Book b1 = {"C pointer",20};
//    struct B b = {{'a', 10}, 20};
//    printf("%c %d %d", b.a.a, b.a.i, b.i);

//  4.结构体内存对齐
    //对齐规则：
    //  1.结构体的第一个成员永远存放在结构体变量在内存中存储位置的0偏移量处
    //  2.从第二个成员往后的所有成员，都存放在一个对齐数的整数倍的地址处。  对齐数：成员的大小和默认对齐数的较小值     vs默认对齐数8，linux以自身为对齐数
    //  3.结构体的总大小是结构体所有成员的最大对齐数的整数倍。
    //  4.嵌套的结构体对齐到自己成员变量的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//    struct S s = {0};
//    struct S2 s2={0};
//    struct S3 s3={0};
//    struct S4 s4={0};
//    struct S5 s5={0};
//    printf("%d\n",sizeof(s));//     1 + 3 + 4 + 1 + (3*4 - 9) = 12
//    printf("%d\n",sizeof(s2));//    1 + 3 + 4 + 8 = 16
//    printf("%d\n",sizeof(s3));//    1 + 1 + 2 + 4 = 8
//    printf("%d\n",sizeof(s4));//    8 + 1 + 3 + 4 = 16
//    printf("%d\n",sizeof(s5));//    1 + 7 + 16 + 8 = 32
//  为什么存在内存对齐：
//  1.平台原因（可移植性）：某些硬件平台只能在某些地址处读取某些特定的数据类型，否则抛出异常
//  2.性能原因：数据结构（尤其是栈）应该尽可能的在自然边界上对齐。原因在于，为了访问未对齐的内存，处理器需要两次内存访问；而对齐的内存仅需要一次内存访问
//  结构体的内存对齐实际上是用空间换取时间，但应尽量设计的节省空间：1.让占用空间小的成员尽量集中在一起  2.修改默认对齐数
//    printf("%d\n",sizeof(s));//修改默认对齐数：2

//  计算结构体中某变量相对于首地址的偏移量，即offsetof宏的实现
//    printf("%d\n",offsetof(struct S ,c1));
//    printf("%d\n",offsetof(struct S ,i));
//    printf("%d\n",offsetof(struct S ,c2));


//  5.结构体传参
//    struct S6 s6 = {{1, 2, 3, 4}, 1000};
//    //函数传参时，参数需要压栈，会有时间和空间上的开销；如果传递的结构体对象过大，参数压栈的系统开销比较大，会导致性能的下降。
//    print1(s6);  //浪费空间
//    print2(&s6);//效率高

//  6.结构体实现位段（位段的填充&可移植性）
//  位段的声明和结构是类似的，有两个不同：1.位段的成员必须是int、unsigned int、signed int、char       2.位段的成员后边有一个冒号和一个数字
//  位段的空间上是按照需要以4个字节（int）或1个字节（char）的方式来开辟的
//  位段涉及很多不确定因素，位段是不跨平台的，注重可移植性的程序应该避免使用位段
//      1。int位段被当成有符号数还是无符号数是不确定的；
//      2。位段中最大位的数目不能确定（32位机器int4个字节，可以设置30个bit，而16位机器int2个字节，无法设置30个bit）
//      3。位段中的成员的内存是从左向右分配还是从右向左分配是没有规定的
//      4。当一个结构包含两个位段，第二个位段成员比较大，第一个位段剩余的位无法容纳它，剩余的位舍弃还是利用也是不确定的
//  和结构体相比，位段可以达到同样的效果，但是可以很好的节省空间，但是有跨平台的问题存在
//  位段应用场景：网络包的传输等
//    printf("%d\n", sizeof(struct C));//8
//  不要和大小段混淆，大小段讨论的是字节序的存储顺序，位段是一个字节内部的存储顺序
//    struct D d = {0};
//    d.a = 10;
//    d.b = 12;
//    d.c = 3;
//    d.d = 4;
    //3 4 5 3
    //01100010 -> 01100010 00000011 -> 01100010 00000011 00000100
    //CLion：一个字节的空间由地位向高位使用，即从右向左；一个字节剩余的空间不够下一个成员使用时，舍弃这块儿空间


    /*
     * 二、枚举
     */
//    enum Color color = 2;//CPP语法更严格，不通过
//    printf("%d\n", RED);//默认为0，递增一，可以赋初值，但是不可以更改
//    printf("%d\n", BLUE);
//    printf("%d\n", GREEN);
//    RED = 6；// err，不可更改





    return 0;
}

