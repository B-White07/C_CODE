#include "utils.h"

//void test() {
//    int *p = (int *) malloc(100);
//    if (NULL == p)
//        return;
//    //使用p
//}

//void GetMemory(char* p)
//{//p是str的一份临时拷贝，p改变不会影响str
//    p = (char*)malloc(100);//出函数后行参p销毁，且没有释放空间，导致内存泄漏
//}
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(str);//值传递，并没有改变str，str仍是空指针
//    strcpy(str,"Hello World");//往空指针里拷贝，失败
//    printf(str);
//}

//改1
//char *GetMemory(char *p) {
//    p = (char *) malloc(100);
//    return p;
//}
//void Test(void) {
//    char *str = NULL;
//    str = GetMemory(str);
//    strcpy(str, "Hello World");
//    printf(str);
//    free(str);
//    str = NULL;
//}

//改2
//void GetMemory(char* *p) {
//    *p = (char *) malloc(100);
//}
//void Test(void) {
//    char *str = NULL;
//    GetMemory(&str);
//    strcpy(str, "Hello World");
//    printf(str);
//    free(str);
//    str = NULL;
//}


//char *GetMemory(void) {
//    char p[] = "hello world";//数组是在栈上创建的，出了此函数，这块儿空间就还给了操作系统，即使返回地址，也是没有意义的，若访问就是非法访问
//    return p;//虽然可以return字符串的首地址，但是出了这个函数后，局部变量p就被销毁了，原空间有可能已经被其他的程序使用，而不是hello world
//    //返回栈空间地址的问题
//}
//void Test(void) {
//    char *str = NULL;
//    str = GetMemory();
//    printf(str);//非法访问空间
//}

//int *f2(void) {
//    int *ptr;//野指针问题
//    *ptr = 10;
//    return ptr;
//}


//void GetMemory(char** p,int num)
//{
//    *p = (char*)malloc(num);
//}
//void Test(void)
//{
//    char* str = NULL;
//    GetMemory(&str, 100);
//    strcpy(str,"Hello World");
//    //没有free，导致内存泄漏
//    printf(str);
//}


//void Test(void)
//{
//    char* str = (char*)malloc(100);
//    strcpy(str,"hello");
//    free(str);
//    //free不会将str置空，但是已经将空间还给操作系统了，再访问就是非法的
//    //考察的是free后一定要置空
//    if(str != NULL)
//    {
//        strcpy(str,"world");
//        printf(str);
//    }
//}

struct S {
    int n;
//    int arr[];//大小未知，是柔性数组，写法1
    int arr[0];//大小未知，是柔性数组，写法2
};

struct S2 {
    int n;
    int *arr;
};


int main() {
    setbuf(stdout,NULL);
    /*
     * 二、动态内存管理
     * 1。为什么存在动态内存分配        2。动态内存函数的介绍：malloc、free、calloc、realloc
     * 3。常见的动态内存错误        4。几个经典的笔试题          5。C/C++程序的内存开辟        6。柔性数组
     */
//      1.写死的空间容易浪费，或者不够
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
//    test();//出了这个函数，想释放都无法释放，因为局部变量p已经被销毁，无法再找到那块儿空间
//    动态开辟的空间只有两种情况才能被销毁：1。主动free        2。程序结束，注意是程序而非函数

//  4.  几个经典的笔试题
//      4.1
//    Test();

//      4.2
//    Test();

//      4.3
//    Test();

//      4.4
//    Test();

//    5。C/C++程序的内存开辟
//    1. 栈区(stack):在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结 束时这些存储单元自动被释放。
//          栈内存分配运算内置于处理器的指令集中，效率很高，但是 分配的内存容量有限。 栈区主要存放运行函数而分配的局部变量、函数参数、返回数据、返 回地址等。
//    2. 堆区(heap):一般由程序员分配释放， 若程序员不释放，程序结束时可能由OS回收 。分配方式类似于链表。
//    3. 数据段(静态区)(static)存放全局变量、静态数据。程序结束后由系统释放。
//    4. 代码段:存放函数体(类成员函数和全局函数)的二进制代码。

//  6。柔性数组
//      C99中，允许结构体中的最后一个元素是未知大小的数组，这就叫做柔性数组成员
//          柔性数组成员前必须至少有一个其他成员
//          sizeof计算带有柔性数组的结构体的大小不包括柔性数组的大小
//          包含柔性数组成员的结构用malloc函数进行动态内存分配，并且分配的内存大小应该大于结构体的大小，以适应柔性数组的预期大小

//    struct S s = {0};
//    printf("%d ", sizeof(s));

//      期望arr的大小是10个整形空间，需要自己在后边补充
//    struct S *ps = (struct S *) malloc(sizeof(struct S) + 10 * sizeof(int));
//    if (ps == NULL)
//        return 1;
//    ps->n = 10;
//    for (int i = 0; i < ps->n; ++i) {
//        ps->arr[i] = i;
//    }
////  扩容
//    struct S *tmp = (struct S *) realloc(ps, sizeof(struct S) + 20 * sizeof(int));
//    if (tmp != NULL)
//        ps = tmp;
//    //使用
//    //释放
//    free(ps);
//    ps = NULL;
//
//    //不使用柔性数组也能实现相同的效果，对比一下：
//    struct S2 *ps2 = (struct S2 *) malloc(sizeof(struct S2));
//    if (ps2 == NULL)
//        return 1;
//    ps2->n = 10;
//    ps2->arr = (int *) malloc(10 * sizeof(int));
//    for (int i = 0; i < 10; ++i) {
//        ps2->arr[i] = i;
//    }
//    //扩容
//    int *tmp2 = (int *) realloc(ps2->arr, 20 * sizeof(int));
//    if (tmp != NULL)
//        ps2->arr = tmp2;
//    //use
//    //释放
//    free(ps2->arr);
//    ps2->arr = NULL;
//    free(ps2);
//    ps2 = NULL;


//    发现使用柔性数组的好处：
//      1. 内存释放方便：可以看到，不使用柔性数组的时候，结构体的数组成员变量也是需要动态分配的，这样一来就造成了使用结构体需要进行两次内存分配
//          也就意味着结束时需要调用两次free，这就容易发生错误
//      2. 有利于提高访问速度：实际上，单次动态内存分配分配的是连续的空间，但是多次动态内存分配分配的并不是连续的空间，不知道在哪里分配的
//          因此多次分配就容易造成内存碎片的产生，这样内存利用率也降低了
//      内存池：为了提高内存利用率，操作系统为当前程序分配的一块儿内存，此程序就使用这块内存
//      局部性原理：空间局部性：当使用一块儿内存的时候，接下来80%的可能会使用此块内存周边的内存，因此采用柔性数组时，整个结构体内的成员的地址都是较为连续的，
//                          访问效率也就提高了，而不使用柔性数组，多次动态开辟的空间在内存上不是连续的，影响效率
//                时间局部性


    /*
     * 三、文件
     * 1为什么使用文件     2什么是文件      3文件的打开和关闭       4文件的顺序读写        5文件的随机读写
     * 6文本文件和二进制文件               7文件读取结束的判定      8文件缓冲区
     */
//    1为什么使用文件：做到数据持久化
//    2什么是文件：从文件的功能角度分类程序文件和数据文件
//              程序文件：源文件(.c)    目标文件(.obj)      可执行程序(windows的.exe)
//              数据文件：文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件



    return 0;
}
