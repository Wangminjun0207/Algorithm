#include <iostream>
using namespace std;
class OutputDigits{
public:
    int top; // ջ��ָ��
    int Stack[20]; // ջ���������20
    OutputDigits(){top=-1;}  // ��ʼ��ջ��ջ��ָ�����-1
    // �ݹ���������ĸ�λ����
    void recursivePrt(int n)
    {
        if(n>0)
        {
            recursivePrt(n/10);
            cout<<n%10<<" ";
        }
    }
    // �ǵݹ���������ĸ�λ����
    void prt(int n)
    {
        // �Ӹ�λ���ֿ�ʼ��ջ
        while(n){
            top++;
            Stack[top] = n%10;
            n = n/10;
        }
        // �����λ��ʼ��ջ
        for(;top>-1;top--)
            cout << Stack[top] << " ";
    }
};
int main()
{
    OutputDigits p;
    p.recursivePrt(12085);
    p.prt(12085);
    return 0;
}
