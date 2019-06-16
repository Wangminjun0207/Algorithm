#include<iostream>
#include<fstream>
using namespace std;
void CountingSort(int t[],int n,int r[],int e,int q[])
{
   	int i;              //��������
   	for( i=0;i<e;i++)
    	q[i]=0;        //������Ԫ��ȫ������ֵΪ0
	for( i=0;i<n;i++)
    	q[t[i]]+=1;    //�ж��ۼ���ͬ�ȴ�ʱ��ĸ��� q[t[i]]=q[t[i]]+1;
   	for( i=1;i<e;i++)
    	q[i]+=q[i-1];  //q[i]=q[i]+q[i-1]
	for( i=n;i>0;i--)  //���˿͵ȴ�ʱ���С��������
	{
    	r[q[t[i-1]]-1]=t[i-1];
    	q[t[i-1]]-=1;
    }
}

int main()
{
	int i=0, sum=0, n, max=0, u; //nΪ�˿͸���
	float vt,p;
	ifstream in("input.txt");		
	if(in.fail())
	{
   		cout<<"input error!"<<endl;
   		exit(1);   //�׳�һ���쳣����
	}
	ofstream out("output.txt");
	out.setf(ios::fixed);      //��������þ���
	out.precision(2);
	in>>n;             
	//new�Ǹ�ָ��r����n���ȵĿռ䣬���ö�̬����r,m�����������С��ͬ
	int *r=new int[n];
 	int *t=new int[n];
	for(i=0;i<n;i++)
   		in>>t[i];//���ı����ȴ�ʱ��t[i]���鸳ֵ
	for(i=0;i<n;i++)
	{
   		if(max<t[i])
     	max=t[i];//�ҳ����ĵȴ�ʱ��
	}
	u=max;             //uΪ���й˿�����ĵȴ�ʱ��
	int *q=new int[u+1];  //��̬�������ڼ�������,��������ʱ��
	CountingSort(t,n,r,u+1,q);//����CountingSort��������
	for(i=0;i<n;i++)
	{
   		sum+=r[i]*(n-i);
	}
	//�ļ�β:
	p=(float)sum;   //�˿͵ȴ�����ʱ����ܺ�sumת���ɸ���������p
	vt=p/n;   // ����ƽ���ȴ�ʱ��
	std::cout << "�û�������" << n << std::endl; 
	std::cout << "ƽ���ȴ�ʱ��:" << vt; 
	out<<vt<<endl;
}
