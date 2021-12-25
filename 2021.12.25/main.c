#include <stdio.h>
#include <unistd.h>

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

//  pf是一个指向FILE类型数据的指针变量，可以使pf指向某个文件的文件信息区（是一个结构体变量）。
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
//    //读文件
//    //关闭文件
//    fclose(pf);
//    pf = NULL;

//    4函数的顺序读写
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


//      对格式化数据的写文件
//    S s = {"fudandaxue", 20, 3.14};
//    FILE *ps = fopen("test.txt", "w");
//    if (NULL == ps) {
//        perror("fopen");
//        return 1;
//    }
//    fprintf(ps, "%s %d %lf", s.arr, s.num, s.sc);
//    fclose(ps);
//    ps = NULL;

//      对格式化数据的读文件
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

//    S s[10] = {0};
//    FILE *pf = fopen("test.txt", "r");
//    if (NULL == pf) {
//        perror("fopen");
//        return 1;
//    }
//    //以二进制形式读文件，可以以正确的格式读出fwrite写的内容
//    fread(s, sizeof(S), 2, pf);
//    for (int i = 0; i < 2; ++i) {
//        printf("%s %d %f", s[i].arr, s[i].num, s[i].sc);
//    }
//    fclose(pf);
//    pf = NULL;

//  对比一组函数
//  scanf：针对标准输入的格式化输入语句 - stdin，即键盘       fscanf：针对所有输入流的格式化输入语句      sscanf：从一个字符串中读取一个格式化的数据
//  printf：针对标准输出流的格式化输出语句 - stdout，即屏幕      fprintf：针对所有输出流的格式化输出语句     sprint：把一个格式化的数据，转换成字符串
//    S s = {"hello", 20, 3.14f};
//    S tmp = {0};
//    char buffer[100] = {0};
//    //讲一个格式化数据转换为字符串
//    sprintf(buffer, "%s %d %f", s.arr, s.num, s.sc);
//    printf("%s\n", buffer);
//    //从buffer中还原出一个结构体数据
//    sscanf(buffer, "%s %d %f", tmp.arr, &tmp.num, &tmp.sc);
//    printf("%s %d %f\n", tmp.arr, tmp.num, tmp.sc);

//    5.1文件的随机读写fseek：根据文件指针的位置和偏移量来定位文件指针
//    FILE *pf = fopen("test.txt", "r");
//    if (pf == NULL) {
//        perror("fopen");
//        return 1;
//    }
//    int ret = fgetc(pf);
//    printf("%c ", ret);//a
//    fseek(pf, -1, SEEK_CUR);//指针从当前位置向前偏移一个字符
//    ret = fgetc(pf);
//    printf("%c ", ret);//a
//    ret = fgetc(pf);
//    printf("%c ", ret);//b
//    //ftell返回文件指针相对于起始位置的偏移量
//    int move = ftell(pf);
//    printf("%d ", move);
////    rewind让文件指针回到起始位置
//    rewind(pf);
//    ret = fgetc(pf);
//    printf("%c ",ret);
//    fclose(pf);
//    pf = NULL;


//    6.文本文件和二进制文件：根据数据的组织形式，数据文件被称为文本文件或者二进制文件。
//      数据在内存中以二进制的形式存储，如果不加以转换的输出到外存，就是二进制文件。
//      如果要求在外存上以ASCLL码的形式存储，则需要在存储前转换，以ASCLL码字符的形式存储的文件就是文本文件
//    一个数据在文件中的存储方式：字符一律以ASCLL形式存储，数值型数据既可以用ASCLL形式存储，也可以使用二进制形式存储
//    如整数10000，如果以ASCLL的形式输出到磁盘，则磁盘中占用5个字节（每个字符一个字节），而二进制形式输出，则在磁盘上只占4个字节
//    int a = 10000;
//    FILE *pf = fopen("test.txt", "wb");
//    if (pf == NULL) {
//        perror("fopen");
//        return 1;
//    }
//    //以二进制形式写入
//    fwrite(&a, sizeof(int), 1, pf);
//    fclose(pf);
//    pf = NULL;
//    int res = 0;
//    FILE *pf2 = fopen("test.txt", "r");
//    if (pf2 == NULL) {
//        perror("fopen");
//        return 1;
//    }
//    fread(&res, sizeof(int), 1, pf2);
//    printf("%d", res);
//    fclose(pf2);
//    pf2 = NULL;

//    7文件读取结束的判定
//        7.1被错误使用的feof：在文件读取的过程中，不能用feof函数的返回值判断文件是否结束，而是用于当文件读取结束时，判断是读取失败结束，还是遇到文件尾结束
//    写代码将test.txt文件拷贝一份，生成test2.txt
//    FILE *pfread = fopen("test.txt", "r");
//    if (pfread == NULL) {
//        perror("pfread fopen");
//        return 1;
//    }
//    FILE *pfwrite = fopen("test2.txt", "w");
//    if (pfwrite == NULL) {
//        perror("pfwrite fopen");
//        fclose(pfread);
//        pfread = NULL;
//        return 1;
//    }
//    //拷贝
//    int ret = 0;
//    while ((ret = fgetc(pfread)) != EOF) {
//        fputc(ret, pfwrite);
//    }
//    //判断是否为正常结束
//    if(feof(pfread))
//    {
//        printf("遇到文件末尾，正常结束");
//    }
//    else if(ferror(pfread))
//    {
//        printf("读取文件失败，导致读取文件结束");
//    }
//    fclose(pfread);
//    pfread = NULL;
//    fclose(pfwrite);
//    pfwrite = NULL;

//    8.文件缓冲区
//      ANSIC 标准采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动地在内存中为程序中每一个正在使用的文件开辟一块“文件缓冲区”。
//      从内存向磁盘输出数据会先送到内存中的缓冲区，装满缓冲区后才一起送到磁盘上。
//      如果从磁盘向计算机读入数据，则从磁盘文件中读取数据输入到内存缓冲区(充满缓冲区)，然后再从缓冲区逐个地将数据送到程序数据区(程序变量等)。
//      缓冲区的大小根据C编译系统决定的。

//    FILE*pf = fopen("testBuffer.txt", "w");
//    fputs("abcdef", pf);//先将代码放在输出缓冲区
//    printf("睡眠10秒-已经写数据了，打开testBuffer.txt文件，发现文件没有内容\n");
//    sleep(10);//linux下的单位是秒
//    printf("刷新缓冲区\n");
//    fflush(pf);//刷新缓冲区时，才将输出缓冲区的数据写到文件(磁盘) //注:fflush 在高版本的VS上不能使用了
//    printf("再睡眠10秒-此时，再次打开testBuffer.txt文件，文件有内容了\n");
//    sleep(10);
//    fclose(pf);
////注:fclose在关闭文件的时候，也会刷新缓冲区
//    pf = NULL;




    return 0;
}
