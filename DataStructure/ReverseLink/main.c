/* 试写一种算法，实现顺序表的就地逆置，即利用原表的存储空间将线性表逆置 */

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern void display(NodePtr h);
extern void reverseLink(NodePtr h);

int main()
{
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
    reverseLink(h);
    printf("delete node later:");
    display(h);
    return 0;
}
