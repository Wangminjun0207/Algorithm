#include "Predefine.h"
extern int Insert(BST &bt, BST p);

// 二叉排序树的建立方法
BST CreateBST(int arr[], int n)
{
    BST bt = NULL;
    // 逐个节点插入
    for(int it=0;it<n;it++)
    {
        BST p = new BSTNode();
        p->key = arr[it];
        p->lchild = p->rchild = NULL;
        Insert(bt,p);
    }
    return bt;
}
