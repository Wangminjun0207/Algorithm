#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int *elme;
    int max_size;//˳����������
    int n;//���Ա�ʵ�ʳ���
}SqList;
typedef enum {ERROR, OK} Status;
