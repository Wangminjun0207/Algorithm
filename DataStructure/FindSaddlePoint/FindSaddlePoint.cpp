int *find_sadPoint(int *arr, int m, int n, int *arr_result)
// Ѱ������arr�е�����洢��att_result�У�arr�����Сm��n,
{
    int min_val;
    int val[n];
    for(int k=0;k<n;k++)
        val[k] = -1000;        //��¼���е����ֵ
    int min_i, min_j;          // ��¼ÿ����Сֵ���±�
    for(int i=0;i<m;++i)
    {
        min_val = arr[i*n];
        min_i = i;
        min_j = 0;
        for(int j=1;j<n;++j)
        {
            if(arr[i*n+j]<min_val)
            {
                min_val = arr[i*n+j];
                min_i = i;
                min_j = j;
            }
        }
        // ���min_j�е����ֵû���ҳ�������ң�����ֱ�ӱȽ�
        if(val[min_j]==-1000)
        {
            for(int k=0;k<m;++k)
            {
                if(arr[k*n+min_j]>val[min_j])
                {
                    val[min_j] = arr[k*n+min_j];
                }
            }
        }
        // ��������㣬���ŵ�arr_result������
        if(val[min_j]==min_val)
        {
            *arr_result++ = min_i;
            *arr_result++ = min_j;
            *arr_result++ = min_val;
        }
    }
    return arr_result;
}
