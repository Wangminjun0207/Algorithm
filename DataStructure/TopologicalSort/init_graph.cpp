#include "Predefine.h"
#include <fstream>
#include <cstdlib>

int InitGraph(DAGGraph &graph)
{
    /** \brief 初始化DAG
     *
     * \param  DAG
     * \param  DAGGraph 的指针
     * \return 无返回值
     *
     */
    std::ifstream file;
    file.open("graph.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cout << "Can not open graph.txt!" << std::endl;
        exit(-1); // 异常退出
    }
    file >> graph.n;

    for(int it=0;it<graph.n;it++)
    {
        file >> graph.h[it].i; // 读入顶点下标
        file >> graph.h[it].info; // 读入顶点入度
        file >> graph.h[it].k; // 读入顶点出度
        graph.h[it].firstarc = NULL; // 邻接表头结点指针域置空
        ArcNode *p;
        // 读入每个顶点的邻接表
        for(int j=0;j<graph.h[it].k;j++)
        {
            ArcNode *Node = new ArcNode();
            file >> Node->code;
            Node->next = NULL; // 每个节点的指针域都置空
            if(j==0)
            {
                graph.h[it].firstarc = Node;
                p = graph.h[it].firstarc;
                continue;
            }
            p->next = Node;
            p = Node;
        }
    }
    file.close();
    return 0; // 初始化DAG成功
}
