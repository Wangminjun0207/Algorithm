/* ��֪һ������ѭ��������ÿ������к���������prior, data, ��next������
 * dataΪ������nextΪ��̽ڵ�ָ����priorΪǰ�����ָ���򣬵�������ֵΪNULL��
 * ��д�㷨���˵���ѭ�������Ϊ˫��ѭ��������ʹprior��Ϊǰ������ָ����
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
        p->prior = NULL; // �½���priorָ����ֵNULL
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
