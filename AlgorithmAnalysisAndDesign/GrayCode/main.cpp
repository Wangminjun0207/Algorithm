/*
 * 用分治法设计Gray码
 */

#include <iostream>
#include <cmath>
using namespace std;

int arr[1024][1024]; //arr[i][j]表示第i个格雷码的第j位
//构造b位格雷码
//a为格雷码的个数
void gray(int a, int b)
{
    if(b==1) //如果格雷码宽度为1
    {
        arr[0][0] = 0;
        arr[1][0] = 1;
        return;
    }
    for(int i=0; i<a/2; i++) //格雷码最高位
    {
        arr[i][b-1] = 0;  //生成的格雷码前一半最高位填“0”
        arr[a-i-1][b-1] = 1;  //后一半最高位位填“1”
    }
    gray(a/2, b-1);  //生成b-1位格雷码，填写到目标码高半部分
    for(int i=a/2; i<a; i++) //格雷码低半部分
        for(int j=0; j<b-1; j++)
            arr[i][j] = arr[a-i-1][j];
}

int main()
{
    int b;
    cout << "输入格雷码位数：";
    cin >> b;
    int a = pow(2, b);// Gray码的个数
    gray(a, b);
    cout << "格雷码为：\n";
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
