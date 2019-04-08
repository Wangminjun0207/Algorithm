/*
 * �÷��η����Gray��
 */

#include <iostream>
#include <cmath>
using namespace std;

int arr[1024][1024]; //arr[i][j]��ʾ��i��������ĵ�jλ
//����bλ������
//aΪ������ĸ���
void gray(int a, int b)
{
    if(b==1) //�����������Ϊ1
    {
        arr[0][0] = 0;
        arr[1][0] = 1;
        return;
    }
    for(int i=0; i<a/2; i++) //���������λ
    {
        arr[i][b-1] = 0;  //���ɵĸ�����ǰһ�����λ�0��
        arr[a-i-1][b-1] = 1;  //��һ�����λλ�1��
    }
    gray(a/2, b-1);  //����b-1λ�����룬��д��Ŀ����߰벿��
    for(int i=a/2; i<a; i++) //������Ͱ벿��
        for(int j=0; j<b-1; j++)
            arr[i][j] = arr[a-i-1][j];
}

int main()
{
    int b;
    cout << "���������λ����";
    cin >> b;
    int a = pow(2, b);// Gray��ĸ���
    gray(a, b);
    cout << "������Ϊ��\n";
    for(int i=0; i<a; i++)
    {
        for(int j=0; j<b; j++)
            cout << arr[i][j];
        cout << endl;
    }
    return 0;
}
