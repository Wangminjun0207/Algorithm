#include <iostream>

using namespace std;

class Recursive{
public:
    // �ݹ�����ֵ
    int recursiveFun(int n)
    {
        if(n<0) // ��� n<0 ��ʱ�򷵻�-1
            return -1;
        else if(n==0)
            return n+1;
        else
        {
            return recursiveFun(n/2)*n; // ����recursiveFun() �����ĵݹ����
        }
    }
    // �����ݹ�����ֵ
    int fun(int n)
    {
        if(n<0)
            return -1;// ��� n<0 ��ʱ�򷵻�-1
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
