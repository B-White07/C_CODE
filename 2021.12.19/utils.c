//
// Created by B_White on 2021/12/19.
//
#include "utils.h"

void *myMemcpy(void *dest, const void *src, size_t count) {
    assert(dest && src);
    void *tmp = dest;
    while (count--) {
        *(char *) dest = *(char *) src;
        dest = (char *) dest + 1;
        src = (char *) src + 1;
//        *((char*)dest)++ = *((char*)src)++;//��ͨ��
        //ע�⣬����(char*)dest++��ǿ������ת����һ����ʱ״̬������ǰ��++���Ǻ���++��++ִ��ʱdest�Ѿ�����char*�˶������void*
    }
    return tmp;
}

void *myMemmove(void *dest, const void *src, size_t count) {
    assert(dest && src);
    char* tmp = (char*)dest;
    if( dest < src)
    {
        //��ǰ��󿽱�
        while(count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        //�Ӻ���ǰ����
        while(count--)
        {
            *((char*)dest + count) = *((char*)src + count);
        }
    }
    return tmp;
}

