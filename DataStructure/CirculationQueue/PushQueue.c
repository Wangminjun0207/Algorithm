#include "Predefine.h"
extern int full(SqQueue *q);
// Ԫ����ӣ���ӳɹ�����1��ʧ�ܷ���0
int pushQueue(SqQueue *q, char *ch)
{
    if(full(q))
        return 0; // ���������ʧ��
    q->r = (q->r+1)%q->n;
    q->elem[q->r] = *ch;
    return 1;// ��ӳɹ�������1
}
