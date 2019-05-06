#ifndef _PREDEFINE_H_
#define _PREDEFINE_H_
#include <iostream>
#include <cstdlib>

typedef char ElemTp;
typedef struct node{
    ElemTp data;                // 数据域
    struct node *lelf_child,    // 左指针
                *right_child;   // 右指针
}*BiTree, BiTreeNode;
#endif // _PREDEFINE_H_

