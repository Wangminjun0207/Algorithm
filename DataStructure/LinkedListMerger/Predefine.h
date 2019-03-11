#include <stdlib.h>
#include <stdio.h>
//定义一个带有一个数据和一个指针的结构体

typedef struct node
{
    int nNumber;
    struct node *next;
}LinkNode, *LinkList;
