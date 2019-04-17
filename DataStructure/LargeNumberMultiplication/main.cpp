#include "LargeNumberMul.h"

int main(int argc, char **argv)
{
    if(argc!=1)
        { LargeNumberMul large_num_mul(argv[1],argv[2]);}
    else
        { LargeNumberMul large_num_mul;}
    return 0;
}
