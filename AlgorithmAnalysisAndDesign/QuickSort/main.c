#include <stdio.h>
#include <stdlib.h>

extern void display(int *p, int n);
extern int * creatArray(int n);
extern void quickSort(int *p, int left, int right);
extern void swap( int *p, int i, int j);
extern int partition(int *p, int left, int right);

int main()
{
    int *p, n;
    printf("�����������ģ��");
    scanf("%d", &n);
    p = creatArray(n);
    quickSort(p, 0, n-1);
    display(p, n);
    return 0;
}
