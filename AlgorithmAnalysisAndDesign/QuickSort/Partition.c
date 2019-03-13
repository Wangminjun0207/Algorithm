 extern void swap( int *p, int i, int j);
//对数组进行分区操作
int partition(int *p, int left, int right)
{
    int pivot = left;
    int index = pivot + 1;
    for(int i = index; i<=right; i++)
    {
        if(p[i] < p[pivot])
        {
            if(p[i] != p[index])
            {
                swap(p, i, index);
                index++;
            }
            else
                index++;
        }
    }
    swap(p, pivot, index-1);
    return (index-1);
}
