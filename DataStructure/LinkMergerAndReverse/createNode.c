#include "predefine.h"

//����һ������ͷ��㣬�����򲻴洢����
LinkList createNode()
{
    LinkList p = (LinkList)malloc(sizeof(LinkList));
    if(p)
    {
        p->next = NULL;
    }
    else{exit(0);}
    return p;
}
