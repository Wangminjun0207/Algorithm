#include "predefine.h"

//ʵ�ֶ���һ�������������������
void reverse(NodePtr h)
{
    NodePtr q, s;
    q = h->next;//qָ���һ�����ݽڵ�
    h->next = NULL;
    while(q)
    {
        s = q;
        q = q->next;
        //s��ָ�Ľڵ�嵽����ͷ��
        s->next = h->next;
        h->next = s;
    }
}
