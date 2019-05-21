#include "Predefine.h"
#include <vector>
#include <fstream>

void test(DAGGraph graph, int k, int a[], int num);
int flag; // 标志变量，为假舍弃递归结果
int count = 0; // 标志变量，count>=graph.n时，证明graph是DAG
std::ofstream file;

bool TopoSort(DAGGraph &graph)
{
    /** \brief DAG拓扑排序
     *
     * \param DAG
     * \return if(DAG) return true; else return false;
     *
     */

    // ArcNode *p;
    std::vector<int> S;
    file.open("result.txt",std::ios::out);

    // DAG 入度为零的节点入栈
    for(int i=0;i<graph.n;i++)
    {
        if(graph.h[i].info==0)
        {
            S.push_back(i);
        }
    }

    /******************************************************
     * 以下代码只能输出一个DAG拓扑排序序列
     int count = 0;
    while(S.size())
    {
        // 输出该节点并且退栈
        i = S.back();
        std::cout << i << "  ";
        count++;
        S.pop_back();
        for(p=graph.h[i].firstarc;p;p=p->next)
        {
            // i节点关联的节点入度-1 为0之后入栈
            if((--graph.h[p->code].info)==0)
            {
                S.push_back(p->code);
            }
        }
    }
    file.close();
    // 如果一次都没有排序成功，返回false， 否则返回true
    if(count<graph.n)
    {
        return false; // 不是DAG
    }
    return true;
    ********************************************************/

    int a[graph.n]; // 存放拓扑排序结果
    int k; // 标记拓扑排序序列位置

    // 输出所有的拓扑排序序列
    while(S.size())
    {
        k = S.back();
        S.pop_back();
        test(graph,k,a,0);
    }
    std::cout << "所有拓扑排序的数目：" << count/graph.n << std::endl;
    file << "所有拓扑排序的数目：" << count/graph.n << std::endl;
    file.close();
    if(count>=graph.n)
    {
        return true;
    }
    return false;
}

void test(DAGGraph graph, int k, int a[], int num)
{
    /** \brief 输出DAG所有拓扑排序序列
     *
     * \param DAG
     * \param 第一个入度为零节点
     * \param 存放DAG拓扑排序序列的数组
     * \param 标记DAG拓扑排序序列的数组位置
     * \return 无返回值
     *
     */

    // result.push_back(temp);
    // result.back().push_back(k);
    std::vector<int> S;
    ArcNode *p;
    /* 第一个入度为零节点存到数组对应位置 */
    a[num] = k;
    num++;
    graph.h[k].info = -1;
    for(int j=0;j<graph.n;j++)
    {
        if(graph.h[j].info==0)
        {
            S.push_back(j);
        }
    }

    // i节点关联的节点入度-1 为0之后入栈
    for(p=graph.h[k].firstarc;p;p=p->next)
    {
        if((--graph.h[p->code].info)==0)
        {
            S.push_back(p->code);
        }
    }

    // 栈不空时继续递归进行拓扑排序
    while(S.size())
    {
        flag = 1;
        test(graph,S.back(),a,num);
        S.pop_back();
        for(int j=0;j<graph.n&&flag;j++)
        {
            std::cout << a[j] << " ";
            file << a[j] << " ";
            count++;
        }
        if(flag)
        {
            std::cout << std::endl;
            file << "\n";
        }
        flag = 0;// 递归重复结果舍弃
    }
}
