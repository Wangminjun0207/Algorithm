#include "Predefine.h"
#include <vector>
#include <fstream>

void test(DAGGraph graph, int k, int a[], int num);
int flag; // ��־������Ϊ�������ݹ���
int count = 0; // ��־������count>=graph.nʱ��֤��graph��DAG
std::ofstream file;

bool TopoSort(DAGGraph &graph)
{
    /** \brief DAG��������
     *
     * \param DAG
     * \return if(DAG) return true; else return false;
     *
     */

    // ArcNode *p;
    std::vector<int> S;
    file.open("result.txt",std::ios::out);

    // DAG ���Ϊ��Ľڵ���ջ
    for(int i=0;i<graph.n;i++)
    {
        if(graph.h[i].info==0)
        {
            S.push_back(i);
        }
    }

    /******************************************************
     * ���´���ֻ�����һ��DAG������������
     int count = 0;
    while(S.size())
    {
        // ����ýڵ㲢����ջ
        i = S.back();
        std::cout << i << "  ";
        count++;
        S.pop_back();
        for(p=graph.h[i].firstarc;p;p=p->next)
        {
            // i�ڵ�����Ľڵ����-1 Ϊ0֮����ջ
            if((--graph.h[p->code].info)==0)
            {
                S.push_back(p->code);
            }
        }
    }
    file.close();
    // ���һ�ζ�û������ɹ�������false�� ���򷵻�true
    if(count<graph.n)
    {
        return false; // ����DAG
    }
    return true;
    ********************************************************/

    int a[graph.n]; // �������������
    int k; // ���������������λ��

    // ������е�������������
    while(S.size())
    {
        k = S.back();
        S.pop_back();
        test(graph,k,a,0);
    }
    std::cout << "���������������Ŀ��" << count/graph.n << std::endl;
    file << "���������������Ŀ��" << count/graph.n << std::endl;
    file.close();
    if(count>=graph.n)
    {
        return true;
    }
    return false;
}

void test(DAGGraph graph, int k, int a[], int num)
{
    /** \brief ���DAG����������������
     *
     * \param DAG
     * \param ��һ�����Ϊ��ڵ�
     * \param ���DAG�����������е�����
     * \param ���DAG�����������е�����λ��
     * \return �޷���ֵ
     *
     */

    // result.push_back(temp);
    // result.back().push_back(k);
    std::vector<int> S;
    ArcNode *p;
    /* ��һ�����Ϊ��ڵ�浽�����Ӧλ�� */
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

    // i�ڵ�����Ľڵ����-1 Ϊ0֮����ջ
    for(p=graph.h[k].firstarc;p;p=p->next)
    {
        if((--graph.h[p->code].info)==0)
        {
            S.push_back(p->code);
        }
    }

    // ջ����ʱ�����ݹ������������
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
        flag = 0;// �ݹ��ظ��������
    }
}
