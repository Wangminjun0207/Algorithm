#include "Predefine.h"
extern int Insert(BST &bt, BST p);

// �����������Ľ�������
BST CreateBST(int arr[], int n)
{
    BST bt = NULL;
    // ����ڵ����
    for(int it=0;it<n;it++)
    {
        BST p = new BSTNode();
        p->key = arr[it];
        p->lchild = p->rchild = NULL;
        Insert(bt,p);
    }
    return bt;
}
