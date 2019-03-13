#include "Predefine.h"
#include <stdlib.h>

//对链表数据进行逆置
void reverseLink(NodePtr h)
{
    NodePtr s, p = h->next; //断开有效链表和头节点,p指向第一个有效指针
    h->next = NULL;
    while(p)
    {
        s = p;
        p = p->next; // p扫描链表下一节点
        s->next = h->next; // 后入先出插入节点，实现逆置
        h->next = s;
    }
}
