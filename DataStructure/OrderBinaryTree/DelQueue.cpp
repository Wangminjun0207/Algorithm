#include "Predefine.h"
// ��ͷԪ�س���
BiTree delQueue(const BiTreeQueue Q)
{
    if(Q->f==Q->r)
    {
        return NULL;
    }
    Q->f = (Q->f + 1)%30;
    BiTree q = new BiTreeNode;
    q = &Q->Node[Q->f]; // ��ͷԪ�س���
    return q;
}
