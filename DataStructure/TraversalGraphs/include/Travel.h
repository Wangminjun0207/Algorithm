#ifndef TRAVEL_H
#define TRAVEL_H
#include <iostream>
#include <iomanip>

#define MAX_N 20 // 最大节点数目
class Travel
{
    public:
        Travel();
        virtual ~Travel();
        int InitGraph(); // 初始化图
        int DFSTravel(); // 深度优先搜索
        int BFSTravel(); // 广度优先搜索
        int FirstAdj(int i);  // 返回节点i的第一个邻接节点
        int NextAdj(int i, int j); // 返回节点i的关于节点j的下一个节点
        friend void DFS(Travel t, bool visited[], int i);
    protected:

    private:
        int node_count_; // 节点数目
        int arcs[MAX_N][MAX_N]; // 邻接矩阵
};



#endif // TRAVEL_H
