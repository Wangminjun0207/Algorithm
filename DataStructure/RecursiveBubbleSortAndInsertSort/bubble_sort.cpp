// �ݹ�ʵ��ð������
void BubbleSort(int arr[], int n)
{
    // Ԫ�ظ������ڵ���1������������
    if(n<=1)
        return;
    int max_val = arr[0]; // ��¼���ֵ
    int k = 0; // ��¼���ֵ�±�
    for(int it=1;it<n;it++)
    {
        if(arr[it]>max_val)
        {
            // �������ֵ���±�
            max_val = arr[it];
            k = it;
        }
    }
    int temp = arr[n-1];
    arr[n-1] = max_val;
    arr[k] = temp;
    BubbleSort(arr,n-1);
}
