#include <stdlib.h>
#include "Predefine.h"

//ɾ�����������Ľڵ㣬���ͷŽڵ�
int delNode(NodePtr h, int mink, int maxk)
{
    if(mink >= maxk) // ���mink>=maxk,�򷵻�-1
        return -1;
    int nCounter = 0;
    NodePtr p, q, pt;
    for(q=h,p=h->next;p!=NULL;)//��qָ��ͷ��㣨����Ч���ݣ���pָ���һ����Ч�ڵ�
    {
        if(p->n > mink && p->n < maxk)
        {
            pt = p;//��¼���������Ľڵ�
            q->next = p->next;//�Ͽ�p�ڵ�֮���������
            free(pt);
            p = q->next;//p�ڵ���ǰɨ��
            nCounter++;
        }
        else{
            q = p;      //���û�ҵ����������Ľڵ㣬p,q�ڵ�ͬʱ��ǰɨ��
            p = p->next;
        }
    }
    q->next=NULL;
    if(!nCounter)   //���û���ҵ����򷵻�1
        return 1;
    return 0;
}
