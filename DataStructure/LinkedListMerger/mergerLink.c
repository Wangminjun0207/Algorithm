#include "Predefine.h"

//��������ϲ�Ϊһ������ʹ�õ���������������
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
        if(pa) pc->next = pa;//���pa��ָ������û�б����ֱ꣬�ӽӵ�pc��ָ����֮��
        if(pb) pc->next = pb;//���pb��ָ������û�б����ֱ꣬�ӽӵ�pc��ָ����֮��
        ha->next = hb->next = NULL;
    }
    return hc;
}
