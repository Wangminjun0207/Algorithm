#include <iostream>

using namespace std;

class Recursive{
public:
    int fun(int m, int n)
    {
        if(n<0 || m<0) // 如果m<0 或者 n<0 的时候返回-1
            return -1;
        else if(m==0)
            return 0;
        else
        {
            return fun(m-1,2*n)+n; // 进行fun() 函数的递归调用
        }
    }
};
int main()
{
    Recursive g;
    int result = g.fun(5,2);
    cout << "result = " << result << endl;
    return 0;
}
