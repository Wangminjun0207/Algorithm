#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

// 节点数据结构
typedef struct node
{
    int key; // 关键字
    struct node *lchild, *rchild; // 左右儿子指针
}BSTNode, *BST;
#endif // PREDEFINE_H_
