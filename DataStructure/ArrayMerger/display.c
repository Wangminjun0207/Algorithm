#include "predefine.h"

void display(SqList *p)
{
    int i = 0;
    //�Խڵ��ʵ�ʳ��ȿ���ѭ��
    while(i < p->n)
    {
        printf("%5d",p->elme[i]);
        i++;
    }
    printf("\n");
}
