#include <stdio.h>
#include <stdlib.h>

extern int preprocess(char *buf, int *len, char *cur);
extern int analysis(char *buf, int *len);
int main()
{
    char buf[20000];  // ���Դ����
    char cur[20000];  // ���Ԥ����֮��Ĵ���
    int len = 0;     // Դ���볤��
    if(!preprocess(buf,&len,cur))
    {
        analysis(cur,&len);
    }
    printf("total : %d\n",len);
    return 0;
}
