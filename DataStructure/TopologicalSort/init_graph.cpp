#include "Predefine.h"
#include <fstream>
#include <cstdlib>

int InitGraph(DAGGraph &graph)
{
    /** \brief ��ʼ��DAG
     *
     * \param  DAG
     * \param  DAGGraph ��ָ��
     * \return �޷���ֵ
     *
     */
    std::ifstream file;
    file.open("graph.txt",std::ios::in);
    if(!file.is_open())
    {
        std::cout << "Can not open graph.txt!" << std::endl;
        exit(-1); // �쳣�˳�
    }
    file >> graph.n;

    for(int it=0;it<graph.n;it++)
    {
        file >> graph.h[it].i; // ���붥���±�
        file >> graph.h[it].info; // ���붥�����
        file >> graph.h[it].k; // ���붥�����
        graph.h[it].firstarc = NULL; // �ڽӱ�ͷ���ָ�����ÿ�
        ArcNode *p;
        // ����ÿ��������ڽӱ�
        for(int j=0;j<graph.h[it].k;j++)
        {
            ArcNode *Node = new ArcNode();
            file >> Node->code;
            Node->next = NULL; // ÿ���ڵ��ָ�����ÿ�
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
    return 0; // ��ʼ��DAG�ɹ�
}
