//
// Created by B_White on 2021/12/22.
//
#ifndef INC_2021_12_22_CONTACT_CONTACT_H
#define INC_2021_12_22_CONTACT_CONTACT_H
#endif //INC_2021_12_22_CONTACT_CONTACT_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TEL 15
#define MAX_ADDR 30

#define DEFAULT_SIZE 3
#define INC_SIZE 2

#define MAX 1000

//用户信息
typedef struct PeoInfo
{
    int age;
    char name[MAX_NAME];
    char sex[MAX_SEX];
    char tel[MAX_TEL];
    char addr[MAX_ADDR];
}PeoInfo;

//通讯录，静态版本
//typedef struct Contact
//{
//    PeoInfo peo[MAX];//存放用户的信息
//    int sz;//记录当前通讯录用户的个数
//}Contact;
//动态版
typedef struct Contact
{
    PeoInfo* peo;//指向动态内存空间，用来存放联系人的信息
    int sz;//记录当前通讯录用户的个数
    int capacity//记录当前通讯录的最大容量
}Contact;

//初始化通讯录，静态
//void initContact(Contact* pcon);
//动态
void initContact2(Contact* pcon);

//void addContact(Contact *pcon);
//动态增加
void addContact2(Contact *pcon);

void showContact(const Contact *pcon);
void delContact(Contact *pcon);
void searContact(const Contact *pcon);
void modfContact(Contact *pcon);
void sortContact(Contact *pcon);

void destoryContact(Contact *pcon);