#include "Predefine.h"
extern void visit(const BiTree bt);
// 用先序遍历算法遍历二叉树
void preorder(const BiTree bt)
{
    if(bt)
    {
        visit(bt);
        preorder(bt->lelf_child);
        preorder(bt->right_child);
    }
}
