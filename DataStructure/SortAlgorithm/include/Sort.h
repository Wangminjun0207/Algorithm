#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <vector>
#include <iomanip>

template <class T>
class Sort
{
    public:
        Sort(){}
        virtual ~Sort(){}

        int quickSort(std::vector<T> &arr);   // ���ÿ�������������е�Ԫ������
        int shellSort(std::vector<T> &arr);   // ����ϣ������������е�Ԫ������
        int insertSort(std::vector<T> &arr);  // ���ò�������������е�Ԫ������
        int radixSort(std::vector<T> &arr);   // ���û�������������е�Ԫ������
        int bubbleSort(std::vector<T> &arr);  // ����ð������������е�Ԫ������
        int mergerSort(std::vector<T> &arr);  // ���ù鲢����������е�Ԫ������
        int heapSort(std::vector<T> &arr);    // ���ö�����������е�Ԫ������
        int bucketSort(std::vector<T> &arr);  // ����Ͱ����������е�Ԫ������
        int bogoSort(std::vector<T> &arr);    // ����Bogo����������е�Ԫ������

    protected:

    private:
        int printArr(std::vector<T> &arr);    // ��������ڵ�Ԫ��
};


template <class T>
int Sort<T>::printArr(std::vector<T> &arr)
{
    /** �����ķ�������������ʹ��
    std::vector<T>::iterator it;
    for(it=arr.begin();it!=arr.end();it++)
    {
        std::cout << std::setw(4) << *it;
    }*/

    // ��ȡ�����������Ԫ�أ�����6�ֿ����
    int len = arr.size();
    for(int it=0;it<len;it++)
    {
        std::cout << std::setw(6) << arr.at(it);
    }
    std::cout << std::endl;
    return 0;
}

template <class T>
int Sort<T>::quickSort(std::vector<T> &arr)
{
    //TODO
    std::cout << "quickSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::shellSort(std::vector<T> &arr)
{
    int len = arr.size(); // ���鳤��
    // ���ݲ������飬ֱ������Ϊ1
    for(int gap=len/2;gap>0;gap/=2)
    {
        for(int ival=gap;ival<len;ival++)
        {
            T temp = arr[ival];
            int jval;
            for(jval=ival;jval>=gap&&arr[jval-gap]>temp;jval-=gap)
            {
                arr[jval] = arr[jval-gap];
            }
            arr[jval] = temp;
        }
    }
    std::cout << "shellSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::insertSort(std::vector<T> &arr)
{
    int ival, jval, len;
    len = arr.size(); // ������鳤��
    // ����㷨�ĸ��Ӷ�Ϊ O(n*n)
    for(ival=1;ival<len;ival++)
    {
        T temp = arr[ival];
        // ��jvalλ��ǰ���Ԫ�ؽ��бȽϣ�������ھ�����ƶ�
        for(jval=ival;jval>0 && arr[jval-1]>temp;jval--)
        {
            arr[jval] = arr[jval-1];
        }
        arr[jval] = temp;
    }
    std::cout << "insertSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::radixSort(std::vector<T> &arr)
{
    // TODO
    std::cout << "radixSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::bubbleSort(std::vector<T> &arr)
{
    bool swapp = true;
    size_t len = arr.size();
    while(swapp)
    {
        swapp = false; // ���ȫ���������������ǰ��ֹ
        for(size_t it=0; it<len-1;it++)
        {
            if(arr[it]>arr[it+1])
            {
                arr[it] = arr[it] + arr[it+1];
                arr[it+1] = arr[it] - arr[it+1];
                arr[it] = arr[it] - arr[it+1];
                swapp = true;
            }
        }
        len -= 1; // ÿð��һ�Σ����Ԫ�������������
    }
    std::cout << "bubbleSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::mergerSort(std::vector<T> &arr)
{
    //TODO
    std::cout << "mergerSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::heapSort(std::vector<T> &arr)
{
    //TODO
    std::cout << "heapSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::bucketSort(std::vector<T> &arr)
{
    //TODO
    std::cout << "bucketSort:";
    printArr(arr);
    return 0;
}

template <class T>
int Sort<T>::bogoSort(std::vector<T> &arr)
{
    //TODO
    std::cout << "bogoSort:";
    printArr(arr);
    return 0;
}

#endif // SORT_H
