#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

//��������е�����
void display(NodePtr s)
{
    NodePtr p;
    for(p = s;p->next!=s;p=p->next)
        printf("%5d",p->nNumber);
    printf("%5d",p->nNumber);
    printf("\n");
}
