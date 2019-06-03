#include <stdio.h>
#include <stdlib.h>

extern int preprocess(char *buf, int *len, char *cur);
extern int analysis(char *buf, int *len);
int main()
{
    char buf[20000];  // 存放源代码
    char cur[20000];  // 存放预处理之后的代码
    int len = 0;     // 源代码长度
    if(!preprocess(buf,&len,cur))
    {
        analysis(cur,&len);
    }
    printf("total : %d\n",len);
    return 0;
}
