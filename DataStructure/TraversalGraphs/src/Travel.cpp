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

// ��i���������������
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
    // ���ļ���ȡ���ݽ���ͼ
    std::ifstream file;
    file.open("input.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cout << "can not open file!\n";
        return 0; // ����ͼʧ��
    }
    file >> node_count_;
    for(int it=0;it<node_count_;it++)
    {
        for(int j=0;j<node_count_;j++)
        {
            file >> arcs[it][j];
        }
    }
    return 1; // ����ͼ�ɹ�
}

int Travel::DFSTravel()
{
    // ��������������������������
    bool *visited = new bool[node_count_];
    for(int it=0;it<node_count_;it++)
    {
        visited[it] = false;
    }

    // ��֤����ͨͼ�ı���
    for(int it=0;it<node_count_;it++)
    {
        if(visited[it]==false)
        {
            DFS(*this,visited, it);
        }
    }
    std::cout << std::endl;
    delete []visited;
    return 1; // �ɹ�����
}

int Travel::BFSTravel()
{
    bool *visited = new bool[node_count_];
    for(int it=0;it<node_count_;it++)
    {
        visited[it] = false;
    }
    std::queue<int> Queue; // ��ʼ������
    for(int it=0;it<node_count_;it++)
    {
        if(visited[it]!=true)
        {
            std::cout << std::setw(3) << it; // ���ʽڵ�
            visited[it] = true; // ��Ƿ��ʹ��Ľڵ�
            Queue.push(it);
            while(!Queue.empty())
            {
                int temp = Queue.front(); // ���ض�ͷԪ��
                Queue.pop(); // ��ͷԪ�س���
                for(int v=FirstAdj(temp);v!=-1;v=NextAdj(temp,v))
                {
                    if(!visited[v])
                    {
                        std::cout << std::setw(3) << v; // ���ʽڵ�
                        visited[v] = true; // ��Ƿ��ʹ��Ľڵ�
                        Queue.push(v);
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    delete []visited;
    return 1; // �ɹ�����
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
    return -1; // û����һ�ڵ㷵��-1
}

int Travel::NextAdj(int i, int j)
{
    // j�����һ���ڵ�
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
    return -1; // û����һ�ڵ㷵��-1
}
