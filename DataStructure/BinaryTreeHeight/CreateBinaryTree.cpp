#include "Predefine.h"
// 用先序遍历算法建立二叉树
BiTree CrtBT()
{
    char ch = getchar();
    if(ch=='#') // 输入#字符表示NULL指针域
        return NULL;
    BiTree bt = new BiTreeNode();
    bt->data = ch;
    bt->lelf_child = CrtBT();  // 建立左子树
    bt->right_child = CrtBT(); // 建立右子数
    return bt;
}

