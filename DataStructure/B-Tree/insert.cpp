#include "Predefine.h"
extern void Sort(BSubT p,int key);

//������
BSubT BSubTInsert(BSubT t,int key)
{
	BSubT p, pt, parent;
	int i, j, n, a[100], flag;
	p = t;
	parent = NULL;
	n = 0;
	while(p)
    {
		flag=0;
		// �����ڵ����������
		for(i=1;i<=p->n;i++)
            // �ҵ�����λ��
			if(key<p->K[i])
            {
				flag = 1; // ��־�����޸�Ϊ��
				parent = p;
				p = p->A[i-1];
				if(p) {a[n++]=i-1;}
				break;
			}
        // û���κ�һ���ؼ��ִ���key
		if(flag==0&&i==p->n+1)
		{
			parent=p;
			p=p->A[i-1];
			if(p) {a[n++]=i-1;}
		}
	}
	n--;
	Sort(parent,key);//���������
	while(parent->n==M)
    {//����
		if(parent->parent)
		{//�����ӽ��
			p=new BSubTNode;
			for(i=0;i<=M;i++)
				p->A[i]=NULL;
			p->parent=parent->parent;
			for(i=1,j=M/2+2;j<=M;i++,j++)
			{
				p->K[i]=parent->K[j];
				p->A[i]=parent->A[j];
				if(parent->A[j])
					parent->A[j]->parent=p;
				p->A[i-1]=parent->A[j-1];
				if(parent->A[j-1])
					parent->A[j-1]->parent=p;
			}
			parent->n=M/2;
			p->n=M-M/2-1;
			parent->parent->n++;
			for(i=p->parent->n;i>a[n]+1;i--)
			{
				p->parent->K[i]=p->parent->K[i-1];
				p->parent->A[i]=p->parent->A[i-1];
			}
			p->parent->K[a[n]+1]=parent->K[M/2+1];
			p->parent->A[a[n--]+1]=p;
			parent=parent->parent;
		}
		else
		{//���Ѹ����
			p=new BSubTNode;
			pt=new BSubTNode;
			pt->parent=NULL;
			p->parent=pt;
			parent->parent=pt;
			for(i=0;i<=M;i++)
				p->A[i]=pt->A[i]=NULL;
			for(i=1,j=M/2+2;j<=M;i++,j++)
			{
				p->K[i]=parent->K[j];
				p->A[i]=parent->A[j];
				if(parent->A[j])
					parent->A[j]->parent=p;
				p->A[i-1]=parent->A[j-1];
				if(parent->A[j-1])
					parent->A[i-1]->parent=p;
			}
			parent->n=M/2;
			p->n=M-M/2-1;
			pt->n=1;
			pt->K[1]=parent->K[M/2+1];
			pt->A[0]=parent;
			pt->A[1]=p;
			t=pt;
		}
	}
	return t;
}
