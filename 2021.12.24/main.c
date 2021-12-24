#include <stdio.h>

typedef struct S {
    char arr[10];
    int num;
    float sc;
} S;

int main() {
    /*
     * 三、文件
     * 1为什么使用文件     2什么是文件      3文件的打开和关闭       4文件的顺序读写        5文件的随机读写
     * 6文本文件和二进制文件               7文件读取结束的判定      8文件缓冲区
     */
//    1为什么使用文件：做到数据持久化
//    2什么是文件：从文件的功能角度分类程序文件和数据文件
//          2.1程序文件：源文件(.c)    目标文件(.obj)      可执行程序(windows的.exe)
//          2.2数据文件：文件的内容不一定是程序，而是程序运行时读写的数据，比如程序运行需要从中读取数据的文件，或者输出内容的文件
//          2.3文件名：文件名包含三部分：文件路径+文件名主干+文件后缀，是个绝对路径
//    3文件的打开和关闭
//          3.1文件指针：每个被使用的文件都在内存中开辟了一个相应的文件信息区，用来存放文件的相关信息（如文件名字，文件状态及文件当前位置等）。
//                这些信息是保存在一个结构体变量中的，该结构体类型是由系统声明的，取名FILE。一般使用FILE的指针来维护FILE结构的变量。
//                文件发生变化，文件信息区也会相应地发生变化。不同的编译器FILE类型包含的内容不完全相同，但是大同小异。

//  pf是一个指向FILE类型数据的指针变量，可以是pf指向某个文件的文件信息区（是一个结构体变量）。
//  通过该文件信息区中的信息就能够访问该文件，也就是说，通过文件指针变量能够找到与他关联的文件
//    FILE* pf;
////          3.2文件的打开和关闭
////          FILE* fopen( const char* filename, const char* mode )
////    pf = fopen("test.txt","r");//默认路径在cmake-build-debug目录下
//    pf = fopen("/Users/b_white/JetBrains/CLionProjects/2021.12.24/test.txt","r");//可以写绝对路径
//    if(pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //写文件
//    //关闭文件
//    fclose(pf);
//    pf = NULL;

//    FILE* pf = fopen("test.txt","w");
//    if(pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    写文件
//    fputc('f',pf);
//    fputc('u',pf);
//    fclose(pf);


//    流：程序想读写不同的硬件，就要知道对应硬件的读写规则，这样很麻烦，于是在硬件和程序之间用流来连接，程序只需要对流进行操作而不需要知道流是怎么输入输出到硬件的。
//      操作文件实际上就是操作文件流
//      C语言程序只要运行起来，就默认打开了3个流：
//      stdin - 标准输入流 - 键盘          stdout - 标准输出流 - 屏幕         stderr - 标准错误流 - 屏幕     这三个流都是FILE*
//    fputc('f',stdout);
//    fputc('u',stdout);

//    FILE* pf = fopen("test.txt","r");
//    if(pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
////    从文件读文件
//    int ret = fgetc(pf);
//    printf("%c",ret);
//    ret = fgetc(pf);
//    printf("%c",ret);
//    ret = fgetc(pf);
//    printf("%c",ret);
//    ret = fgetc(pf);
//    printf("%c",ret);
//    ret = fgetc(pf);
//    printf("%c",ret);
//    ret = fgetc(pf);//-1
//    printf("%c",ret);
//    ret = fgetc(pf);
//    printf("%c",ret);
//    fclose(pf);
//    pf = NULL;


//    从标准输入流读取信息
//    int ret = fgetc(stdin);
//    printf("%c",ret);
//    ret = fgetc(stdin);
//    printf("%c",ret);
//    ret = fgetc(stdin);
//    printf("%c",ret);

//      FILE* pf = fopen("test.txt","w");
//      if(pf == NULL)
//      {
//          perror("fopen");
//          return 1;
//      }
//      //按照行写文件
//      fputs("sdada\n",pf);//换行需要体现在代码里
//      fputs("jlsdjgha\n",pf);
//      fclose(pf);
//      pf = NULL;

//    FILE* pf = fopen("test.txt","r");
//    if(pf == NULL)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //按照行读文件
//    char arr[10] = "xxxxxxxx";
//    fgets(arr,4,pf);//从pf中读取3个字符（因为要给\0留一个位置）存放到arr中
//    printf("%s\n",arr);
//    fgets(arr,4,pf);
//    printf("%s\n",arr);
//    fclose(pf);
//    pf = NULL;


    //对格式化数据的写文件
//    S s = {"fudandaxue", 20, 3.14};
//    FILE *ps = fopen("test.txt", "w");
//    if (NULL == ps) {
//        perror("fopen");
//        return 1;
//    }
//    fprintf(ps, "%s %d %lf", s.arr, s.num, s.sc);
//    fclose(ps);
//    ps = NULL;

    //对格式化数据的读文件
//    S s = {0};
//    FILE *pf = fopen("test.txt", "r");
//    if (NULL == pf) {
//        perror("fopen");
//        return 1;
//    }
//    fscanf(pf, "%s %d %f", s.arr, &(s.num), &(s.sc));
//    fprintf(stdout, "%s %d %f", s.arr, s.num, s.sc);
//    fclose(pf);
//    pf = NULL;

//      以上读写全部是以文本的形式而非二进制的形式读写，适用于所有输入输出流
//      二进制读写，只适用于文件
//    S s ={"asdf",20,3.14};
//    FILE* pf = fopen("test.txt","w");
//    if(NULL == pf)
//    {
//        perror("fopen");
//        return 1;
//    }
//    //以二进制形式写文件,除字母外，其他全部乱码
//    fwrite(&s,sizeof(S),1,pf);
//    fclose(pf);
//    pf =NULL;

//    S s = {0};
//    FILE *pf = fopen("test.txt", "r");
//    if (NULL == pf) {
//        perror("fopen");
//        return 1;
//    }
//    //以二进制形式读文件，可以以正确的格式读出fwrite写的内容
//    fread(&s, sizeof(S), 1, pf);
//    printf("%s %d %f", s.arr, s.num, s.sc);
//    fclose(pf);
//    pf = NULL;





    return 0;
}
