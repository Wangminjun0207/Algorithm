#include <stdlib.h>
#include "Predefine.h"

//删除符合条件的节点，并释放节点
void delNode(NodePtr h)
{
    NodePtr p, q, pt;
    while(h=h->next,h!=NULL) //让h指向头结点（无有效数据）
    {
        for(q=h,p=h->next;p!=NULL;)//q指向第一个有效节点,p指向第二个有效节点
        {
            if(h->n == p->n)
            {
                pt = p;//记录符合条件的节点
                q->next = p->next;//断开p节点之后进行连接
                free(pt);
                p = q->next;//p节点向前扫描
            }
            else{
                q = p;      //如果没找到符合条件的节点，p,q节点同时向前扫描
                p = p->next;
            }
        }
        q->next=NULL;
    }
    return 0;
}
