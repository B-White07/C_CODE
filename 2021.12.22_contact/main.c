#include "contact.h"

void menu()
{
    printf("*****************************\n");
    printf("***   1.add      2.del    ***\n");
    printf("***   3.modify   4.search ***\n");
    printf("***   5.sort     6.show   ***\n");
    printf("***        0.exit         ***\n");
    printf("*****************************\n");
}
enum Option
{
    EXIT,
    ADD,
    DEL,
    MODIFY,
    SEARCH,
    SORT,
    SHOW
};

int main() {
/*
 * 通讯录
 * 1。通讯录中能够存放1000个人的信息，每个人的信息包含：名字，年龄，性别，电话，地址
 * 2。增删改查指定人的信息
 * 3。排序通讯录信息
 */
    //创建通讯录
    Contact con;
    //初始化通讯录
    //在堆区给peo申请一块连续的空间
    initContact2(&con);

    int input = 0;
    do {

        menu();
        printf("请选择：");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:
                addContact2(&con);
                break;
            case DEL:
                delContact(&con);
                break;
            case MODIFY:
                modfContact(&con);
                break;
            case SEARCH:
                searContact(&con);
                break;
            case SORT:
                sortContact(&con);
                break;
            case SHOW:
                showContact(&con);
                break;
            case EXIT:
                //销毁通讯录
                destoryContact(&con);
                printf("即将退出...");
                return 0;
            default:
                printf("请输入有效选项\n");
                break;
        }
    }while(input);







    return 0;
}
