#include <iostream>
#include "Predefine.h"

extern int InitGraph(DAGGraph &graph);
extern bool TopoSort(DAGGraph &graph);

int main()
{
    DAGGraph graph;
    InitGraph(graph); // ��ʼ��DAG
    bool result = TopoSort(graph);  // ��������
    if(result==false)
    {
        std::cout << "Not DAG." << std::endl;
    }
    return 0;
}
