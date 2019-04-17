#ifndef LARGENUMBERMUL_H
#define LARGENUMBERMUL_H
#include <iostream>
#include <cstring>

class LargeNumberMul
{
    public:
        LargeNumberMul();
        LargeNumberMul(char *large_number_a, char *large_number_b);
        char get_ch(char *str, int ival){return str[ival];}
        void set_ch(char *str, int ival, char ch){str[ival] = ch;}
        void mul_operator();
        void print_num(char *str){std::cout << str;}
        void print(char *str);
        virtual ~LargeNumberMul();

    protected:

    private:
        char *large_number_a_ = new char[100]; // ��һ����������
        char *large_number_b_ = new char[100]; // �ڶ�����������
        char *mul_result_ = new char[200];     // ������
};

#endif // LARGENUMBERMUL_H
