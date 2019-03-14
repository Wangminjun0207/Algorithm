#include "Predefine.h"

//两个链表合并为一个链表，使得第三个链表保持降序
LinkList mergerLink(LinkList ha, LinkList hb, LinkList hc)
{
    LinkList pa, pb, pc, p;
    pa = ha->next;
    pb = hb->next;
    pc = hc;
/*     算法设计思想：先找到数据最小的节点，取下节点连接到hc第一个有效数据位置，
 *     按照先入后出连接链表，遍历完ha,hb其中一个的时候，剩余的直接逆序插到hc
 *     的第一个有效数据节点
 */
    while(pa && pb)
    {
        if(pa->nNumber <= pb->nNumber)
        {
            p = pa;
            pa = pa->next;
            p->next = pc->next;
            pc->next = p;
        }
        else{
            p = pb;
            pb = pb->next;
            p->next = pc->next;
            pc->next = p;
        }
    }
    while(pa)
    {
        p = pa;
        pa = pa->next;
        p->next = pc->next;
        pc->next = p;
    }
    while(pb)
    {
        p = pb;
        pb = pb->next;
        p->next = pc->next;
        pc->next = p;
    }
    ha->next = hb->next = NULL; // ha,hb链表置空
    return hc;
}
