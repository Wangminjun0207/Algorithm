// 改进的插入排序
// 内循环改用二分查找
int InsertSort(int arr[], int len)
{
    int left, right; // 二分查找左右指针
    int mid;
    for(int it=1;it<len;it++)
    {
        // 比有序序列最后一个大
        if(arr[it-1]<=arr[it])
        {
            continue;
        }
        // 比有序序列第一个都小
        else if(arr[0]>arr[it])
        {
            int temp = arr[it];
            // 移动大于arr[it]的关键字
            for(int i=it;i>0;i--)
            {
                arr[i] = arr[i-1];
            }
            arr[0] = temp;
            continue;
        }
        left = 0;
        right = it-1;
        while(left<=right)
        {
            mid = (left+right)/2;
            // 找到插入位置
            if(arr[mid]>arr[it] && arr[mid-1]<=arr[it])
            {
                int temp = arr[it];
                // 移动大于arr[it]的关键字
                for(int i=it;i>mid;i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[mid] = temp;
                break;
            }
            // 插入位置在mid之后
            else if(arr[mid]<=arr[it])
            {
                left = mid + 1;
            }
            // 插入位置在mid之后
            else if(arr[mid-1]>arr[it])
            {
                right = mid - 1;
            }
        }
    }
    return 1;
}
