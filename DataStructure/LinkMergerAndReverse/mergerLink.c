#include "Predefine.h"

//��������ϲ�Ϊһ������ʹ�õ����������ֽ���
LinkList mergerLink(LinkList ha, LinkList hb, LinkList hc)
{
    LinkList pa, pb, pc, p;
    pa = ha->next;
    pb = hb->next;
    pc = hc;
/*     �㷨���˼�룺���ҵ�������С�Ľڵ㣬ȡ�½ڵ����ӵ�hc��һ����Ч����λ�ã�
 *     ������������������������ha,hb����һ����ʱ��ʣ���ֱ������嵽hc
 *     �ĵ�һ����Ч���ݽڵ�
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
    ha->next = hb->next = NULL; // ha,hb�����ÿ�
    return hc;
}
