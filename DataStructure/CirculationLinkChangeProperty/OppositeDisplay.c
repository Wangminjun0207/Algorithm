#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

//���շ���ǰ���ڵ���������е�����
void oppositeDisplay(NodePtr s)
{
    NodePtr p;
    for(p = s;p->prior!=s;p=p->prior)
        printf("%5d",p->nNumber);
    printf("%5d",p->nNumber);
    printf("\n");
}
