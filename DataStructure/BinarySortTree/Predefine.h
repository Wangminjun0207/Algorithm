#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>

// �ڵ����ݽṹ
typedef struct node
{
    int key; // �ؼ���
    struct node *lchild, *rchild; // ���Ҷ���ָ��
}BSTNode, *BST;
#endif // PREDEFINE_H_
