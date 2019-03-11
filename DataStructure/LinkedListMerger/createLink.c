#include "predefine.h"
extern LinkList createNode();

//创建一个先入先出的链表，直到输入0结束
LinkList createLink()
{
    LinkList p, last, h = createNode();
    last = h;
    int e;
    while(1)
    {
        scanf("%d",&e);
        if(!e) break;//输入的数字为0，跳出循环
        p = createNode();
        p->nNumber = e;
        last->next = p;
        last = p;
    }
    return h;
}
