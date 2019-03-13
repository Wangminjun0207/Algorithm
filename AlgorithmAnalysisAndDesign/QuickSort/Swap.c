//进行两个数字的交换
 void swap( int *p, int i, int j)
 {
//     问题：在相等数值交换的时候使用注释代码，结果出现错误
//     但是在测试其他相等数据交换的时候结果正确
//
//     原因：在地址操作的时候使用注释代码时候如果传入的参数i, j相等
//     实际操作的是一个变量，不能使用注释代码
//
//     优化：通过对代码的修改(值相等的时候不交换)，也可以使用注释代码
//     *(p + i) = *(p + i) + *(p + j);
//     *(p + j) = *(p + i) - *(p + j);
//     *(p + i) = *(p + i) - *(p + j);
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
 }

