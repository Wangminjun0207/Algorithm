#include "Predefine.h"
// 队头元素出队
BiTree delQueue(const BiTreeQueue Q)
{
    if(Q->f==Q->r)
    {
        return NULL;
    }
    Q->f = (Q->f + 1)%30;
    BiTree q = new BiTreeNode;
    q = &Q->Node[Q->f]; // 队头元素出队
    return q;
}
