#include "Predefine.h"
// ����������ĸ߶�
int TreeHeight(BiTree bt)
{
    if(!bt) return 0;
    int hl_val = TreeHeight(bt->lelf_child);    // �����ĸ߶�Ϊ0
    int hr_val = TreeHeight(bt->right_child);   // �������ĸ߶�
    return (hl_val>hr_val?hl_val:hr_val)+1;     // �������ĸ߶�
}
