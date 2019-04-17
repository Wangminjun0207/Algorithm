#include <iostream>
#include <cstdio>
using namespace std;
extern int *find_sadPoint(int *arr, int m, int n, int *arr_result);
int main()
{
    int arr[4][5] = {1,1,4,1,1,1,1,5,1,1,10,9,8,11,12,1,1,7,1,1};
    int arr_result[12];
    for(int i=0;i<12;i++)
        arr_result[i] = -1;
    find_sadPoint(&arr[0][0],4,5,arr_result);
    int k = 0;
	// 输出下马鞍点的下标和数值
    while(arr_result[k]!=-1)
    {
        printf("(%d,",arr_result[k++]);
        printf("%d) ",arr_result[k++]);
        printf("%d\n",arr_result[k++]);
    }
    return 0;
}
