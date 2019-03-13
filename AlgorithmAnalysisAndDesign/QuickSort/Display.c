#include <stdio.h>

//输出数组数据
void display(int *p, int n)
{
    int i = 0;
    while(i < n)
    {
        printf("%4d",p[i]);
        i++;
    }
    printf("\n");
}
