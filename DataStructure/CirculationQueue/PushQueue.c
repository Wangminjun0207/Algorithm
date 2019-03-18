#include "Predefine.h"
extern int full(SqQueue *q);
// 元素入队，入队成功返回1，失败返回0
int pushQueue(SqQueue *q, char *ch)
{
    if(full(q))
        return 0; // 队满，入队失败
    q->r = (q->r+1)%q->n;
    q->elem[q->r] = *ch;
    return 1;// 入队成功，返回1
}
