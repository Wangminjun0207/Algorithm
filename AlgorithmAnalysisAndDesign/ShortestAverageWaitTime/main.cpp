#include<iostream>
#include<fstream>
using namespace std;
void CountingSort(int t[],int n,int r[],int e,int q[])
{
   	int i;              //计数排序
   	for( i=0;i<e;i++)
    	q[i]=0;        //把数组元素全部赋初值为0
	for( i=0;i<n;i++)
    	q[t[i]]+=1;    //判断累计相同等待时间的个数 q[t[i]]=q[t[i]]+1;
   	for( i=1;i<e;i++)
    	q[i]+=q[i-1];  //q[i]=q[i]+q[i-1]
	for( i=n;i>0;i--)  //将顾客等待时间从小到大排列
	{
    	r[q[t[i-1]]-1]=t[i-1];
    	q[t[i-1]]-=1;
    }
}

int main()
{
	int i=0, sum=0, n, max=0, u; //n为顾客个数
	float vt,p;
	ifstream in("input.txt");		
	if(in.fail())
	{
   		cout<<"input error!"<<endl;
   		exit(1);   //抛出一个异常窗口
	}
	ofstream out("output.txt");
	out.setf(ios::fixed);      //对输出设置精度
	out.precision(2);
	in>>n;             
	//new是给指针r分配n长度的空间，设置动态数组r,m，两个数组大小相同
	int *r=new int[n];
 	int *t=new int[n];
	for(i=0;i<n;i++)
   		in>>t[i];//从文本给等待时间t[i]数组赋值
	for(i=0;i<n;i++)
	{
   		if(max<t[i])
     	max=t[i];//找出最大的等待时间
	}
	u=max;             //u为所有顾客中最长的等待时间
	int *q=new int[u+1];  //动态数组用于计数排序,减少排序时间
	CountingSort(t,n,r,u+1,q);//调用CountingSort（）函数
	for(i=0;i<n;i++)
	{
   		sum+=r[i]*(n-i);
	}
	//文件尾:
	p=(float)sum;   //顾客等待服务时间的总和sum转换成浮点数赋给p
	vt=p/n;   // 计算平均等待时间
	std::cout << "用户个数：" << n << std::endl; 
	std::cout << "平均等待时间:" << vt; 
	out<<vt<<endl;
}
