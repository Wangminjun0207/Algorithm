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
    ElemTp data;                // ������
    struct node *lelf_child,    // ��ָ��
                *right_child;   // ��ָ��
}*BiTree, BiTreeNode;

typedef struct Queue{
    BiTree Node; // ������
    int f; // ��ͷָ��
    int r; // ��βָ��
}*BiTreeQueue, BiTreeNodeQueue;
#endif // _PREDEFINE_H_
