#ifndef _PREDEFINE_H_
#define _PREDEFINE_H_
#include <iostream>
#include <cstdlib>
#include <cstdio>
typedef int ElemTp;
// ʮ������ڵ���������
typedef struct node
{
    int i, j;            // �С����±�
    ElemTp data;         // �ڵ�����
    struct node *right,*down; // ��ָ�롢��ָ��
}OLNode, *OLink;
// ������¼ɾ���ڵ���У�����ÿ�δ�ͷ��ʼɾ��
#endif // _PREDEFINE_H_
