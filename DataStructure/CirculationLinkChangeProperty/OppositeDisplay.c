#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

//按照访问前驱节点输出链表中的数据
void oppositeDisplay(NodePtr s)
{
    NodePtr p;
    for(p = s;p->prior!=s;p=p->prior)
        printf("%5d",p->nNumber);
    printf("%5d",p->nNumber);
    printf("\n");
}
