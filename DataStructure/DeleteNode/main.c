/* 线性表中的元素以值递增有序排列，并以单链表做存储结构。
 * 试着写一种高效的算法，删除表中所有值大于mink和小于maxk
 * 的元素(如果表中存在这样的元素)，同时释放被删节点空间，并
 * 分析你的算法的时间复杂度(mink和maxk是给定的两个参变量)。
 */

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern int delNode(NodePtr h, int mink, int maxk);
extern void display(NodePtr h);

int main()
{
    int mink, maxk;
    NodePtr h, p, ptr = (NodePtr)malloc(sizeof(Node)*(20+1));
    //对链表进行初始化
    for(int i=0; i<21; i++)
    {
        if(i==0)
            h = p = ptr;
        else{
            ptr->n = i*i;
            p->next = ptr;
            p = ptr;
        }
        ptr++;
    }
    p->next = NULL;//表尾置空
    printf("delete node before:");
    display(h);
    printf("please input \'mink\' and \'maxk\':");
    scanf("%d%d",&mink, &maxk);
    switch(delNode(h, mink, maxk))
    {
        case -1:printf("mink >= maxk!\n");break;
        case 0:printf("operating success!\n");break;
        case 1:printf("operating failed!\n");break;
        default:break;
    }
    printf("delete node later:");
    display(h);
    return 0;
}
