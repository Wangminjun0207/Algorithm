#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>
#define MAX_N 20
typedef int ElemTp;

typedef struct node
{
    //double w; // ����Ȩ��
    int i, j; // ���Ķ˵��±�
    struct node *hlink;
    struct node *vlink;
}OLANode;

typedef struct
{
    //ElemTp data; // ��������
    int i; // �����±�
    OLANode *firstin;
    OLANode *firstout;
}OLHNode;

typedef struct
{
    OLHNode h[MAX_N]; // ͷ�ڵ�����
    int n, e; // n:ʵ�ʶ����� e:�ߵ���Ŀ
}OLGraph;

#endif // PREDEFINE_H_
