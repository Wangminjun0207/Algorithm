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
    scanf("%d",&n); // 输入队列最大容量
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
            case '#':if(popQueue(&q,&c)) // 输入‘#’的时候出队一次
                    {printf("pop queue element :");printf("%c\n",c);}
                    else {printf("pop queue failed!\n");} break;
            case '@':if(!empty(&q))printf("all queue element :"); // 输入‘@’的时候全部元素出队
                    else {printf("pop queue failed!\n"); break;}
                    while(popQueue(&q,&c)){printf("%c\t",c);} printf("\n"); break;
            case '\n':n=0;printf("exit operation !\n");break; // 输入回车操作结束
            default: if(pushQueue(&q,&c1))           // 输入其他字符将该字符入队
                    {printf("push queue success!\n");}
                    else {printf("push queue failed!\n");} break;
        }
        if(c1!='@' && c1!='#' && full(&q)==1)    // 如果队列已满且不是出队操作的时候提示用户选择出队操作
        {
            printf("the queue is full!\n");
            printf("you can choose pop one queue or pop all queue element!\n");
        }
    }
    return 0;
}
