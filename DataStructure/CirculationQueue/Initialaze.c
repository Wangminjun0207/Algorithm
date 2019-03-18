#include "Predefine.h"
// 初始化队列
void initQueue(SqQueue *queue, int n)
{
    queue->n = n;
    queue->r = queue->f = -1; // 队头。队尾同时指向同一个数据单元
    queue->elem = (char *)malloc(sizeof(char)*n);
}
