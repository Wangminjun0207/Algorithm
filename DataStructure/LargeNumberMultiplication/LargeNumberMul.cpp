#include "LargeNumberMul.h"

LargeNumberMul::LargeNumberMul()
{
    while(1)
    {
        std::cout << "please input two large numbers :";
        std::cin >> large_number_a_ >> large_number_b_;
        if(large_number_a_[0]!='0' && large_number_b_[0]!='0')
            break;
        else
            std::cout << "you entered the wrong number!" << std::endl;
    }
    for(int i=0;i<200;i++)
        mul_result_[i] = '\0';
    this->mul_operator();
}

LargeNumberMul::LargeNumberMul(char *large_number_one, char *large_number_two)
{
    // 对两个乘数用形参进行初始化
    large_number_a_ = large_number_one;
    large_number_b_ = large_number_two;
    this->mul_operator();
}

void LargeNumberMul::print(char *str)
{
    for(int i=strlen(str)-1;i>=0;i--)
        std::cout << str[i];
    std::cout << std::endl;
}

void LargeNumberMul::mul_operator()
{
    int length_a = strlen(large_number_a_);
    int length_b = strlen(large_number_b_);
    char remainder = 0; // 记录本位余数
    char adding = '0';    // 记录进位数
    int ch = 0;         // 记录存到结果字符串里的值
    int temp = 0;         // 记录两个个位数相乘的结果
    int counter;          // 记录结果存放地址下标
    int flag = 0;         // 标志变量
    int a, b;
    for(int ival=length_b-1;ival>=0;ival--)
    {
        counter = length_b - ival - 1;
        adding = '0';
        for(int kval=length_a-1;kval>=0;kval--)
        {
            a = this->get_ch(large_number_b_, ival)-'0';
            b = this->get_ch(large_number_a_, kval)-'0';
            temp = a * b;
            if(this->get_ch(mul_result_, counter)=='\0')
                ch = (temp + (adding-'0') + flag)%10;
            else
                ch = (this->get_ch(mul_result_, counter) - '0') + (temp + (adding-'0') +flag)%10;
            remainder = (temp + (adding -'0') + flag)%10 + '0';
            adding = (temp + (adding-'0') + flag)/10 + '0';
            flag = 0;
            if(ch/10)
            {
                // 在计算乘数的和的时候，如果对应两位相加大于0，则需要记录，即flag=1
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
            this->set_ch(mul_result_, counter, adding);
        }
    }
    this->print_num(large_number_a_);
    std::cout << " × ";
    this->print_num(large_number_b_);
    std::cout << " = ";
    this->print(mul_result_);
}

LargeNumberMul::~LargeNumberMul()
{
    //dtor
}
