#include "Predefine.h"

// ����������ڵ��㷨
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
            return 0; // �ؼ����Ѿ����ڣ����ٲ���
        }
    }
    // bt���ǿ���
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
    // bt�ǿ���
    else{
        bt = p;
    }
    return 1; // ����ɹ�
}
