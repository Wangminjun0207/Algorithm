#include "Predefine.h"
// 元素出队，出队成功返回1，否则返回0
extern int empty(SqQueue *q);
int popQueue(SqQueue *q, char *ch)
{
    if(empty(q))
        return 0;// ¶Ó¿Õ£¬³ö¶ÓÊ§°Ü
    q->f = (q->f+1)%q->n;
    *ch = q->elem[q->f];
    return 1;
}
