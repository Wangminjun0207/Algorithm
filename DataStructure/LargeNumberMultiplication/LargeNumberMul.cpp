#include "LargeNumberMul.h"

LargeNumberMul::LargeNumberMul(char *large_number_a, char *large_number_b)
{
    large_number_a_ = large_number_a;
    large_number_b_ = large_number_b;
    for(int i=0;i<200;i++)
        mul_result_[i] = '\0';
}

// ��ʼ�������������Լ��������
LargeNumberMul::LargeNumberMul()
{
    std::cin >> large_number_a_ >> large_number_b_;
    for(int i=0;i<200;i++)
        mul_result_[i] = '\0';
}

 // ȡ�ַ����е�һλ
char LargeNumberMul::get_ch(char *str, int ival)
{
	return str[ival];
}

// ����ַ�����д��һλ
int LargeNumberMul::set_ch(char *str, int ival, char ch)
{
    str[ival] = ch;
    return 0;
}
// �������
int LargeNumberMul::print_num(char *str)
{
    std::cout << str;
    return 0;
}

// ����������ַ���
int LargeNumberMul::print(char *str)
{
    for(int i=strlen(str)-1;i>=0;i--)
        std::cout << str[i];
    std::cout << std::endl;
    return 0;
}

// ������ļ�����
int LargeNumberMul::print_result()
{
    this->print_num(large_number_a_);
    std::cout << " * ";
    this->print_num(large_number_b_);
    std::cout << " = ";
    this->print(mul_result_);
    return 0;
}

// ���м���
int LargeNumberMul::mul_operator()
{
    int length_a = strlen(large_number_a_);
    int length_b = strlen(large_number_b_);
    // char remainder = '0'; // ��¼��λ����
    char adding = '0';    // ��¼��λ��
    int ch = 0;           // ��¼�浽����ַ������ֵ
    int temp = 0;         // ��¼������λ����˵Ľ��
    int counter = 0;      // ��¼�����ŵ�ַ�±�
    int flag = 0;         // ��־����
    int a, b;             // ������¼�������������Զ�ȡ��һλ��ֵ
    for(int ival=length_b-1;ival>=0;ival--)
    {
        counter = length_b - ival - 1;
        adding = '0';   // ��λ�ָ�Ϊ0
        b = this->get_ch(large_number_b_, ival)-'0'; // ȡ��������һλ
        for(int kval=length_a-1;kval>=0;kval--)
        {
            a = this->get_ch(large_number_a_, kval)-'0';  // ȡ����������һλ
            temp = a * b;
            // �����Ž����ĳ��λ��û�����ݣ���ֱ�Ӵ���
            if(this->get_ch(mul_result_, counter)=='\0')
                ch = (temp + (adding-'0') + flag)%10;
            else
                ch = (this->get_ch(mul_result_, counter) - '0') + (temp + (adding-'0') + flag)%10;
            // remainder = (temp + (adding -'0') + flag)%10 + '0';
            adding = (temp + (adding-'0') + flag)/10 + '0';
            flag = 0;
            if(ch/10)
            {
                // �ڼ�������ĺ͵�ʱ�������Ӧ��λ��Ӵ���10������Ҫ��¼����flag=1
                flag = 1;
            }
            // �������ĺʹ浽����ַ�����
            this->set_ch(mul_result_, counter, ch%10+'0');
            counter++;
        }
        //this->set_ch(mul_result_, counter, adding);
        // ���һ�εĽ�λ�浽����ַ�����
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
