#include "Predefine.h"
extern void visit(const BiTree bt);
// 用后序遍历算法遍历二叉树
void lasorder(const BiTree bt)
{
    if(bt)
    {
        preorder(bt->lelf_child);
        preorder(bt->right_child);
		visit(bt);
    }
}
