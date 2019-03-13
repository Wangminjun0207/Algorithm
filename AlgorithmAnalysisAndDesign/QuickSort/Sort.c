extern int partition(int *p, int left, int right);
//��������п�������
void quickSort(int *p, int left, int right)
{
    int nPartitionIndex;
    if(left < right)
    {
        nPartitionIndex = partition(p, left, right);
        quickSort(p, left, nPartitionIndex - 1);
        quickSort(p, nPartitionIndex + 1, right);
    }
}
