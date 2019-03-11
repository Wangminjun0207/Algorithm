#include "predefine.h"

//实现单向链表的升序排序
void sort(NodePtr h)
{
    NodePtr pr, p, q, s;
    q = h->next;
    h->next = NULL;//断开附加头结点，成为空链表
    while(q)
    {
        s = q;
        q = q->next;
        pr = h;
        p = h->next;
        while(p && p->data < s->data)
        {
            pr = p;
            p = p->next;
        }
        //插入s所指节点到升序链表中
        pr->next = s;
        s->next = p;
    }
}
