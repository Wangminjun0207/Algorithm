#include "Predefine.h"
#include <stdlib.h>

//���������ݽ�������
void reverseLink(NodePtr h)
{
    NodePtr s, p = h->next; //�Ͽ���Ч�����ͷ�ڵ�,pָ���һ����Чָ��
    h->next = NULL;
    while(p)
    {
        s = p;
        p = p->next; // pɨ��������һ�ڵ�
        s->next = h->next; // �����ȳ�����ڵ㣬ʵ������
        h->next = s;
    }
}
