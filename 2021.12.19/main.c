#include "utils.h"

int main() {
    //strerror()    ��������ת��Ϊ������Ϣ
//    FILE *pf = fopen("test.txt", "r");//�ļ���ʧ�ܷ���NULLָ��
/*    if (NULL == pf) {
//        printf("%s\n", strerror(errno));//��������ת��Ϊ�ַ����������ַ����׵�ַ
        //perror()  ���ڴ�ӡ������Ϣ
        perror("fopen");//����Ҫ����errno��ʵ������������������ת���ˣ����һ���ӡ��ע���strerror������
        return 1;
    }
    fclose(pf);    //�ر��ļ�
    pf = NULL;*/

    /*
     * 1���ַ����ຯ��
     * 1.iscntrl()�κο����ַ�    2.isspace()�հ��ַ�     3.isdigit()ʮ��������0-9      4.isxdigit()ʮ����������
     * 5.islower()Сд��ĸ       6.isupper()��д��ĸ     7.isalpha()Ӣ����ĸ           8.isalnum()��ĸ������
     * 9.ispunct()�����ţ��κβ��������ֻ���ĸ��ͼ���ַ����ɴ�ӡ��                      10.isgraph()�κ�ͼ���ַ�
     * 11.isprint()�κοɴ�ӡ�ַ�������ͼ���ַ��Ϳհ��ַ�
     */
//    char ch = 'i';
//    printf("%d\n",isdigit(ch));//�������ַ�����0�����򷵻ط�0
//    printf("%d\n",isalpha(ch));//��Ӣ����ĸ�ַ�����0�����򷵻ط�0

    /*
     * 2���ַ�ת������
     * 1.tolower()ת��ΪСд��ĸ������ASCLL��ֵ      2.toupper()ת��Ϊ��д��ĸ����ASCLL��ֵ
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
     * 3���ڴ溯��
     * 1.memcpy()       2.memmove()     3.memcmp()      4.memset()
     */
    //  1.memcpy() �����ص�
//    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    //01 00 00 00 02 00 00 00
//    int arr2[10] = {0};
    //strcpy()
    //char* strcpy(char* dest, char* src)   ��ȱ�ݣ�ֻ�ܿ����ַ��޷�����������������
    //void* memcpy( void* dest, const void* src, size_t count )    countΪ��Ҫ�������ֽ���
//    memcpy(arr2,arr1,20);
    //ģ��ʵ��memcpy()
//    myMemcpy(arr2,arr1,20);

    //��12345������34567
//    myMemcpy(arr1 + 2, arr1, 20);//1 2 1 2 1 2 1 8 9 10 ��Ԥ�ڵ�1 2 1 2 3 4 5 8 9 10��һ��
//    memcpy(arr1 + 1, arr1, 20);//ֻҪʵ���˲��ص������Ϳ��ԣ���ͬ������ʵ�ֵķ�ʽ��һ������˾���Ӧ�ó����ú�memmove���𿪣�memcpyֻ���ڲ��ص��Ŀ���

//    //    2.memmove() ���ص�
//    memmove(arr1 + 2, arr1, 20);
//    /ģ��memmove()
//    myMemmove(arr1 + 2, arr1 + 4 , 20);

    //  3.memcmp()
//    float arr1[] = {1.0,2.0,3.0,4.0};
//    float arr2[] = {1.0,3.0,3.0};
//    printf("%d\n",memcmp(arr1,arr2,8));//��ȷ���0��С�ڷ��ظ��������ڷ�������

    //  4.memset()  ���ֽ�Ϊ��λ�����ڴ�
//    int arr[10] = {0};
//    memset(arr,1,20);//��arr��ǰ20���ֽ�����Ϊ1




    return 0;
}

