#include "predefine.h"

//�ڽڵ������в������ݣ����ݱ����С����������0�������룬���߳���max_size�Զ�ֹͣ
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
