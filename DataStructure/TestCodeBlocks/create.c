#include "predefine.h"

NodePtr create()//first in first out, create linked list
{
    NodePtr h, last, p;
    int x;
    h = (NodePtr)malloc(sizeof(NodePtr));
    h->next = NULL;
    last = h;
    scanf("%d",&x);
    while(x)
    {
        p = (NodePtr)malloc(sizeof(NodePtr));
        p->data = x;
        p->next = NULL;
        last->next = p;
        last = p;
        scanf("%d",&x);
    }
    return h;
}
