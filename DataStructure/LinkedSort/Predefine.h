#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <cstdlib>

typedef struct node
{
    int key; // 关键字
    struct node *next; // 节点指针
}Node, *NodePtr;

#endif // PREDEFINE_H_
