#include "LargeNumberMul.h"

int main(int argc, char **argv)
{
    LargeNumberMul *large_num_mul;
    if(argc!=1)
    {
        // 命令行传入两个参数相乘
        large_num_mul = new LargeNumberMul(argv[1],argv[2]);
    }
    else
    {
        // 用户输入两个大数相乘
        large_num_mul = new LargeNumberMul();
    }
    large_num_mul->mul_operator();
    large_num_mul->print_result();
    delete large_num_mul;
    return 0;
}
