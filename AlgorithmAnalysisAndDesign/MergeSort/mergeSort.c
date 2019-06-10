extern int Merger(int r[], int r1[], int s, int m, int t);
void MergerSort(int r[], int r1[], int s, int t)
{
    int m;
    if(s==t)
    {
        r1[s] = r[s];
    }
    else
    {
        m = (s+t)/2;
        MergerSort(r,r1,s,m);   // 归并前半个子序列
        MergerSort(r,r1,m+1,t); // 归并后半个子序列
        Merger(r1,r,s,m,t);     // 合并两个已排序的子序列
    }
}
