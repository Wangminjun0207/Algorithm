#ifndef PREDEFINE_H_
#define PREDEFINE_H_

#include <iostream>
#define MAX_N 10 // ���ڵ���

// �ڽӱ�ڵ����ݽṹ
typedef struct node{
   int code; // �ڵ��±�
   struct node *next;
}ArcNode;

// �ڽӱ�ͷ������ݽṹ
typedef struct{
    int info; // �������
    int k;    // �������
    int i;    // �����±�
    ArcNode *firstarc;
}HNode;

// DAGͼ���ݽṹ
typedef struct{
    int n; // ʵ�ʶ�����Ŀ
    HNode h[MAX_N]; // ͷ�������
}DAGGraph;

#endif // PREDEFINE_H_
