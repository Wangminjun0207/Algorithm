#include <stdlib.h>
#include <stdio.h>

//����һ�����飬���û����������ģ
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
