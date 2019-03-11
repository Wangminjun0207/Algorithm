#include "predefine.h"

//实现对于一个单向链表的逆序排列
void reverse(NodePtr h)
{
    NodePtr q, s;
    q = h->next;//q指向第一个数据节点
    h->next = NULL;
    while(q)
    {
        s = q;
        q = q->next;
        //s所指的节点插到链表头部
        s->next = h->next;
        h->next = s;
    }
}
