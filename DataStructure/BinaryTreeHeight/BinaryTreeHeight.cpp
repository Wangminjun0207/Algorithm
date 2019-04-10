#include "Predefine.h"
// 计算二叉树的高度
int TreeHeight(BiTree bt)
{
    if(!bt) return 0;
    int hl_val = TreeHeight(bt->lelf_child);    // 空树的高度为0
    int hr_val = TreeHeight(bt->right_child);   // 左子树的高度
    return (hl_val>hr_val?hl_val:hr_val)+1;     // 右子树的高度
}
