#include "Predefine.h"
#include <iostream>

// �����������Ĳ����㷨(�ǵݹ��㷨)
BST Search(BST bt, int k)
{
    while(bt && bt->key!=k)
    {
        if(k<bt->key)
        {
            bt = bt->lchild;
        }
        else{
            bt = bt->rchild;
        }
    }
    if(bt)
        std::cout << "hhhhh" << std::endl;
    return bt;
}
/*

// �����������Ĳ����㷨(�ݹ��㷨)
BST Search(BST bt, int k)
{
    if(bt==NULL || k==bt->key)
    {
        return bt;
    }
    if(k<bt->key)
    {
        return Search(bt->lchild,k);
    }
    else{
        return Search(bt->rchild,k);
    }
}

*/
