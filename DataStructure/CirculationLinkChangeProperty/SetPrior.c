#include <stdlib.h>
#include "Predefine.h"

//ʹ�õ���ѭ�������Ϊ˫��ѭ������
int stePrior(NodePtr h)
{
    //������Ľڵ�hΪ�ջ��߾�ֻ��hһ���ڵ㣬����򷵻�-1
    if(h==NULL)
        return -1001;
    else if(h->next==h)
    {
        h->prior = h;
        return 0;
    }
    NodePtr p, q;
    q = h; //h��ֵ��q
    p = h->next;
    while(p != h)
    {
        p->prior = q;
        q = p;
        p = p->next;
    }
    p->prior = q;
    return 0;
}
