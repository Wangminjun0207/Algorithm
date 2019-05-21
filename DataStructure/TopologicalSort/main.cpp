#include <iostream>
#include "Predefine.h"

extern int InitGraph(DAGGraph &graph);
extern bool TopoSort(DAGGraph &graph);

int main()
{
    DAGGraph graph;
    InitGraph(graph); // ≥ı ºªØDAG
    bool result = TopoSort(graph);  // Õÿ∆À≈≈–Ú
    if(result==false)
    {
        std::cout << "Not DAG." << std::endl;
    }
    return 0;
}
