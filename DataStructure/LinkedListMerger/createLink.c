#include "predefine.h"
extern LinkList createNode();

//����һ�������ȳ�������ֱ������0����
LinkList createLink()
{
    LinkList p, last, h = createNode();
    last = h;
    int e;
    while(1)
    {
        scanf("%d",&e);
        if(!e) break;//���������Ϊ0������ѭ��
        p = createNode();
        p->nNumber = e;
        last->next = p;
        last = p;
    }
    return h;
}
