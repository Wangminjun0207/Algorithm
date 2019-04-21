#include "Predefine.h"
extern void visit(const BiTree bt);
// 用中序遍历算法遍历二叉树
void midorder(const BiTree bt)
{
    if(bt)
    {
        preorder(bt->lelf_child);
		visit(bt);
        preorder(bt->right_child);
    }
}
