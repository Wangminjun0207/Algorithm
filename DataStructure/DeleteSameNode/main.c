/* 线性表中的元素以值递增有序排列，并以单链表做存储结构。
 * 试着写一种高效的算法，删除表中所有值相同多余的元素
 *(使得操作后所有的值均不同)，同时释放被删节点空间，并
 * 分析你的算法的时间复杂度。
 */

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern int delNode(NodePtr h);
extern void display(NodePtr h);

int main()
{
    NodePtr h, p, ptr = (NodePtr)malloc(sizeof(Node)*(30+1));
    //对链表进行初始化
    for(int i=0; i<31; i++)
    {
        if(i==0)
            h = p = ptr;
        else{
            ptr->n = i%9;
            p->next = ptr;
            p = ptr;
        }
        ptr++;
    }
    p->next = NULL;//表尾置空
    printf("delete node before:");
    display(h);
    delNode(h);
    printf("delete node later:");
    display(h);
    return 0;
}
