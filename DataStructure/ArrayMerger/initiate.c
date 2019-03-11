#include "predefine.h"

//初始化节点的参数，以及给节点的整形数组动态分配内存
Status initiate(SqList *pL, int max_size)
{
    pL->n = 0;
    pL->max_size = max_size;
    pL->elme = (int *)malloc(sizeof(int)*max_size);
    if(NULL == pL)
    {
        return ERROR;
    }
    return OK;
}
