#include <stdlib.h>
#include "Predefine.h"

//使得单向循环链表变为双向循环链表
int stePrior(NodePtr h)
{
    //如果给的节点h为空或者就只有h一个节点，则程序返回-1
    if(h==NULL)
        return -1001;
    else if(h->next==h)
    {
        h->prior = h;
        return 0;
    }
    NodePtr p, q;
    q = h; //h赋值给q
    p = h->next;
    while(p != h)
    {
        p->prior = q;
        q = p;
        p = p->next;
    }
    p->prior = q;
    return 0;
}
