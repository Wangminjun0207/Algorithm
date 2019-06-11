#include <stdio.h>
#include <stdlib.h>
extern void MergerSort(int r[], int r1[], int s, int t);
int main()
{
    int a[10] = {87,-99,50,1,32,-69,-100,5,56,88};
    int b[10];
    MergerSort(a,b,0,9);
    int i = 0;
    while(i<10)
    {
        printf("%4d",a[i]);
        i++;
    }
    return 0;
}

