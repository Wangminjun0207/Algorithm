#include "Predefine.h"
// 判断队列是否为空，为空返回1
int empty(SqQueue *q)
{
    return q->f==q->r; // 如果队满，返回1，否则返回0
}
