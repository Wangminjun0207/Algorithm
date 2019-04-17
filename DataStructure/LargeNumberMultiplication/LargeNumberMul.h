#ifndef LARGENUMBERMUL_H
#define LARGENUMBERMUL_H
#include <iostream>
#include <cstring>

class LargeNumberMul
{
    public:
        LargeNumberMul();
        LargeNumberMul(char *large_number_a, char *large_number_b);
        int mul_operator();  // ���д������
        char get_ch(char *str, int ival){return str[ival];}
        int print_result();  // ���������
        int set_ch(char *str, int ival, char ch)
        {
            str[ival] = ch;
            return 0;
        }
        int print_num(char *str)
        {
            std::cout << str;
            return 0;
        }
        int print(char *str);  // �������ַ���
        virtual ~LargeNumberMul();

    protected:

    private:
        char *large_number_a_ = new char[100];  // ��һ����������
        char *large_number_b_ = new char[100];  // �ڶ�����������
        char *mul_result_ = new char[200];      // ������
};

#endif // LARGENUMBERMUL_H
