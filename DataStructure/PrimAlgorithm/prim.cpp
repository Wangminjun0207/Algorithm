#include "Predefine.h"
#define INF 32767 // 表示权值无穷大
void prim(Network G, int k)
{
    CD_TP *closedge = new CD_TP[G.n];
    // 初始化closedge
    for(int it=0;it<G.n;it++)
    {
        closedge[it].vex = k;
        closedge[it].lowcost = G.w[k][it];
    }

    /* 为什么代码这么复杂，因为赵老师没想到简单的代码
    closedge[k].lowcost = 0;
    std::cout << k; // 输出k号顶点
    for(int it=0;it<G.n-1;it++) // n-1趟循环
    {
        int i;
        for(i=0;i<G.n;i++)
        {
            if(closedge[i].lowcost>0)
            {
                break;
            }
        }
        for(int j=i+1;j<G.n;j++)
        {
            if(closedge[j].lowcost>0 && closedge[j].lowcost<closedge[i].lowcost)
            {
                i = j;
            }
        }
        std::cout << "," << i; // 输出i号顶点
        closedge[i].lowcost = 0;
        for(int j=0;j<G.n;j++)
        {
            if(closedge[j].lowcost>0 && closedge[j].lowcost>G.w[j][i])
            {
                closedge[j].lowcost = G.w[j][i];
                closedge[j].vex = i;
            }
        }
    }

    std::cout << "\n";
    int sum = 0; // 最小生成树边上权重之和
    // 以下输出n-1条边及边上的权重
    for(int it=0;it<G.n;it++)
    {
        if(it != k)
        {
            std::cout << "(" << it << "," << closedge[it].vex << ")";
            std::cout << "-" << G.w[it][closedge[it].vex] << std::endl;
            sum += G.w[it][closedge[it].vex];
        }
    }
    std::cout << "最小生成树边上权重之和：" << sum << std::endl;
    delete []closedge; */

    int sum = 0; // 最小生成树边的权值之和
    for(int it=0;it<G.n-1;it++)
    {
        int min_w = INF; // 最小权值
        int k; // 记录权值最小顶点
        for(int i=0;i<G.n;i++)
        {
            if(closedge[i].lowcost!=0 && closedge[i].lowcost<min_w)
            {
                min_w = closedge[i].lowcost;
                k = i; // k记录最近顶点编号
            }
        }
        std::cout << "(" << closedge[k].vex << "," << k << ")" << "-" << min_w << std::endl; // 输出权值最小边
        sum += closedge[k].lowcost;
        // 修改closedge数组内容
        for(int i=0;i<G.n;i++)
        {
            if(closedge[i].lowcost!=0 && G.w[k][i]<closedge[i].lowcost)
            {
                closedge[i].lowcost = G.w[k][i];
                closedge[i].vex = k;
            }
        }
    }
    std::cout << "最小生成树边的权值之和：" << sum << std::endl;
    delete []closedge;
}
