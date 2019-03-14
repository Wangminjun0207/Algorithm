/* 题目：假设两个按照元素值递增有序排列的线性表A和B，均以单链表作存储结构，
 *       请编写算法将A表和B表归并成一个按照元素递减有序排列的线性表C，并要
 *       求利用原有的节点空间构造C表
 */
#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern LinkList createLink();
extern LinkList createNode();
extern void displayLink(LinkList h);
extern LinkList mergerLink(LinkList ha, LinkList hb, LinkList hc);
int main()
{
    LinkList h1, h2, h3;
    printf("please input the first link until input zero, must from small to large:");
    h1 = createLink();
    printf("the first link is:");
    displayLink(h1);
    printf("please input the second link until input zero, must from small to large:");
    h2 = createLink();
    printf("the second link is:");
    displayLink(h2);
    h3 = createNode();
    printf("merger link by the first and second link:");
    displayLink(mergerLink(h1,h2,h3));
    return 0;
}

