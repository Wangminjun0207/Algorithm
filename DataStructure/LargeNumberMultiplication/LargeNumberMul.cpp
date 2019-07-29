#include "LargeNumberMul.h"

LargeNumberMul::LargeNumberMul(char *large_number_a, char *large_number_b)
{
    large_number_a_ = large_number_a;
    large_number_b_ = large_number_b;
    for(int i=0;i<200;i++)
        mul_result_[i] = '\0';
}

// 初始化两个乘数，以及结果数组
LargeNumberMul::LargeNumberMul()
{
    std::cin >> large_number_a_ >> large_number_b_;
    for(int i=0;i<200;i++)
        mul_result_[i] = '\0';
}

 // 取字符串中的一位
char LargeNumberMul::get_ch(char *str, int ival)
{
	return str[ival];
}

// 结果字符串中写入一位
int LargeNumberMul::set_ch(char *str, int ival, char ch)
{
    str[ival] = ch;
    return 0;
}
// 输出乘数
int LargeNumberMul::print_num(char *str)
{
    std::cout << str;
    return 0;
}

// 输出计算结果字符串
int LargeNumberMul::print(char *str)
{
    for(int i=strlen(str)-1;i>=0;i--)
        std::cout << str[i];
    std::cout << std::endl;
    return 0;
}

// 输出最后的计算结果
int LargeNumberMul::print_result()
{
    this->print_num(large_number_a_);
    std::cout << " * ";
    this->print_num(large_number_b_);
    std::cout << " = ";
    this->print(mul_result_);
    return 0;
}

// 进行计算
int LargeNumberMul::mul_operator()
{
    int length_a = strlen(large_number_a_);
    int length_b = strlen(large_number_b_);
    // char remainder = '0'; // 记录本位余数
    char adding = '0';    // 记录进位数
    int ch = 0;           // 记录存到结果字符串里的值
    int temp = 0;         // 记录两个个位数相乘的结果
    int counter = 0;      // 记录结果存放地址下标
    int flag = 0;         // 标志变量
    int a, b;             // 用来记录从两个大数各自读取的一位数值
    for(int ival=length_b-1;ival>=0;ival--)
    {
        counter = length_b - ival - 1;
        adding = '0';   // 进位恢复为0
        b = this->get_ch(large_number_b_, ival)-'0'; // 取出乘数的一位
        for(int kval=length_a-1;kval>=0;kval--)
        {
            a = this->get_ch(large_number_a_, kval)-'0';  // 取出被乘数的一位
            temp = a * b;
            // 如果存放结果的某个位置没有数据，则直接存入
            if(this->get_ch(mul_result_, counter)=='\0')
                ch = (temp + (adding-'0') + flag)%10;
            else
                ch = (this->get_ch(mul_result_, counter) - '0') + (temp + (adding-'0') + flag)%10;
            // remainder = (temp + (adding -'0') + flag)%10 + '0';
            adding = (temp + (adding-'0') + flag)/10 + '0';
            flag = 0;
            if(ch/10)
            {
                // 在计算乘数的和的时候，如果对应两位相加大于10，则需要记录，即flag=1
                flag = 1;
            }
            // 将乘数的和存到结果字符串中
            this->set_ch(mul_result_, counter, ch%10+'0');
            counter++;
        }
        //this->set_ch(mul_result_, counter, adding);
        // 最后一次的进位存到结果字符串中
        if(adding-'0')
        {
            if((adding-'0'+flag)/10)
            {
                this->set_ch(mul_result_, counter++, '0');
                this->set_ch(mul_result_, counter, '1');
            }
            else{
                this->set_ch(mul_result_, counter, adding+flag);
            }
        }
    }
    return 0;
}

LargeNumberMul::~LargeNumberMul()
{
    //dtor
}
