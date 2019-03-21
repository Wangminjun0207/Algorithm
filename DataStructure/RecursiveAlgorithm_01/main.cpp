#include <iostream>

using namespace std;

class Recursive{
public:
    // 递归求函数值
    int recursiveFun(int n)
    {
        if(n<0) // 如果 n<0 的时候返回-1
            return -1;
        else if(n==0)
            return n+1;
        else
        {
            return recursiveFun(n/2)*n; // 进行recursiveFun() 函数的递归调用
        }
    }
    // 消除递归求函数值
    int fun(int n)
    {
        if(n<0)
            return -1;// 如果 n<0 的时候返回-1
        int result = 1;
        while(n)
        {
            result = result*n;
            n = n/2;
        }
        return result;
    }
};
int main()
{
    Recursive g;
    int result = g.fun(80);
    cout << "result = " << result << endl;
    result = g.recursiveFun(80);
    cout << "result = " << result << endl;
    return 0;
}
