#include <stdio.h>
#include <stdlib.h>
#include "predefine.h"

extern Status initiate(SqList *pL, int max_size);
extern void display(SqList * p);
extern void insert(SqList * p);
extern Status merger(SqList *la, SqList *lb, SqList *lc);
int main()
{
    SqList la, lb, lc;
    //如果拉la,lb,lc初始化失败，程序退出执行
    if(!(initiate(&la, 10)==OK && initiate(&lb, 10)==OK && initiate(&lc, 30)==OK))
    {
        printf("initiate failed!\n");
        exit(0);
    }
    printf("please input the first link until input zero, must from small to large:");
    insert(&la);
    printf("please input the second link until input zero, must from small to large:");
    insert(&lb);
    //如果la,lb插入成功，便执行归并算法
    if(merger(&la, &lb,&lc)==OK)
    {
        printf("merger link by the first and second link:");
        display(&lc);
    }
    else
        printf("merger failed!\n");
    return 0;
}

