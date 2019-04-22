#include "Predefine.h"

// 判断队列是否为空
int isEmpty(const BiTreeQueue Q)
{
    if(Q->f==Q->r)
    {
        return 1; // 队列为空返回1
    }
    else
    {
        return 0; // 队列不空返回0
    }
}

