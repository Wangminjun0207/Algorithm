void Merger(int r[], int r1[], int s, int m, int t)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while(i<=m && j<=t)
    {
        if(r[i]<=r[j])
            r[k++] = r[i++];  // ȡr[i]��r[j]�н�С�߷���r1[k]
        else
            r1[k++] = r[j++];
    }
    // ����һ��������û�����꣬�������β����
    while(i<=m)
        r1[k++] = r[i++];
    // ���ڶ���������û�����꣬�������β����
    while(j<=t)
        r1[k++] = r[j++];
    // ��������л��ԭ�����飬֮���ٴν�������
    int num=t-s+1;
    for(int i=0;i<num;i++,t--)
    {
        r[t] = r1[t];
    }
}
