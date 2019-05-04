#include <fstream>
#include "Predefine.h"

int crtGraph(OLGraph &graph)
{
    /** 从文件读取数据建立十字链表 */
    std::ifstream input("input.txt");
    if(!input)
    {
        std::cout << "can not open the file!" << std::endl;
        return -1;
    }
    input >> graph.n >> graph.e; // 读入顶点数和弧数

    for(int it=0;it<graph.n;it++)
    {
        graph.h[it].i = it; // 初始化顶点序号
        graph.h[it].firstout = graph.h[it].firstin = NULL;
    }

    for(int it=0;it<graph.e;it++)
    {
        OLANode *pr, *p, *q = new OLANode;
        input >> q->i >> q->j;
        q->hlink = q->vlink = NULL;
        // 水平链表按照弧头序号升序
        pr = NULL;
        p = graph.h[q->i].firstout;
        while(p&&p->j<q->j)
        {
            pr = p;
            p = p->hlink;
        }
        if(pr==NULL)
        {
            // 此时水平链表无节点
            q->hlink = p;
            graph.h[q->i].firstout = q;
        }
        else{
            // 此时水平链表已经存在节点
            // 将q节点插入到链表中
            pr->hlink = q;
            q->hlink = p;
        }

        // 垂直链表按照弧尾序号升序
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
    input.close(); // 关闭文件
    return 0;
}
