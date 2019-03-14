/* 假设某个单向循环链表的长度大于1，且表中既无头结点也无头指针，已知s为
 * 指向链表中某个节点的指针，试着编写算法，删除指针s所指结点的前驱结点
 */
#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"
#define MAX_SIZE  20

extern int delNode(NodePtr s);
extern void display(NodePtr s);

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
        q->nNumber = i;
    }
    q->next = h;
    printf("h->nNumber = %d\n",h->nNumber);
    printf("delete node before:");
    display(h);
    //delNode(h);
    printf("return value: %d\n",delNode(h));
    printf("delete node after:");
    display(h);
    return 0;
}
