#include <stdlib.h>
#include "Predefine.h"

//ɾ�������ڵ����һ���ڵ�
int delNode(NodePtr s)
{
    //������Ľڵ�sΪ�ջ��߾�ֻ��sһ���ڵ㣬����򷵻�-1
    if(s==NULL || s->next==s)
        return -1;
    NodePtr p, q;
    p = s; //s��ֵ��p
    while(p->next != s)
    {
        q = p;
        p = p->next;
    }
    q->next = s;
    return 0;
}
