#include "predefine.h"

//ʵ�ֵ����������������
void sort(NodePtr h)
{
    NodePtr pr, p, q, s;
    q = h->next;
    h->next = NULL;//�Ͽ�����ͷ��㣬��Ϊ������
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
        //����s��ָ�ڵ㵽����������
        pr->next = s;
        s->next = p;
    }
}
