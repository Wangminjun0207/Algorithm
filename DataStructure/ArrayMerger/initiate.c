#include "predefine.h"

//��ʼ���ڵ�Ĳ������Լ����ڵ���������鶯̬�����ڴ�
Status initiate(SqList *pL, int max_size)
{
    pL->n = 0;
    pL->max_size = max_size;
    pL->elme = (int *)malloc(sizeof(int)*max_size);
    if(NULL == pL)
    {
        return ERROR;
    }
    return OK;
}
