#include "Predefine.h"
extern void visit(const BiTree bt);
// ����������㷨����������
void preorder(const BiTree bt)
{
    if(bt)
    {
        visit(bt);
        preorder(bt->lelf_child);
        preorder(bt->right_child);
    }
}
