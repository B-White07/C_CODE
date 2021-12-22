//
// Created by B_White on 2021/12/22.
//
#include "contact.h"

//void initContact(Contact *pcon) {
//    assert(pcon);
//    pcon->sz = 0;
//    //内存设置
//    memset(pcon->peo, 0, sizeof(pcon->peo));
//}
void initContact2(Contact *pcon) {
    assert(pcon);
    pcon->peo = (PeoInfo *) malloc(DEFAULT_SIZE * sizeof(PeoInfo));
    if (NULL == pcon->peo) {
        perror("initContact2");
        return;
    }
    pcon->sz = 0;
    pcon->capacity = DEFAULT_SIZE;
}

//void addContact(Contact *pcon) {
//    assert(pcon);
//    if (pcon->sz == MAX) {
//        printf("通讯录已满，无法添加\n");
//        return;
//    }
//    printf("请输入姓名：\n");
//    scanf("%s", pcon->peo[pcon->sz].name);
//    printf("请输入年龄：\n");
//    scanf("%d", &(pcon->peo[pcon->sz].age));
//    printf("请输入性别：\n");
//    scanf("%s", pcon->peo[pcon->sz].sex);
//    printf("请输入电话：\n");
//    scanf("%s", pcon->peo[pcon->sz].tel);
//    printf("请输入地址：\n");
//    scanf("%s", pcon->peo[pcon->sz].addr);
//    pcon->sz++;
//    printf("添加成功！\n");
//}

void addContact2(Contact *pcon) {
    assert(pcon);
    if (pcon->sz == pcon->capacity) {
        //增容
        PeoInfo * tmpPeo = (PeoInfo*)realloc(pcon->peo,(pcon->capacity+INC_SIZE)*sizeof(PeoInfo));
        if(NULL == tmpPeo) {
            perror("addContact2");
            printf("添加联系人失败\n");
            return;
        }
        else{
            pcon->peo = tmpPeo;
            pcon->capacity += INC_SIZE;
            printf("扩容成功\n");
        }
    }
    printf("请输入姓名：\n");
    scanf("%s", pcon->peo[pcon->sz].name);
    printf("请输入年龄：\n");
    scanf("%d", &(pcon->peo[pcon->sz].age));
    printf("请输入性别：\n");
    scanf("%s", pcon->peo[pcon->sz].sex);
    printf("请输入电话：\n");
    scanf("%s", pcon->peo[pcon->sz].tel);
    printf("请输入地址：\n");
    scanf("%s", pcon->peo[pcon->sz].addr);
    pcon->sz++;
    printf("添加成功！\n");
}

void showContact(const Contact *pcon) {
    assert(pcon);
    printf("%-15s\t%-10s\t\t%-10s\t\t%-15s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
    for (int i = 0; i < pcon->sz; i++) {
        printf("%-15s\t%-10s\t%-10d\t%-15s\t%-30s\n", pcon->peo[i].name, pcon->peo[i].sex,
               pcon->peo[i].age, pcon->peo[i].tel, pcon->peo[i].addr);
    }
}

static int searchByName(const Contact *pcon, char name[]) {
    assert(pcon);
    for (int i = 0; i < pcon->sz; i++) {
        if (0 == strcmp(pcon->peo[i].name, name))
            return i;//找到返回下标
    }
    return -1;//找不到
}

void delContact(Contact *pcon) {
    assert(pcon);
    if (0 == pcon->sz) {
        printf("通讯录已空，无法删除！\n");
        return;
    }

    char name[MAX_NAME] = {0};
    printf("请输入要删除的用户的姓名：\n");
    scanf("%s", name);
    //查找要删除的人
    int peoIndex = searchByName(pcon, name);
    if (-1 == peoIndex) {
        printf("查无此人，请确认姓名是否正确\n");
        return;
    }

    //删除
    for (int i = peoIndex; i < pcon->sz - 1; i++) {
        pcon->peo[i] = pcon->peo[i + 1];//结构体可以直接用=赋值
    }
    pcon->sz--;
    printf("删除成功！\n");
}

void searContact(const Contact *pcon) {
    assert(pcon);
    char name[MAX_NAME] = {0};
    printf("请输入要查找的用户的姓名：\n");
    scanf("%s", name);
    int res = searchByName(pcon, name);
    if (-1 == res) {
        printf("查无此人！\n");
        return;
    }

    printf("%-15s\t%-10s\t\t%-10s\t\t%-15s\t%-30s\n", "姓名", "性别", "年龄", "电话", "住址");
    printf("%-15s\t%-10s\t%-10d\t%-15s\t%-30s\n", pcon->peo[res].name, pcon->peo[res].sex,
           pcon->peo[res].age, pcon->peo[res].tel, pcon->peo[res].addr);

}

void modfContact(Contact *pcon) {
    assert(pcon);
    char name[MAX_NAME] = {0};
    printf("请输入要修改的用户的姓名：\n");
    scanf("%s", name);
    int res = searchByName(pcon, name);
    if (-1 == res) {
        printf("查无此人！\n");
        return;
    }
    printf("请输入修改后的姓名：\n");
    scanf("%s", pcon->peo[res].name);
    printf("请输入修改后的年龄：\n");
    scanf("%d", &(pcon->peo[res].age));
    printf("请输入修改后的性别：\n");
    scanf("%s", pcon->peo[res].sex);
    printf("请输入修改后的电话：\n");
    scanf("%s", pcon->peo[res].tel);
    printf("请输入修改后的地址：\n");
    scanf("%s", pcon->peo[res].addr);
    printf("修改成功！\n");
}

void sortContact(Contact *pcon) {
    assert(pcon);
    for (int i = 0; i < pcon->sz - 1; i++) {
        if (0 < strcmp(pcon->peo[i].name, pcon->peo[i + 1].name)) {
            PeoInfo tmpInfo = pcon->peo[i];
            pcon->peo[i] = pcon->peo[i + 1];
            pcon->peo[i + 1] = tmpInfo;
        }
    }
    printf("排序成功!\n");
}

void destoryContact(Contact *pcon)
{
    assert(pcon);
    free(pcon->peo);
    pcon->peo = NULL;
    pcon->sz = 0;
    pcon->capacity = 0;
}