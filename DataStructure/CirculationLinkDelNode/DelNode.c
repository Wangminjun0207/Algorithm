#include <stdlib.h>
#include "Predefine.h"

//删除所给节点的上一个节点
int delNode(NodePtr s)
{
    //如果给的节点s为空或者就只有s一个节点，则程序返回-1
    if(s==NULL || s->next==s)
        return -1;
    NodePtr p, q;
    p = s; //s赋值给p
    while(p->next != s)
    {
        q = p;
        p = p->next;
    }
    q->next = s;
    return 0;
}
