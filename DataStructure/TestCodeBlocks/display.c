#include "predefine.h"

//输出单向链表的节点数据
void display(NodePtr h)
{
    NodePtr p = h->next;//跳过头结点
    while(p)
    {
        printf("%8d",p->data);
        p = p->next;
    }
}
