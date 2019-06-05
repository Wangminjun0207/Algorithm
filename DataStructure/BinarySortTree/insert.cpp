#include "Predefine.h"

// 二叉树插入节点算法
int Insert(BST &bt, BST p)
{
    BST parent = NULL;
    BST root = bt;
    while(root)
    {
        parent = root;
        if(p->key<root->key)
        {
            root = root->lchild;
        }
        else if(p->key>root->key)
        {
            root = root->rchild;
        }
        else{
            return 0; // 关键字已经存在，不再插入
        }
    }
    // bt不是空树
    if(parent)
    {
        if(p->key<parent->key)
        {
            parent->lchild = p;
        }
        else{
            parent->rchild = p;
        }
    }
    // bt是空树
    else{
        bt = p;
    }
    return 1; // 插入成功
}
