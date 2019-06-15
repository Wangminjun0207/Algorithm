#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

// 节点数据结构
typedef struct node
{
    unsigned int key;
    struct node *next;
}Node, *NodePtr;

// 辅助排序数据结构
typedef struct link
{
    NodePtr ptr;
    NodePtr Sort[16];
}Link;

#endif // PREDEFINE_H_
