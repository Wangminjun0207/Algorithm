#include <stdio.h>

//�����������
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
