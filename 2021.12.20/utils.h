//
// Created by B_White on 2021/12/20.
//
#include <stdio.h>

#ifndef INC_2021_12_20_UTILS_H
#define INC_2021_12_20_UTILS_H

struct S6
{
    int data[1000];
    int num;
};
void print1(struct S6 s);
void print2(struct S6* ps);

#endif //INC_2021_12_20_UTILS_H
