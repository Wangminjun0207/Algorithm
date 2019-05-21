#ifndef PREDEFINE_H_
#define PREDEFINE_H_

#include <iostream>
#define MAX_N 10 // 最大节点数

// 邻接表节点数据结构
typedef struct node{
   int code; // 节点下标
   struct node *next;
}ArcNode;

// 邻接表头结点数据结构
typedef struct{
    int info; // 顶点入度
    int k;    // 顶点出度
    int i;    // 顶点下标
    ArcNode *firstarc;
}HNode;

// DAG图数据结构
typedef struct{
    int n; // 实际顶点数目
    HNode h[MAX_N]; // 头结点数组
}DAGGraph;

#endif // PREDEFINE_H_
