#include "predefine.h"

//�����������Ľڵ�����
void display(NodePtr h)
{
    NodePtr p = h->next;//����ͷ���
    while(p)
    {
        printf("%8d",p->data);
        p = p->next;
    }
}
