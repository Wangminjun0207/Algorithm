/* ����ĳ������ѭ������ĳ��ȴ���1���ұ��м���ͷ���Ҳ��ͷָ�룬��֪sΪ
 * ָ��������ĳ���ڵ��ָ�룬���ű�д�㷨��ɾ��ָ��s��ָ����ǰ�����
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
