/* ��дһ���㷨��ʵ��˳���ľ͵����ã�������ԭ��Ĵ洢�ռ佫���Ա����� */

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern void display(NodePtr h);
extern void reverseLink(NodePtr h);

int main()
{
    NodePtr h, p, ptr = (NodePtr)malloc(sizeof(Node)*(20+1));
    //��������г�ʼ��
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
    p->next = NULL;//��β�ÿ�
    printf("delete node before:");
    display(h);
    reverseLink(h);
    printf("delete node later:");
    display(h);
    return 0;
}
