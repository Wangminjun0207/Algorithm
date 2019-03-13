#include <stdlib.h>
#include <stdio.h>

//创建一个数组，由用户输入数组规模
int * creatArray(int n)
{
    int *p = (int *)malloc(sizeof(int)*n);
    if(!p) exit(0);
    int i = 0;
    while(i < n)
    {
        scanf("%d", &p[i]);
        i++;
    }
    return p;
}
