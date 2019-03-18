#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *elem;
    int n;// 队列容量
    int f;// 队头指针
    int r;//队尾指针
}SqQueue;
