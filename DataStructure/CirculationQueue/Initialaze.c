#include "Predefine.h"
// ��ʼ������
void initQueue(SqQueue *queue, int n)
{
    queue->n = n;
    queue->r = queue->f = -1; // ��ͷ����βͬʱָ��ͬһ�����ݵ�Ԫ
    queue->elem = (char *)malloc(sizeof(char)*n);
}
