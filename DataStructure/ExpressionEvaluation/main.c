//�Ӽ���������׺���ʽ���������������������ջ�����㲢������ʽ����ֵ�����
//����Ҫ��ʵ�� +, -, *, /�ĸ���Ԫ������Լ�������
//          ��������ΧΪ0��9��
//���Ҫ��ʵ��+, -����һԪ����������������ţ���
//          ��������Ϊ��������ֵ������ɲ����Ǽ����������
//������������������ֻ���������̣�������������ÿλͬѧ��ѡ��ʵ�ֻ���Ҫ��������Ҫ�󣻳���ɲ�������ʽ�﷨����

#include <stdio.h>
#include <stdlib.h>
#include "Predefine.h"
#define MAX_SIZE 20

int main()
{
    int top_optr = -1;   // �����ջ��ָ��
    int top_opnd = -1;   // ������ջ��ָ��
    char optr[MAX_SIZE]; // ������ջ���������MAX_SIZE
    int opnd[MAX_SIZE];  // ������ջ���������MAX_SIZE
    exTransform(optr,opnd,&top_optr,&top_opnd);
	printf("%d\n",get_top_number(opnd,&top_opnd));
    return 0;
}

