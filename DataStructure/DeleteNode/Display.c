#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

//��������е�����
void display(NodePtr h)
{
    // hָ���һ����Ч����
    for(h=h->next;h!=NULL;h=h->next)
        printf("%5d",h->n);
    printf("\n");
}
