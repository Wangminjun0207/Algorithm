/* ���Ա��е�Ԫ����ֵ�����������У����Ե��������洢�ṹ��
 * ����дһ�ָ�Ч���㷨��ɾ����������ֵ��ͬ�����Ԫ��
 *(ʹ�ò��������е�ֵ����ͬ)��ͬʱ�ͷű�ɾ�ڵ�ռ䣬��
 * ��������㷨��ʱ�临�Ӷȡ�
 */

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern int delNode(NodePtr h);
extern void display(NodePtr h);

int main()
{
    NodePtr h, p, ptr = (NodePtr)malloc(sizeof(Node)*(30+1));
    //��������г�ʼ��
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
    p->next = NULL;//��β�ÿ�
    printf("delete node before:");
    display(h);
    delNode(h);
    printf("delete node later:");
    display(h);
    return 0;
}
