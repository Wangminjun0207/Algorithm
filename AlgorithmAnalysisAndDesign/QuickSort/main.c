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
    printf("请输入数组规模：");
    scanf("%d", &n);
    p = creatArray(n);
    quickSort(p, 0, n-1);
    partition(p, 0, n-1);
    display(p, n);
    //用此段代码测试swap函数在数值相等的时候进行交换，结果正确
//    int a[2] = {4,4};
//    int *p = a;
//    swap(p, 0, 1);
//    printf("%d %d ",p[0],p[1]);
    return 0;
}
