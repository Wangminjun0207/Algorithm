#include "predefine.h"

//创建一个链表头结点，数据域不存储数据
LinkList createNode()
{
    LinkList p = (LinkList)malloc(sizeof(LinkList));
    if(p)
    {
        p->next = NULL;
    }
    else{exit(0);}
    return p;
}
