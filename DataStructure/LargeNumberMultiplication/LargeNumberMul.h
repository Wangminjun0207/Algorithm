#ifndef LARGENUMBERMUL_H
#define LARGENUMBERMUL_H
#include <iostream>
#include <cstring>

class LargeNumberMul
{
    public:
        LargeNumberMul(); // 命令行无参数时初始化成员变量
        LargeNumberMul(char *large_number_a, char *large_number_b);// 命令行有参数时初始化成员变量
        int mul_operator();  // 进行大数相乘
        char get_ch(char *str, int ival); // 取字符串中的一位
        int print_result();  // 输出计算结果
        int set_ch(char *str, int ival, char ch);// 结果字符串中写入一位
        int print_num(char *str);  // 输出乘数
        int print(char *str);      // 输出结果字符串
        virtual ~LargeNumberMul();

    protected:

    private:
        char *large_number_a_ = new char[100];  // 第一个大数乘数
        char *large_number_b_ = new char[100];  // 第二个大数乘数
        char *mul_result_ = new char[200];      // 运算结果
};

#endif // LARGENUMBERMUL_H
