#include "Predefine.h"

BiTree CrtBT()
{
	/**
	 * 使用先序遍历建立二叉树
	 * 返回二叉树头结点指针
	 */ 
    char ch = getchar();
    if(ch=='#') // 输入#字符表示NULL指针域
        return NULL;
    BiTree bt = new BiTreeNode();
    bt->data = ch;
    bt->lelf_child = CrtBT();  // 建立左子树
    bt->right_child = CrtBT(); // 建立右子数
    return bt;
}
