// 递归实现插入排序
void InsertSort(int arr[], int low, int n)
{
    // 全部有序函数返回
    if(low==n) return;
    int it; // 迭代器
    for(it=0;it<low;it++)
    {
        if(arr[low]<arr[0])
        {
            it = -1;
            break;
        }
        if(arr[low]>=arr[it] && arr[low]<arr[it+1])
        {
            break;
        }
    }
    if(it<low)
    {
        int temp = arr[low];
        // 挪动元素
        for(int i=low;i>it+1;i--)
        {
            arr[i] = arr[i-1];
        }
        arr[it+1] = temp;
    }
    InsertSort(arr,low+1,n);
}
