#ifndef _PREDEFINE_H_
#define _PREDEFINE_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <math.h>
#include <string>

typedef char ElemTp;
typedef struct node{
    ElemTp data;                // 数据域
    struct node *lelf_child,    // 左指针
                *right_child;   // 右指针
}*BiTree, BiTreeNode;

typedef struct Queue{
    BiTree Node; // 数据域
    int f; // 队头指针
    int r; // 队尾指针
}*BiTreeQueue, BiTreeNodeQueue;
#endif // _PREDEFINE_H_
