#include "Predefine.h"
// �ж�ѭ�������Ƿ���������������1
int full(SqQueue *q)
{
//    math��-1 mod n = n-1
//    CProgram:-1 mod n = -1
    return (q->r+1)%q->n == (q->f+q->n)%q->n;
}
