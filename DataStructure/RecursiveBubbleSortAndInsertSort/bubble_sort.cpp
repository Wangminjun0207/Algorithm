// 递归实现冒泡排序
void BubbleSort(int arr[], int n)
{
    // 元素个数少于等于1个，函数返回
    if(n<=1)
        return;
    int max_val = arr[0]; // 记录最大值
    int k = 0; // 记录最大值下标
    for(int it=1;it<n;it++)
    {
        if(arr[it]>max_val)
        {
            // 更新最大值和下标
            max_val = arr[it];
            k = it;
        }
    }
    int temp = arr[n-1];
    arr[n-1] = max_val;
    arr[k] = temp;
    BubbleSort(arr,n-1);
}
