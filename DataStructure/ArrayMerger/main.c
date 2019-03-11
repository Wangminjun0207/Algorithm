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
    //�����la,lb,lc��ʼ��ʧ�ܣ������˳�ִ��
    if(!(initiate(&la, 10)==OK && initiate(&lb, 10)==OK && initiate(&lc, 30)==OK))
    {
        printf("initiate failed!\n");
        exit(0);
    }
    printf("please input the first link until input zero, must from small to large:");
    insert(&la);
    printf("please input the second link until input zero, must from small to large:");
    insert(&lb);
    //���la,lb����ɹ�����ִ�й鲢�㷨
    if(merger(&la, &lb,&lc)==OK)
    {
        printf("merger link by the first and second link:");
        display(&lc);
    }
    else
        printf("merger failed!\n");
    return 0;
}

