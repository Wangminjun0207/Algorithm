/* ���Ա��е�Ԫ����ֵ�����������У����Ե��������洢�ṹ��
 * ����дһ�ָ�Ч���㷨��ɾ����������ֵ����mink��С��maxk
 * ��Ԫ��(������д���������Ԫ��)��ͬʱ�ͷű�ɾ�ڵ�ռ䣬��
 * ��������㷨��ʱ�临�Ӷ�(mink��maxk�Ǹ����������α���)��
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
