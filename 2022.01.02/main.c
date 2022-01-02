#include <stdio.h>
#include <stdlib.h>



extern int Add(int, int);

//#define定义符号
#define MAX 1000
#define reg register            //为register这个关键字创建一个简短的名字
#define do_forever for(;;)      //用形象的符号来替换一种实现
#define CASE break;case         //在写case语句的时候自动把break写上
//定义的代码过长，可以分成几行写，除了最后一行，每行的后面都加一个反斜杠（续行符）
#define DEBUG_PRINT printf("file:%s\tline:%d\t  \
                                date%s\ttime%s\n",  \
                                __FILE__,__LINE__,  \
                                __DATE__,__TIME__)

//#define定义宏
#define SQUARE(X) X*X

#define PRINT(X) printf("the value of "#X" is %d\n",X)
#define PRINT2(X, FORMAT) printf("the value of "#X" is "FORMAT"\n",X)

#define CAT(X, Y) X##Y

//#define MAX(X, Y) ((X) > (Y)?(X):(Y))

//int Max(int x, int y) {
//    return x > y ? x : y;
//}

#define MALLOC(num, type) (type*)malloc(num*sizeof(type))

//#define PRINTF

int main() {
    /*
     * 程序的环境和预处理
     * 1程序的翻译环境     2程序的执行环境    3详解：C语言程序的编译+链接     4预定义符号介绍    5预处理指令#define
     * 6宏和函数的对比     7预处理操作符#和##介绍       8命令行定义       9预处理指令#include      10预处理指令#undef
     * 11条件编译
     */
//    一、程序的翻译环境和执行环境
//    在ANSI C的任何一种实现中，存在两个不同的环境
//    第一种是翻译环境，在这个环境中源代码被转换为可执行的机器指令；   第二种是执行环境，它用于实际执行代码
//    test.c --> test.exec的过程依赖的是翻译环境（当前为CLion），运行test.exec所依赖的是运行环境，产生运行结果
//    翻译环境工作流程：工程中的每个.c源文件单独经过编译器处理，变成.o（lunix下的目标文件）文件，
//    然后链接器会将所有的目标文件和链接库(.lib静态库)链接在一起生成可执行程序（exec）


//    二、详解编译+链接
//    因此，翻译环境可分为两部分：编译（依靠编译器）和链接（依靠链接器）
//    其中编译分为三个步骤：
//     1。预编译（预处理），通过gcc test.c -E > test.i将预处理的后的文件重定向到test.i中，便于查看
//          /Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include/stdio.h 查看stdio.h中的内容
//          说明了在预处理阶段完成了:
//              1.头文件的包含，其实就是将头文件拷贝到相应位置
//              2.#define定义的符号和宏的替换，因此后期程序在编译，汇编的时候也是看不到的，后来程序运行也是看不到的，就不便于调试
//              3.注释删除，因此程序中无论有多少注释，都不会给程序带来负担
//          上述这些其实都是文本操作，也就是说，预处理阶段实际上是完成了一些文本操作
//     2。编译，通过gcc test.i(test.c也可以) -S对文件进行编译，生成test.s文件，把C语言代码转化为汇编代码
//          编译阶段完成了：
//              1.语法分析
//              2.词法分析
//              3.语义分析
//              4.符号汇总:将所有的.c中的全局符号汇总，分别汇总
//     3。汇编，通过gcc test.s -c对编译生成的.s文件处理，生成test.o文件（即目标文件），-c意思是汇编之后停止，不要进行下一步
//          test.o是elf格式的，是由一些段组成的，可以使用objdump -d test.o查看这个文件
//          汇编阶段完成了：
//              1.生成符号表：将编译中汇总的符号以及地址放在符号表中
//              2.把汇编代码转换成了机器指令（二进制指令）
//
//    链接：把多个目标文件(.o)和链接库进行链接，生成可执行程序(.out，也是elf格式的)，分为个步骤
//    1。合并段表：将所有的.o文件的相同段链接到一起生成.out文件
//    2。符号表的合并和重定位：汇编生成的符号表中，包含无效信息，需要在此处保留有效的符号和地址，生成最终的符号表。之后通过地址就可以找到对应的函数。

//    int x = 0;
//    int y = 0;
//    int ret = Add(x, y);

//    运行环境：
//        程序执行的过程：
//            1。程序必须载入到内存中。在有操作系统的环境中，一般由操作系统来完成。在独立的环境中，程序的载入必须由手工安排，
//                  也可能是通过可执行代码置入只读内存来完成。
//            2。程序的执行开始。接着便调用main函数
//            3。开始执行程序代码。这个时候程序将使用一个运行时堆栈，又叫函数栈帧（stack），存储函数的局部变量和返回地址。程序同时也可以使用静态（static）内存，
//                  存储于静态内存中的变量在程序的整个执行过程中一直保留他们的值。
//            4。终止程序。正常终止main函数；也有可能是意外终止。


//    三、预处理详解
//        3.1预定义符号
//            __FILE__  __LINE__    __DATE__    __TIME__    __FUNCTION__    __STDC__(遵循ANSI标准的话值为1，否则为定义 )    作用：其实就相当于日志
//    printf("%s\n",__FILE__);//此句代码所在的源文件的路径
//    printf("%d\n",__LINE__);//此句代码所在的行
//    printf("%s\n",__DATE__);//执行此句代码的日期
//    printf("%s\n",__TIME__);//执行此句代码的时间
//    printf("%s\n",__FUNCTION__);//此句代码所在的函数名
//    FILE *pf = fopen("log.txt", "a+");
//    if (pf == NULL) {
//        perror("fopen");
//        return 1;
//    }
//    for (int i = 0; i < 10; ++i) {
//        fprintf(pf, "%s %s %s %s %d %d %d\n", __FILE__, __DATE__, __TIME__, __FUNCTION__, __LINE__, __STDC__, i);
//    }
//    fclose(pf);
//    pf = NULL;

//        3.2#define：定义符号和宏，在预处理阶段就原封不动的替换到相应位置。至于是否加分号，尽量不加，除非必须，因为会原封不动地替换，容易出错
//            定义符号
//    int n = 0;
//    switch (n) {
//        case 1:
//        CASE 2:
//        CASE 3:
//    ; }

//            1定义宏：#define机制包括了一个规定，允许把参数替换到文本中，这种实现通常称为宏（macro）或定义宏（define macro）
//              定义宏时括号很重要
//                宏的申明方式：#define name(parament-list) stuff
//                    其中的parament-list是一个由逗号隔开的符号表，他们可能出现在stuff中，参数列表左括号必须与name紧邻，否则参数列表会被解释为stuff的一部分
//    printf("%d\n", SQUARE(3));
//    printf("%d\n", 3 * 3);//上一行代码在预处理阶段就被替换成了此行代码
//    printf("%d\n", SQUARE(3 + 1));
//    printf("%d\n", 3 + 1 * 3 + 1);//参数不经任何处理，直接传递，传递后再计算，因此应定义为#define SQUARE(X) ((X)*(X))

//           2#define的替换规则：
//            1.在调用宏时，首先对参数进行检查，看看是否包含任何由#define定义的符号。如果是，他们首先被替换
//            2.替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值替换。
//            3.最后，再次对结果文件进行扫描，看看它是否包含任何由#define定义的符号，如果是，就重复上述处理过程。
//            注意：1。宏参数和#define定义中可以出现其他#define定义的常量，但是对于宏，不能出现递归；
//                2。当预处理器搜索#define定义的符号的时候，字符串常量的内容并不被搜索

//          3#和##
//    printf("hello world\n");
//    printf("hello " "world\n");//两个字符串会拼接在一起
//    int a = 10;//the value of a is 10
//    PRINT(a);
////    printf("the value of""a""is %d\n",a);//#的作用是把一个宏参数变成对应的字符串。替换后#X变成了X所对应的字符串即"a"
//    int b = 20;//the value of b is 20
//    PRINT(b);
//    int c = 30;//the value of c is 30
//    PRINT(c);
//    float f = 3.14f;
//    PRINT2(f, "%f");

//    int fudan2023 = 100;
//    printf("%d\n", CAT(fudan, 2023));
////    printf("%d\n", fudan2023);//##作用就是将两个参数连接起来合成了一个符号，变成了fudan2023


//      4带副作用的宏参数
//    int a = 5;
//    int b = 8;
//    int m = MAX(a++, b++);
////    int m = ((a++) > (b++) ? (a++) : (b++));等价于上一行
//    int m2 = Max(a, b);
//    printf("m = %d\n", m);//9
//    printf("a = %d\n", a);//6
//    printf("b = %d\n", b);//10


//      5宏和函数的对比
//        宏优点：
//        1.用于调用函数和从函数返回的代码可能比实际执行这个小型计算工作所需的时间更多。所以宏比函数在程序的规模和速度方面更胜一筹。
//        2.更为重要的是函数的参数必须声明为特定的类型。所以函数只能在类型合适的表达式上使用。反之宏可以使用于整形，长整型，浮点型等可以用>比较的类型，宏是类型无关的。
//        缺点：
//        1.由于宏是直接替换，因此若宏比较长，会导致程序的长度大幅增加
//        2.宏不可以调试。调试是在可执行程序上调试，而宏在预处理阶段就已经被替换了。
//        3.宏与类型无关，不够严谨
//        4.宏可能会带来运算符优先级的问题，导致程序容易出错
//    宏能做到一些函数做不到的事情：宏的参数可以出现类型，而函数不行
//    当运算逻辑比较简单的时候，可以用宏；复杂的话可以使用函数
//    对比表格
//    int *p = MALLOC(10,int);//可以传递类型

//    命名约定：宏名全部大写，函数名不要全部大写


//    3.3#undef取消定义
//    int a = MAX;
//#undef MAX;//移除宏定义，导致下边的宏不可用
//    printf("%d\n",MAX);

//    3.4命令行定义
//    gcc test.c -D M=10        -D M=10 定义M=10      -a  -D等是命令行参数
//    ./a.out   执行

//    3.5条件编译：满足条件才编译
//    常见的条件编译指令：
//        1。#if 常量表达式
//              //..
//          #endif
//#if 1//1为真，执行；若为假（0），则不执行。
//    printf("hello");
//#endif

//        2。多分支的条件编译
//            #if 常量表达式
//                  //..
//            #elif 常量表达式
//                  //..
//            #else
//                  //..
//            #endif
//#if 1==1
//    printf("hello");
//#elif 1==1//由于第一个条件为真，其他所有的都不会执行，即使为真。就是说只能执行一个分支
//    printf("nihao");
//#else
//    printf("hh");
//#endif

//        3。判断是否被定义
//#ifdef PRINTF   //没有#define PRTINF，因此下边一组语句不编译。只要定义了就行，不判断值
//    printf("hello");
//#endif
//
//#if defined(PRINTF)//与上一种等价
//    printf("hello2");
//#endif

    //不定义参与编译，与上一种情况相反
//#ifndef PRINTF   //定义了PRTINF，因此下边一组语句不编译。
//    printf("world");
//#endif
//
//#if !defined(PRINTF)//与上一种等价
//    printf("world2");
//#endif

//        4。嵌套指令
//#if defined(OS_UNIX)
//    #ifdef OPTION1
//        unix_version_option1();
//    #endif
//    #ifdef OPTION2
//        unix_version_option2();
//    #endif
//#elif defined(OS_MSDOS)
//    #ifdef OPTION2
//        msdos_version_option2();
//    #endif
//#endif

//    3.6文件包含
//        1。包含本地头文件 #include "filename"     2。包含库文件#include <>
//        ""和<>包含头文件的本质区别是查找策略：
//          1。""先在源文件所在目录下查找，如果该头文件未找到，编译器就像查找库函数头文件一样在标准位置（即库函数的头文件目录下）查找头文件，如果找不到就提示编译错误。
//            MAC的标准位置：/Library/Developer/CommandLineTools/SDKs/MacOSX12.1.sdk/usr/include/stdio.h:99
//          2。<>直接去库函数头文件所在目录下查找

//        2。嵌套文件包含，会出现头文件被重复包含的情况
//          防止头文件被重复包含的方式：
//                1。头文件中加入#pragma once
//                2。头文件中使用条件编译：#ifndef __TEST_H__
//                                     #define __TEST_H__
//                                              内容..
//                                     #endif


//    四、其他预处理指令
//        《C语言深度剖析》--预处理












    return 0;
}
