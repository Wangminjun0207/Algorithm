#ifndef PREDEFINE_H_
#define PREDEFINE_H_
#include <iostream>

#define MAX_COUNT 10
// �������ݽṹ
typedef struct Graph{
    int n; // ������
    int w[MAX_COUNT][MAX_COUNT]; // ��Ӿ���
}Network;

typedef struct{
    int vex;
    double lowcost;
}CD_TP; // closedge����Ԫ������

#endif // PREDEFINE_H_
