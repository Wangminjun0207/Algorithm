#include <stdlib.h>
#include "Predefine.h"

//ɾ�����������Ľڵ㣬���ͷŽڵ�
void delNode(NodePtr h)
{
    NodePtr p, q, pt;
    while(h=h->next,h!=NULL) //��hָ��ͷ��㣨����Ч���ݣ�
    {
        for(q=h,p=h->next;p!=NULL;)//qָ���һ����Ч�ڵ�,pָ��ڶ�����Ч�ڵ�
        {
            if(h->n == p->n)
            {
                pt = p;//��¼���������Ľڵ�
                q->next = p->next;//�Ͽ�p�ڵ�֮���������
                free(pt);
                p = q->next;//p�ڵ���ǰɨ��
            }
            else{
                q = p;      //���û�ҵ����������Ľڵ㣬p,q�ڵ�ͬʱ��ǰɨ��
                p = p->next;
            }
        }
        q->next=NULL;
    }
    return 0;
}
