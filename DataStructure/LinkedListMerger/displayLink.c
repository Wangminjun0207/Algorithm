#include "Predefine.h"
//��������������
void displayLink(LinkList h)
{
    LinkList p = h->next;//pָ�������ݵĵ�һ���ڵ�
    //���p��Ϊ�գ�������������
    while(p)
    {
        printf("%5d",p->nNumber);
        p = p->next;
    }
    printf("\n");
}
