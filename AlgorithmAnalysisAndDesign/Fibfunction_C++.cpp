#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char **argv)
{
	int i, sum = 0, temp1, temp2;
	vector<int>fib;
	for(i=1; i<=40; i++)
	{
		if(i==1 || i==2)
		{
			fib.push_back(1);
		}
		else
		{
			temp1 = fib.at(i-2);//或者test[i]都可以访问 
			temp2 = fib.at(i-3);
			fib.push_back(temp1 + temp2);
		}
		sum += fib.at(i-1); 
	}
	cout << "第40项的值为：" << fib.at(39) << endl;
	cout << "前40项的值为：" << sum << endl;
	return 0;
} 
