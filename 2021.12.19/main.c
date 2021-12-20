#include "utils.h"

int main() {
    //strerror()    将错误码转换为错误信息
//    FILE *pf = fopen("test.txt", "r");//文件打开失败返回NULL指针
/*    if (NULL == pf) {
//        printf("%s\n", strerror(errno));//将错误码转换为字符串，返回字符串首地址
        //perror()  用于打印错误信息
        perror("fopen");//不需要传递errno，实际上它不仅将错误码转换了，而且还打印了注意和strerror的区别
        return 1;
    }
    fclose(pf);    //关闭文件
    pf = NULL;*/

    /*
     * 1。字符分类函数
     * 1.iscntrl()任何控制字符    2.isspace()空白字符     3.isdigit()十进制数字0-9      4.isxdigit()十六进制数字
     * 5.islower()小写字母       6.isupper()大写字母     7.isalpha()英文字母           8.isalnum()字母或数组
     * 9.ispunct()标点符号，任何不属于数字或字母的图形字符（可打印）                      10.isgraph()任何图形字符
     * 11.isprint()任何可打印字符，包括图形字符和空白字符
     */
//    char ch = 'i';
//    printf("%d\n",isdigit(ch));//非数字字符返回0；否则返回非0
//    printf("%d\n",isalpha(ch));//非英文字母字符返回0；否则返回非0

    /*
     * 2。字符转换函数
     * 1.tolower()转换为小写字母，返回ASCLL码值      2.toupper()转换为大写字母返回ASCLL码值
     */
/*    char arr[10] = {0};
    scanf("%s", arr);
    int i = 0;
    while ('\0' != arr[i])
    {
        if (isupper(arr[i]));
        {
            arr[i] = tolower(arr[i]);
        }
        printf("%c ", arr[i]);
        i++;
    }*/

    /*
     * 3。内存函数
     * 1.memcpy()       2.memmove()     3.memcmp()      4.memset()
     */
    //  1.memcpy() 不可重叠
//    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    //01 00 00 00 02 00 00 00
//    int arr2[10] = {0};
    //strcpy()
    //char* strcpy(char* dest, char* src)   有缺陷，只能拷贝字符无法拷贝上述整型数组
    //void* memcpy( void* dest, const void* src, size_t count )    count为需要拷贝的字节数
//    memcpy(arr2,arr1,20);
    //模拟实现memcpy()
//    myMemcpy(arr2,arr1,20);

    //将12345拷贝至34567
//    myMemcpy(arr1 + 2, arr1, 20);//1 2 1 2 1 2 1 8 9 10 与预期的1 2 1 2 3 4 5 8 9 10不一样
//    memcpy(arr1 + 1, arr1, 20);//只要实现了不重叠拷贝就可以，不同编译器实现的方式不一样，因此具体应用场景得和memmove区别开，memcpy只用于不重叠的拷贝

//    //    2.memmove() 可重叠
//    memmove(arr1 + 2, arr1, 20);
//    /模拟memmove()
//    myMemmove(arr1 + 2, arr1 + 4 , 20);

    //  3.memcmp()
//    float arr1[] = {1.0,2.0,3.0,4.0};
//    float arr2[] = {1.0,3.0,3.0};
//    printf("%d\n",memcmp(arr1,arr2,8));//相等返回0，小于返回负数，大于返回正数

    //  4.memset()  以字节为单位设置内存
//    int arr[10] = {0};
//    memset(arr,1,20);//将arr的前20个字节设置为1




    return 0;
}

