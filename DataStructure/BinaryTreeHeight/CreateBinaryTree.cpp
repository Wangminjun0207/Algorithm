#include "Predefine.h"
// ����������㷨����������
BiTree CrtBT()
{
    char ch = getchar();
    if(ch=='#') // ����#�ַ���ʾNULLָ����
        return NULL;
    BiTree bt = new BiTreeNode();
    bt->data = ch;
    bt->lelf_child = CrtBT();  // ����������
    bt->right_child = CrtBT(); // ����������
    return bt;
}

