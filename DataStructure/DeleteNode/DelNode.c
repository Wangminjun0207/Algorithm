#include <stdlib.h>
#include "Predefine.h"

//删除符合条件的节点，并释放节点
int delNode(NodePtr h, int mink, int maxk)
{
    if(mink >= maxk) // 如果mink>=maxk,则返回-1
        return -1;
    int nCounter = 0;
    NodePtr p, q, pt;
    for(q=h,p=h->next;p!=NULL;)//让q指向头结点（无有效数据），p指向第一个有效节点
    {
        if(p->n > mink && p->n < maxk)
        {
            pt = p;//记录符合条件的节点
            q->next = p->next;//断开p节点之后进行连接
            free(pt);
            p = q->next;//p节点向前扫描
            nCounter++;
        }
        else{
            q = p;      //如果没找到符合条件的节点，p,q节点同时向前扫描
            p = p->next;
        }
    }
    q->next=NULL;
    if(!nCounter)   //如果没有找到，则返回1
        return 1;
    return 0;
}
