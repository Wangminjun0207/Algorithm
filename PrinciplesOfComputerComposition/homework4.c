/*  ��Ŀ����дһ��C���Գ���Σ����а����ṹ������ͶԽṹ���Ա�����ĸ�ֵȻ��ͨ
 *  �����е����ֶΣ�����鿴�������ڴ��еĵ�ַ�����̵�Ԫ�е�ʮ���������ݵȵȣ����鿴��
 * ��1��	���ֽ���ֵ���������ڴ��еĴ��˳��
 * ��2��	�ṹ���������ʼ��ַ�Լ�ÿ���ṹ���Ա�����Ĵ洢��ַ��
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct test1{
    char ch;
    int bval;
    short aval;
    float cval;
}Test1;
#pragma pack (1)  //���ṹ���еĳ�Ա��1�ֽڶ���
typedef struct test2{
    char ch;
    int bval;
    short aval;
    float cval;
}Test2;
#pragma pack ()   //ȡ���Զ����ֽڷ�ʽ
int main()
{
    Test1 ts1;
    ts1.ch = 'a';
    ts1.bval = 1024;
    ts1.aval = 128;
    ts1.cval = 3.14;
    printf("sizeof(test1)=%d\n",sizeof(ts1));

    Test2 ts2;
    ts2.ch = 'a';
    ts2.bval = 1024;
    ts2.aval = 128;
    ts2.cval = 3.14;
    printf("sizeof(test2)=%d\n",sizeof(ts2));
    return 0;
}
