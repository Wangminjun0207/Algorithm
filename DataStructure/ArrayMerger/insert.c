#include "predefine.h"

//在节点数组中插入数据，数据必须从小到大，且输入0结束输入，或者超出max_size自动停止
void insert(SqList * p)
{
    int e;
    scanf("%d",&e);
    while(p->n<p->max_size && e)
    {
        p->elme[p->n] = e;
        (p->n)++;
        scanf("%d",&e);
    }
}
