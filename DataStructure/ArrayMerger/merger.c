#include "predefine.h"

//对于la, lb 按升序归并到lc中
Status merger(SqList *la, SqList *lb, SqList *lc)
{
    if(la->n + lb->n >lc->max_size)
        return ERROR;
    int i, j, k;
    i = j = k = 0;
    lc->n = la->n + lb->n;
    while(i<la->n && j<lb->n)
    {
        if(la->elme[i] < lb->elme[j])
            lc->elme[k++] = la->elme[i++];
        else
            lc->elme[k++] = lb->elme[j++];
    }
    while(i < la->n)
        lc->elme[k++] = la->elme[i++];
    while(j < lb->n)
        lc->elme[k++] = lb->elme[j++];
    return OK;
}
