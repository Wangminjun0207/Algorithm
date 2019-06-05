#include <iostream>
#include "Predefine.h"
extern int Insert(BST &bt, BST p);
extern BST CreateBST(int arr[], int n);
extern BST Search(BST bt, int k);
extern int Delete(BST bt, int k);
extern void Preorder(BST bt);


int main()
{
    int arr[3] = {21, 23,/* 0, -8, 78, 1000, 45, -99, 88, */-1111};
    BST bt = CreateBST(arr,3);
    Preorder(bt);
    std::cout << std::endl;
    BST p = new BSTNode();
    p->key = 3333;
    p->lchild = p->rchild =NULL;
    Insert(bt,p);
    Preorder(bt);
    std::cout << std::endl;
    Delete(bt,21);
    Preorder(bt);
    std::cout << std::endl;
    bt = Search(bt,44);
    if(bt)
        std::cout << "search 3333 :" << bt->key << std::endl;
    else
        std::cout << "search 3333 : fail" << std::endl;
    return 0;
}
