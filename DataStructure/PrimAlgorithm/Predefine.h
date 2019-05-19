#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>

#define MAX_COUNT 10
// 网的数据结构
typedef struct Graph{
    int n; // 顶点数
    int w[MAX_COUNT][MAX_COUNT]; // 领接矩阵
}Network;

typedef struct{
    int vex;
    double lowcost;
}CD_TP; // closedge数组元素类型

#endif // PREDEFINE_H_
