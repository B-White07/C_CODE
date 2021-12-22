#include "utils.h"

union Un {
    char c;//1
    int i;//4
};

union Un2 {
    char a[5];//5
    int i;//4
};

void test()
{
    int* p  = (int*)malloc(100);
    if(NULL == p)
        return;
    //使用p
}
int main() {
/*
 *  一、联合体（共用体）
 *  联合也是一种特殊的自定义类型，这种类型定义的变量也包含一系列的成员，特征是这些成员共用同一块空间，所以联合也叫共用体
 *  联合体的大小，至少是最大成员的大小
 */
//    union Un u = {10};
//    u.i = 1000;
//    u.c = 100;//改变c的同时，i也改变了，因此联合体在同一时间只能使用一个成员
////    printf("%d\n",sizeof(u));//4
//    printf("%p\n", &u);
//    printf("%p\n", &(u.c));
//    printf("%p\n", &(u.i));

//  判断当前机器大小端
//    if( 1 == check_sys2() )
//        printf("小端");
//    else
//        printf("大端");

//    联合体大小的计算：联合体也存在对齐
//      联合体的大小至少是最大成员的大小
//      当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍

//    union Un2 u2;
//    printf("%d\n",sizeof(u2));//8



    /*
     * 二、动态内存管理
     * 1。为什么存在动态内存分配        2。动态内存函数的介绍：malloc、free、calloc、realloc
     * 3。常见的动态内存错误        4。几个经典的笔试题          5。柔性数组
     */
    //  1.写死的空间容易浪费，或者不够
//      2.1 void* malloc( size_t size )：向内存（堆区）申请一块连续可用的空间，并返回指向这块空间的指针
//          1。若开辟成功，则返回一个指向开辟好空间的指针
//          2。若开辟失败，则返回一个NULL指针，因此malloc的返回值一定要做检查
//          3。返回值的类型是void*，所以malloc函数并不知道开辟空间的类型，具体在使用的时候使用者自己来决定
//          4。如果参数size为0，malloc的行为是标准为定义的，取决于编译器
//    开辟10个整形空间 - 10*sizeof(int)
//    int arr[10];//栈区
//    动态内存开辟
//    int *p = (int *) malloc(10 * sizeof(int));
//    //使用这些空间的时候
//    if (NULL == p) {
//        perror("main");//若有错误，打印main:xxxxxxx
////        printf("malloc error\n");
//        return 0;
//    }
//    //使用
//    for (int i = 0; i < 10; i++) {
//        *(p + i) = i;
//    }
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", p[i]);//*(p+i)
//    }
//
//    //回收空间void free( void* ptr )，和malloc成对出现
//    //  如果参数ptr指向的空间不是动态开辟的，那free函数的行为是未定义的
//    //  如果参数ptr是NULL指针，则函数什么都不做。
//    free(p);//只是将空间还给操作系统，p中仍然存放着那快空间的地址，为了防止非法访问，最好将p置空
//    p = NULL;//手动将p置空

//  2.2 void* calloc( size_t num, size_t size )
//    int *p = (int *) malloc(40);
//    int *p = (int *) calloc(10, sizeof(int));//calloc会对分配的内存初始化，malloc不会；参数不一样，其他和malloc完全一样
//    if (NULL == p) {
//        perror("main");
//        return 1;
//    }
//    for (int i = 0; i < 10; i++)
//        printf("%d ", p[i]);
//    free(p);
//    p = NULL;

//    2.3   void *realloc( void *ptr, size_t new_size )
//          realloc(NULL，40)第一个参数传递空指针，效果和malloc一样
//    int *p = (int *) calloc(10, sizeof(int));//calloc会对分配的内存初始化，malloc不会；参数不一样，其他和malloc完全一样
//    if (NULL == p) {
//        perror("main");
//        return 1;
//    }
//    for (int i = 0; i < 10; i++)
//        *(p + i) = 5;
//    //需要p指向的空间更大，需要20个int的空间，使用realloc调整空间
//    //  若原空间后边的空间足够新的空间，直接将后边的空间分配给p，返回原地址p；
//    //  若原空间后边的空间不足够开辟新的空间，则会新开辟一块空间，将原空间的数据拷贝到新空间，返回新空间地址，将原空间释放；
//    //  若找不到合适的空间来调整大小，则返回空指针。因此不要用原指针接收返回值
//    int *ptr = (int *) realloc(p, 20 * sizeof(int));
//    if (NULL != ptr)
//        p = ptr;//确定分配成功再赋值给p，方便维护
//
//    free(p);
//    p = NULL;

//  3.  常见的动态内存错误
//      3.1 对空指针的解引用操作，解决方法：对malloc函数的返回值做判空判断
//    int* p = (int*)malloc(10000000000000);
//    for (int i = 0; i < 10; ++i) {
//        *(p+i) = i;
//    }

//      3.2 对动态开辟空间的越界访问
//    int *p = (int *) malloc(10 * sizeof(int));
//    if (NULL == p)
//        return 1;
//    //越界访问
//    for (int i = 0; i < 40; ++i) {
//        *(p + i) = i;
//    }
//    free(p);
//    p = NULL;

//      3.3 对非动态开辟内存使用free释放
//    int arr[10] = {0};//栈区
//    int* p = arr;
//    free(p);//err，p不是动态开辟的空间，不能用free
//    p = NULL;

//      3.4 使用free释放一块动态开辟内存的一部分
//    int *p = (int *) malloc(10 * sizeof(int));
//    if (NULL == p)
//        return 1;
//    for (int i = 0; i < 5; ++i) {
//        *p++ = i;
//    }
//    free(p);//此时p已经不指向动态开辟空间的首地址，此时free有两个风险：1.free了一部分，这是错误的       2.动态申请的空间的起始位置无法找到，可能会内存泄漏
//    p = NULL;

//      3.5 对同一块动态内存多次释放
//    int* p = (int*)malloc(100);
//    free(p);
//    free(p);//err，避免方法：第一次释放完后p=NULL;free(NULL)什么事情都不会发生

//      3.6 动态开辟内存忘记释放（内存泄漏）
    //test();//出了这个函数，想释放都无法释放，因为局部变量p已经被销毁，无法再找到那块儿空间
    //动态开辟的空间只有两种情况才能被销毁：1。主动free        2。程序结束，注意是程序而非函数






    return 0;
}
