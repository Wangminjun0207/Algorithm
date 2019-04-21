#include "Predefine.h"
extern void visit(const BiTree bt);
// 用中序遍历算法遍历二叉树
void midorder(const BiTree bt)
{
    if(bt)
    {
        midorder(bt->lelf_child);
		visit(bt);
        midorder(bt->right_child);
    }
}
