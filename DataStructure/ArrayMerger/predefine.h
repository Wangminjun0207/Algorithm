#include <stdlib.h>
#include <stdio.h>
typedef struct
{
    int *elme;
    int max_size;//顺序表最大容量
    int n;//线性表实际长度
}SqList;
typedef enum {ERROR, OK} Status;
