#include "Travel.h"
#include <fstream>
#include <queue>

Travel::Travel()
{
    InitGraph();
}

Travel::~Travel()
{
    //dtor
}

// 从i出发深度优先搜索
void DFS(Travel t, bool visited[], int i)
{
    std::cout << std::setw(3) << i;
    visited[i] = true;
    for(int it=t.FirstAdj(i);it!=-1;it=t.NextAdj(i,it))
    {
        if(visited[it]==false)
        {
            DFS(t,visited, it);
        }
    }
}

int Travel::InitGraph()
{
    // 从文件读取数据建立图
    std::ifstream file;
    file.open("input.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cout << "can not open file!\n";
        return 0; // 创建图失败
    }
    file >> node_count_;
    for(int it=0;it<node_count_;it++)
    {
        for(int j=0;j<node_count_;j++)
        {
            file >> arcs[it][j];
        }
    }
    return 1; // 创建图成功
}

int Travel::DFSTravel()
{
    // 借助辅助数组进行深度优先搜索
    bool *visited = new bool[node_count_];
    for(int it=0;it<node_count_;it++)
    {
        visited[it] = false;
    }

    // 保证非连通图的遍历
    for(int it=0;it<node_count_;it++)
    {
        if(visited[it]==false)
        {
            DFS(*this,visited, it);
        }
    }
    std::cout << std::endl;
    delete []visited;
    return 1; // 成功遍历
}

int Travel::BFSTravel()
{
    bool *visited = new bool[node_count_];
    for(int it=0;it<node_count_;it++)
    {
        visited[it] = false;
    }
    std::queue<int> Queue; // 初始化队列
    for(int it=0;it<node_count_;it++)
    {
        if(visited[it]!=true)
        {
            std::cout << std::setw(3) << it; // 访问节点
            visited[it] = true; // 标记访问过的节点
            Queue.push(it);
            while(!Queue.empty())
            {
                int temp = Queue.front(); // 返回队头元素
                Queue.pop(); // 队头元素出队
                for(int v=FirstAdj(temp);v!=-1;v=NextAdj(temp,v))
                {
                    if(!visited[v])
                    {
                        std::cout << std::setw(3) << v; // 访问节点
                        visited[v] = true; // 标记访问过的节点
                        Queue.push(v);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    delete []visited;
    return 1; // 成功遍历
}

int Travel::FirstAdj(int i)
{
    for(int j=0;j<node_count_;j++)
    {
        if(arcs[i][j])
        {
            return j;
        }
    }
    return -1; // 没有下一节点返回-1
}

int Travel::NextAdj(int i, int j)
{
    // j是最后一个节点
    if(j==node_count_-1)
    {
        return -1;
    }
    for(int it=j+1;it<node_count_;it++)
    {
        if(arcs[i][it])
        {
            return it;
        }
    }
    return -1; // 没有下一节点返回-1
}
