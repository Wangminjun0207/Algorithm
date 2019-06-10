void Merger(int r[], int r1[], int s, int m, int t)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while(i<=m && j<=t)
    {
        if(r[i]<=r[j])
            r[k++] = r[i++];  // 取r[i]和r[j]中较小者放入r1[k]
        else
            r1[k++] = r[j++];
    }
    // 当第一个子序列没处理完，则进行收尾处理
    while(i<=m)
        r1[k++] = r[i++];
    // 当第二个子序列没处理完，则进行收尾处理
    while(j<=t)
        r1[k++] = r[j++];
    // 有序的序列回填到原来数组，之后再次进行排序
    int num=t-s+1;
    for(int i=0;i<num;i++,t--)
    {
        r[t] = r1[t];
    }
}
