#include "Predefine.h"
#include <iostream>

// �����������Ĳ����㷨(�ǵݹ��㷨)
std::vector<BST> Search(BST bt, int k)
{
    BST parent = NULL;
    while(bt && bt->key!=k)
    {
        if(k<bt->key)
        {
            parent = bt;
            bt = bt->lchild;
        }
        else{
            parent = bt;
            bt = bt->rchild;
        }
    }
    std::vector<BST> result(2);
    result.at(0) = bt;
    result.at(1) = parent;
    if(result.at(0))
        std::cout << "�鵽" << std::endl;
    return result;
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
