// �Ľ��Ĳ�������
// ��ѭ�����ö��ֲ���
int InsertSort(int arr[], int len)
{
    int left, right; // ���ֲ�������ָ��
    int mid;
    for(int it=1;it<len;it++)
    {
        // �������������һ����
        if(arr[it-1]<=arr[it])
        {
            continue;
        }
        // ���������е�һ����С
        else if(arr[0]>arr[it])
        {
            int temp = arr[it];
            // �ƶ�����arr[it]�Ĺؼ���
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
            // �ҵ�����λ��
            if(arr[mid]>arr[it] && arr[mid-1]<=arr[it])
            {
                int temp = arr[it];
                // �ƶ�����arr[it]�Ĺؼ���
                for(int i=it;i>mid;i--)
                {
                    arr[i] = arr[i-1];
                }
                arr[mid] = temp;
                break;
            }
            // ����λ����mid֮��
            else if(arr[mid]<=arr[it])
            {
                left = mid + 1;
            }
            // ����λ����mid֮��
            else if(arr[mid-1]>arr[it])
            {
                right = mid - 1;
            }
        }
    }
    return 1;
}
