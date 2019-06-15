#include "Predefine.h"

// 链式基数排序
int CardinalSort(Link *h)
{

    for(int it=0;it<8;it++)
    {
        NodePtr ptr = h->ptr->next; // 迭代指针
        while(ptr)
        {
            int n = ptr->key;
            // 取下此节点
            NodePtr pt = ptr;
            h->ptr->next = ptr->next;

            // 对元素分组
            int die = 1;
            for(int i=0;i<it;i++)
            {
                die *= 0xF + 1;
            }
            n = n / die;
            n %= 0xF + 1;
            NodePtr p = h->Sort[n];
            while(p->next)
            {
                p = p->next;
            }
            p->next = pt;
            pt->next = NULL;
            ptr = h->ptr->next;
        }
        NodePtr h1 = h->ptr;
        // 将分组的数据再次写会原存储空间
        for(int i=0;i<16;i++)
        {
            while(h->Sort[i]->next)
            {
                NodePtr pt = h->Sort[i]->next;
                h->Sort[i]->next = pt->next;
                pt->next = NULL;
                h1->next = pt;
                h1 = pt;
            }
        }
    }
    return 1;
}
