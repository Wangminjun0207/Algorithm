#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"

extern void initQueue(SqQueue* q,int n);
extern int full(SqQueue *q);
extern int empty(SqQueue *q);
extern int popQueue(SqQueue *q, char *ch);
extern int pushQueue(SqQueue *q, char *ch);

int main()
{
    int n;
    char c1,c;
    SqQueue q;
    printf("please input queue capacity:");
    scanf("%d",&n); // ��������������
    getchar();
    initQueue(&q,n);
    while(n)
    {
        printf("please choose operating(@ is pop all queue element,"
               " # is pop one queue element, others is push queue,until \\n):");
        scanf("%c",&c1);
        getchar();
        switch(c1)
        {
            case '#':if(popQueue(&q,&c)) // ���롮#����ʱ�����һ��
                    {printf("pop queue element :");printf("%c\n",c);}
                    else {printf("pop queue failed!\n");} break;
            case '@':if(!empty(&q))printf("all queue element :"); // ���롮@����ʱ��ȫ��Ԫ�س���
                    else {printf("pop queue failed!\n"); break;}
                    while(popQueue(&q,&c)){printf("%c\t",c);} printf("\n"); break;
            case '\n':n=0;printf("exit operation !\n");break; // ����س���������
            default: if(pushQueue(&q,&c1))           // ���������ַ������ַ����
                    {printf("push queue success!\n");}
                    else {printf("push queue failed!\n");} break;
        }
        if(c1!='@' && c1!='#' && full(&q)==1)    // ������������Ҳ��ǳ��Ӳ�����ʱ����ʾ�û�ѡ����Ӳ���
        {
            printf("the queue is full!\n");
            printf("you can choose pop one queue or pop all queue element!\n");
        }
    }
    return 0;
}
