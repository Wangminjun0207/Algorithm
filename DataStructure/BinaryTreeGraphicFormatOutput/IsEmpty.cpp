#include "Predefine.h"

// �ж϶����Ƿ�Ϊ��
int isEmpty(const BiTreeQueue Q)
{
    if(Q->f==Q->r)
    {
        return 1; // ����Ϊ�շ���1
    }
    else
    {
        return 0; // ���в��շ���0
    }
}

