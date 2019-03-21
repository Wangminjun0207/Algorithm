#include <iostream>
using namespace std;
class OutputDigits{
public:
    int top; // 栈顶指针
    int Stack[20]; // 栈的最大容量20
    OutputDigits(){top=-1;}  // 初始化栈，栈顶指针等于-1
    // 递归输出整数的各位数字
    void recursivePrt(int n)
    {
        if(n>0)
        {
            recursivePrt(n/10);
            cout<<n%10<<" ";
        }
    }
    // 非递归输出整数的各位数字
    void prt(int n)
    {
        // 从个位数字开始入栈
        while(n){
            top++;
            Stack[top] = n%10;
            n = n/10;
        }
        // 从最高位开始出栈
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
