#include "Predefine.h"

//连个链表合并为一个链表，使得第三个链表保持升序
LinkList mergerLink(LinkList ha, LinkList hb, LinkList hc)
{
    LinkList pa, pb, pc, p;
    pa = ha->next;
    pb = hb->next;
    pc = hc;
    while(pa && pb)
    {
        if(pa->nNumber <= pb->nNumber)
        {
            p = pa;
            pa = pa->next;
            pc->next = p;
            pc = p;
        }
        else{
            p = pb;
            pb = pb->next;
            pc->next = p;
            pc = p;
        }
        if(pa) pc->next = pa;//如果pa所指的链表没有遍历完，直接接到pc所指链表之后
        if(pb) pc->next = pb;//如果pb所指的链表没有遍历完，直接接到pc所指链表之后
        ha->next = hb->next = NULL;
    }
    return hc;
}
