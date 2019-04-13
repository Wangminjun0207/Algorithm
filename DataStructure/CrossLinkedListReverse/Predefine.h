#ifndef _PREDEFINE_H_
#define _PREDEFINE_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
typedef int ElemTp;
// 十字链表节点数据类型
typedef struct node
{
    int i, j;            // 行、列下标
    ElemTp data;         // 节点数据
    struct node *right,*down; // 行指针、列指针
}OLNode, *OLink;

#endif // _PREDEFINE_H_
