#ifndef _PREDEFINE_H_
#define _PREDEFINE_H_
#include <iostream>
#include <cstdlib>

typedef char ElemTp;
typedef struct node{
    ElemTp data;                // ������
    struct node *lelf_child,    // ��ָ��
                *right_child;   // ��ָ��
}*BiTree, BiTreeNode;
#endif // _PREDEFINE_H_

