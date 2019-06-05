#include "Predefine.h"
#include <iostream>
void Preorder(BST bt)
{
    if(bt)
    {
        Preorder(bt->lchild);
        std::cout << bt->key << "  ";
        Preorder(bt->rchild);
    }
}
