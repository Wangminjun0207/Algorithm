#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

//输出链表中的数据
void display(NodePtr h)
{
    // h指向第一个有效数据
    for(h=h->next;h!=NULL;h=h->next)
        printf("%5d",h->n);
    printf("\n");
}
