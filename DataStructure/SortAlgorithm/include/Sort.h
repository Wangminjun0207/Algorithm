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

        int quickSort(std::vector<T> &arr);   // 采用快速排序对容器中的元素排序
        int shellSort(std::vector<T> &arr);   // 采用希尔排序对容器中的元素排序
        int insertSort(std::vector<T> &arr);  // 采用插入排序对容器中的元素排序
        int radixSort(std::vector<T> &arr);   // 采用基数排序对容器中的元素排序
        int bubbleSort(std::vector<T> &arr);  // 采用冒泡排序对容器中的元素排序
        int mergerSort(std::vector<T> &arr);  // 采用归并排序对容器中的元素排序
        int heapSort(std::vector<T> &arr);    // 采用堆排序对容器中的元素排序
        int bucketSort(std::vector<T> &arr);  // 采用桶排序对容器中的元素排序
        int bogoSort(std::vector<T> &arr);    // 采用Bogo排序对容器中的元素排序

    protected:

    private:
        int printArr(std::vector<T> &arr);    // 输出容器内的元素
};


template <class T>
int Sort<T>::printArr(std::vector<T> &arr)
{
    /** 这样的方法迭代器不能使用
    std::vector<T>::iterator it;
    for(it=arr.begin();it!=arr.end();it++)
    {
        std::cout << std::setw(4) << *it;
    }*/

    // 获取迭代器，输出元素，按照6字宽输出
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
    int len = arr.size(); // 数组长度
    // 根据步长分组，直到步长为1
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
    len = arr.size(); // 求得数组长度
    // 这个算法的复杂度为 O(n*n)
    for(ival=1;ival<len;ival++)
    {
        T temp = arr[ival];
        // 与jval位置前面的元素进行比较，如果大于就向后移动
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
        swapp = false; // 如果全部都是有序可以提前终止
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
        len -= 1; // 每冒泡一次，最后元素最大，无需排序
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
