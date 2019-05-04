#include <fstream>
#include "Predefine.h"

int crtGraph(OLGraph &graph)
{
    /** ���ļ���ȡ���ݽ���ʮ������ */
    std::ifstream input("input.txt");
    if(!input)
    {
        std::cout << "can not open the file!" << std::endl;
        return -1;
    }
    input >> graph.n >> graph.e; // ���붥�����ͻ���

    for(int it=0;it<graph.n;it++)
    {
        graph.h[it].i = it; // ��ʼ���������
        graph.h[it].firstout = graph.h[it].firstin = NULL;
    }

    for(int it=0;it<graph.e;it++)
    {
        OLANode *pr, *p, *q = new OLANode;
        input >> q->i >> q->j;
        q->hlink = q->vlink = NULL;
        // ˮƽ�����ջ�ͷ�������
        pr = NULL;
        p = graph.h[q->i].firstout;
        while(p&&p->j<q->j)
        {
            pr = p;
            p = p->hlink;
        }
        if(pr==NULL)
        {
            // ��ʱˮƽ�����޽ڵ�
            q->hlink = p;
            graph.h[q->i].firstout = q;
        }
        else{
            // ��ʱˮƽ�����Ѿ����ڽڵ�
            // ��q�ڵ���뵽������
            pr->hlink = q;
            q->hlink = p;
        }

        // ��ֱ�����ջ�β�������
        pr = NULL;
        p = graph.h[q->j].firstin;
        while(p&&p->i<q->i)
        {
            pr = p;
            p = p->vlink;
        }
        if(pr==NULL)
        {
            q->vlink = p;
            graph.h[q->j].firstin = q;
        }
        else{
            pr->vlink = q;
            q->vlink = p;
        }
    }
    input.close(); // �ر��ļ�
    return 0;
}
