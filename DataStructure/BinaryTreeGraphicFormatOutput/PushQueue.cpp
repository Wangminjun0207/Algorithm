#include "Predefine.h"

// �������ڵ����
int enQueue(const BiTreeQueue Q,BiTree bt)
{
    if((Q->r+1)%30==(Q->f+30)%30)
    {
        return 0;
    }
    Q->r = (Q->r+1)%30;
    Q->Node[Q->r] = *bt;
    return 1; // ��ӳɹ�����1
}
