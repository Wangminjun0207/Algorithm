#include "predefine.h"

void display(SqList *p)
{
    int i = 0;
    //以节点的实际长度控制循环
    while(i < p->n)
    {
        printf("%5d",p->elme[i]);
        i++;
    }
    printf("\n");
}
