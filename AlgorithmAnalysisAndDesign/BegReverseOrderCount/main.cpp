/*
 * 用分治法求逆序对
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void merge(int in[], int out[], int l, int m, int r,int &num)
{
    int i = l;
    int k  = m + 1;
    while (l <= m && k <= r)
    {
        if (in[l] <= in[k]) {
        out[i++] = in[l++];
        }
        else
       {
            out[i++] = in[k++];
           /* 因为此时in[l...m]已经排序，如果in[l] 与 in[k] 逆序,
            则in[l+1], in[l+2]...in[m] 都与in[k]逆序, 共 m-l+1 对*/
           num += m - l + 1;
        }
    }
    while (l <= m) {
    out[i++] = in[l++];
    }
    while (k <= r) {
    out[i++] = in[k++];
    }

}

// 递归将序列划分为只有一个元素的子序列, 然后逐次对子序列进行合并
void m_sort(int in[], int out[], int l, int r,int &num)
{
    // 仅有一个元素, 已排序, 递归结束
    if (l >= r) {
    return;
    }
    // 计算 l 和 r 的中间值, 防止溢出
    int m = (l & r) + ((l ^ r) >> 1);
    m_sort(out, in, l, m,num);
    m_sort(out, in, m + 1, r,num);
    merge(in, out, l, m, r,num);
}

// 统一申请空间, 避免反复申请释放
int merge_sort(int a[], int n,int &num)
{
    int *b = (int *)malloc(n * sizeof(int));
    if (b) {
    memcpy(b, a, n * sizeof(int));
    m_sort(b, a, 0, n - 1,num);
    free(b);
    return 0;
    }
    return -1;
}
int main()
{
    int sum=0;
    int a[9]={4,1,2,8,5,7,12,6,1};
    merge_sort(a,9,sum);
    for(int i=0;i<9;i++)
    printf("%d   ",a[i]);
    printf("\n");
    printf("逆序对的数目为sum=%d",sum);
    printf("\n");
    return 0;
}
