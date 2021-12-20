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
//        *((char*)dest)++ = *((char*)src)++;//不通过
        //注意，不能(char*)dest++，强制类型转换是一种临时状态，不论前置++还是后置++，++执行时dest已经不是char*了而变回了void*
    }
    return tmp;
}

void *myMemmove(void *dest, const void *src, size_t count) {
    assert(dest && src);
    char* tmp = (char*)dest;
    if( dest < src)
    {
        //从前向后拷贝
        while(count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src = (char*)src + 1;
        }
    }
    else
    {
        //从后向前拷贝
        while(count--)
        {
            *((char*)dest + count) = *((char*)src + count);
        }
    }
    return tmp;
}

