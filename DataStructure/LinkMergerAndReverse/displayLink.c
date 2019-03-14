#include "Predefine.h"
//输出链表的数据域
void displayLink(LinkList h)
{
    LinkList p = h->next;//p指向有数据的第一个节点
    //如果p不为空，继续遍历链表
    while(p)
    {
        printf("%5d",p->nNumber);
        p = p->next;
    }
    printf("\n");
}
