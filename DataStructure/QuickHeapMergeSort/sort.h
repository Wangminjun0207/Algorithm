#ifndef SORT_H_
#define SORT_H_
#include <fstream>
#include <vector>

void Merger(std::vector<int> &r, std::vector<int> &r1, int s, int m, int t)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while(i<=m && j<=t)
    {
        if(r[i]<=r[j])
            r1[k++] = r[i++];  // ȡr[i]��r[j]�н�С�߷���r1[k]
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

// �鲢����
void MergerSort(std::vector<int> &r, std::vector<int> &r1, int s, int t)
{
    int m;
    if(s==t)
    {
        r1[s] = r[s];
    }
    else
    {
        m = (s+t)/2;
        MergerSort(r,r1,s,m);   // �鲢ǰ���������
        MergerSort(r,r1,m+1,t); // �鲢����������
        Merger(r1,r,s,m,t);     // �ϲ������������������
    }
}

// ��������
void QuickSort(std::vector<int> &arr, int left, int right)
{
    if(left<right)
    {
        int pivot = left; // ��׼ֵָ��
        int index = pivot + 1;
        int temp;
        for(int it=index;it<=right;it++)
        {
            if(arr[it]<arr[pivot])
            {
                if(arr[it]!=arr[index])
                {
                    temp = arr[index];
                    arr[index] = arr[it];
                    arr[it] = temp;
                    index++;
                }
                else{
                    index++;
                }
            }
        }
        // ����׼ֵ�ŵ����ں�С�ڻ�׼ֵ֮��
        temp = arr[index-1];
        arr[index-1] = arr[pivot];
        arr[pivot] = temp;
        // ��С�ڻ�׼ֵ�Ĳ��ֽ��п�������
        QuickSort(arr, left, index-2);
        // �Դ��ڻ�׼ֵ�Ĳ��ֽ��п�������
        QuickSort(arr, index, right);
    }
}

// ���������Ϣ
void Print(std::vector<int> &arr, int n)
{
    std::ofstream file;
    file.open("output.txt",std::ios::app);
    for(int it=0;it<n;it++)
    {
        file << arr[it] << " ";
    }
    file << std::endl;
    file.close();
}

void HAdjust(std::vector<int> &arr, int i, int n)
{
    int temp = arr[i];
    while(i<=n/2-1) // Ҷ��ֹͣ����Ҷ�Ӽ���
    {
        int left = 2*i + 1;
        int right = left + 1;
        int j = left;
        if(right<n && arr[right]>arr[left])
        {
            j = right;
        }
        if(temp > arr[j])
        {
            break;
        }
        arr[i] = arr[j];
        i = j;
    }
    arr[i] = temp;
}

// ������
void HeapSort(std::vector<int> &arr, int n)
{
    for(int it=n/2-1;it>=0;it--)
    {
        HAdjust(arr, it, n);
    }
    for(int it=1;it<n;it++)
    {
        int temp = arr[0];
        arr[0] = arr[n-it];
        arr[n-it] = temp;
        HAdjust(arr, 0, n-it);
    }
}
#endif // SORT_H_
