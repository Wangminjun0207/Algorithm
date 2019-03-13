//进行两个数字的交换
 void swap( int *p, int i, int j)
 {
     //在数值交换的时候使用此段代码，结果出现错误
     //但是在测试其他相等数据交换的时候结果正确
//     *(p + i) = *(p + i) + *(p + j);
//     *(p + j) = *(p + i) - *(p + j);
//     *(p + i) = *(p + i) - *(p + j);
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
 }
