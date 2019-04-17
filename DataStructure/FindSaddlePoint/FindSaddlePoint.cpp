int *find_sadPoint(int *arr, int m, int n, int *arr_result)
// 寻找数组arr中的马鞍点存储到att_result中，arr数组大小m×n,
{
    int min_val;
    int val[n];
    for(int k=0;k<n;k++)
        val[k] = -1000;        //记录各列的最大值
    int min_i, min_j;          // 记录每行最小值的下标
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
        // 如果min_j列的最大值没有找出，则查找，否则直接比较
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
        // 如果是马鞍点，则存放到arr_result数组中
        if(val[min_j]==min_val)
        {
            *arr_result++ = min_i;
            *arr_result++ = min_j;
            *arr_result++ = min_val;
        }
    }
    return arr_result;
}
