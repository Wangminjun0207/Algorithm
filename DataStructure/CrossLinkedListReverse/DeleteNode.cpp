#include "Predefine.h"
extern int g_OLinkLine;

// 删除十字链表中的一个节点并返回
OLink delNode(OLink h)
{
    OLink pr1 = NULL;
    OLink pr2 = NULL;
    while(g_OLinkLine<h->i)
    {
        pr1 = &h->down[g_OLinkLine];
        pr2 = pr1->right;
        while(pr1!=pr2)
        {
            pr1->right = pr2->right;
            return pr2;
        }
        ++g_OLinkLine;
    }
    return NULL;
}
