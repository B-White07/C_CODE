//
// Created by B_White on 2021/12/22.
//
#include "utils.h"

int check_sys1() {
    int a = 1;
    if (1 == (*(char *) &a))
        return 1;//小端
    else
        return 0;//大端
}

int check_sys2() {
    union U {
        char c;
        int i;
    } u;
    u.i = 1;
    return u.c;
    //返回1是小端，0是大端
}
