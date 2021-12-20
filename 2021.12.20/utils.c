//
// Created by B_White on 2021/12/20.
//
#include "utils.h"



//结构体传参
void print1(struct S6 s)
{
    printf("%d\n",s.num);
}
void print2(struct S6* ps)
{
    printf("%d\n",ps->num);
}

