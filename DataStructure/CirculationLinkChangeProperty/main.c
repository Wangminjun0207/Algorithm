/* 已知一个单向循环链表，其每个结点中含有三个域：prior, data, 和next，其中
 * data为数据域，next为后继节点指针域，prior为前驱结点指针域，但是它的值为NULL，
 * 编写算法将此单向循环链表改为双向循环链表，即使prior成为前驱结点的指针域
 */
#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"
#define MAX_SIZE  20

extern int stePrior(NodePtr s);
extern void display(NodePtr s);
extern void oppositeDisplay(NodePtr s);

int main()
{
    NodePtr h, p, q;
    int i = 0;
    while(i<MAX_SIZE)
    {
        if(i==0)
        {
            h = p = q = (NodePtr)malloc(sizeof(Node));
            i++;
        }
        else{
            p = (NodePtr)malloc(sizeof(Node));
            q->next = p;
            q = p;
            i++;
        }
        p->prior = NULL; // 新结点的prior指针域赋值NULL
        p->nNumber = i;
    }
    q->next = h;
    printf("h->nNumber = %d\n",h->nNumber);
    printf("delete node before:");
    display(h);
    printf("return value: %d\n",stePrior(h));
    printf("delete node after:");
    oppositeDisplay(h);
    return 0;
}
