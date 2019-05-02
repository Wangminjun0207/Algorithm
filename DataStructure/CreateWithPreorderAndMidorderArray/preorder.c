#include "Predefine.h"
extern void visit(const BiT bt);
// 用先序遍历算法遍历二叉树
void preorderTree(const BiT bt)
{
    if(bt)
    {
        visit(bt);
        preorderTree(bt->left_child);
        preorderTree(bt->right_child);
    }
}
