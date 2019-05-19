#include "Predefine.h"
#define INF 32767 // ��ʾȨֵ�����
void prim(Network G, int k)
{
    CD_TP *closedge = new CD_TP[G.n];
    // ��ʼ��closedge
    for(int it=0;it<G.n;it++)
    {
        closedge[it].vex = k;
        closedge[it].lowcost = G.w[k][it];
    }

    /* Ϊʲô������ô���ӣ���Ϊ����ʦû�뵽�򵥵Ĵ���
    closedge[k].lowcost = 0;
    std::cout << k; // ���k�Ŷ���
    for(int it=0;it<G.n-1;it++) // n-1��ѭ��
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
        std::cout << "," << i; // ���i�Ŷ���
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
    int sum = 0; // ��С����������Ȩ��֮��
    // �������n-1���߼����ϵ�Ȩ��
    for(int it=0;it<G.n;it++)
    {
        if(it != k)
        {
            std::cout << "(" << it << "," << closedge[it].vex << ")";
            std::cout << "-" << G.w[it][closedge[it].vex] << std::endl;
            sum += G.w[it][closedge[it].vex];
        }
    }
    std::cout << "��С����������Ȩ��֮�ͣ�" << sum << std::endl;
    delete []closedge; */

    int sum = 0; // ��С�������ߵ�Ȩֵ֮��
    for(int it=0;it<G.n-1;it++)
    {
        int min_w = INF; // ��СȨֵ
        int k; // ��¼Ȩֵ��С����
        for(int i=0;i<G.n;i++)
        {
            if(closedge[i].lowcost!=0 && closedge[i].lowcost<min_w)
            {
                min_w = closedge[i].lowcost;
                k = i; // k��¼���������
            }
        }
        std::cout << "(" << closedge[k].vex << "," << k << ")" << "-" << min_w << std::endl; // ���Ȩֵ��С��
        sum += closedge[k].lowcost;
        // �޸�closedge��������
        for(int i=0;i<G.n;i++)
        {
            if(closedge[i].lowcost!=0 && G.w[k][i]<closedge[i].lowcost)
            {
                closedge[i].lowcost = G.w[k][i];
                closedge[i].vex = k;
            }
        }
    }
    std::cout << "��С�������ߵ�Ȩֵ֮�ͣ�" << sum << std::endl;
    delete []closedge;
}
