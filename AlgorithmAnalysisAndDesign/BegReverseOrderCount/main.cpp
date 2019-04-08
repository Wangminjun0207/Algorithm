/*
 * �÷��η��������
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
           /* ��Ϊ��ʱin[l...m]�Ѿ��������in[l] �� in[k] ����,
            ��in[l+1], in[l+2]...in[m] ����in[k]����, �� m-l+1 ��*/
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

// �ݹ齫���л���Ϊֻ��һ��Ԫ�ص�������, Ȼ����ζ������н��кϲ�
void m_sort(int in[], int out[], int l, int r,int &num)
{
    // ����һ��Ԫ��, ������, �ݹ����
    if (l >= r) {
    return;
    }
    // ���� l �� r ���м�ֵ, ��ֹ���
    int m = (l & r) + ((l ^ r) >> 1);
    m_sort(out, in, l, m,num);
    m_sort(out, in, m + 1, r,num);
    merge(in, out, l, m, r,num);
}

// ͳһ����ռ�, ���ⷴ�������ͷ�
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
    printf("����Ե���ĿΪsum=%d",sum);
    printf("\n");
    return 0;
}
