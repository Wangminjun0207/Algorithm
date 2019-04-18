#ifndef LARGENUMBERMUL_H
#define LARGENUMBERMUL_H
#include <iostream>
#include <cstring>

class LargeNumberMul
{
    public:
        LargeNumberMul(); // �������޲���ʱ��ʼ����Ա����
        LargeNumberMul(char *large_number_a, char *large_number_b);// �������в���ʱ��ʼ����Ա����
        int mul_operator();  // ���д������
        char get_ch(char *str, int ival); // ȡ�ַ����е�һλ
        int print_result();  // ���������
        int set_ch(char *str, int ival, char ch);// ����ַ�����д��һλ
        int print_num(char *str);  // �������
        int print(char *str);      // �������ַ���
        virtual ~LargeNumberMul();

    protected:

    private:
        char *large_number_a_ = new char[100];  // ��һ����������
        char *large_number_b_ = new char[100];  // �ڶ�����������
        char *mul_result_ = new char[200];      // ������
};

#endif // LARGENUMBERMUL_H
