#include <stdio.h>
#include <stdlib.h>

//创建只有一个数据的结构体
typedef struct node
{
    int data;
    struct node * next;
}NodeTp, *NodePtr;
