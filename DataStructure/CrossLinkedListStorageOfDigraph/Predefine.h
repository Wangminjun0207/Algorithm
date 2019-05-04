#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>
#include <cstdlib>
#define MAX_N 20
typedef int ElemTp;

typedef struct node
{
    //double w; // 弧的权重
    int i, j; // 弧的端点下标
    struct node *hlink;
    struct node *vlink;
}OLANode;

typedef struct
{
    //ElemTp data; // 定点数据
    int i; // 顶点下标
    OLANode *firstin;
    OLANode *firstout;
}OLHNode;

typedef struct
{
    OLHNode h[MAX_N]; // 头节点数组
    int n, e; // n:实际定点数 e:边的数目
}OLGraph;

#endif // PREDEFINE_H_
