#include "Predefine.h"

int FindBTNode(BSubTNode *p,int k,int &i);
void Substitution(BSubTNode *p,int i);
void Remove(BSubTNode *p,int i);
void AdjustBTree(BSubTNode *p,int i);
void MoveLeft(BSubTNode *p,int i);
void Combine(BSubTNode *p,int i);
void MoveRight(BSubTNode *p,int i);

//�ڽ��p�в��Ҳ�ɾ���ؼ���k
int BTNodeDelete(BSubTNode *p,int k)
{
    int i;
    int find_flag; //���ұ�־
    if(p==NULL)
    return 0;
    else
    {
        find_flag=FindBTNode(p,k,i);  //���ز��ҽ��
        if(find_flag==1) //���ҳɹ�
        {
            if(p->A[i-1]!=NULL)
            { //ɾ�����Ƿ�Ҷ�ӽ��
                Substitution(p,i);  //Ѱ�����ڹؼ��� ������������С�Ĺؼ��֣�
                BTNodeDelete(p->A[i],p->K[i]);
            }
            else
                Remove(p,i); //�ӽ��p��λ��i��ɾ���ؼ���
    }
    else
        find_flag=BTNodeDelete(p->A[i],k); //�غ��ӽ��ݹ���Ҳ�ɾ���ؼ���k
    if(p->A[i]!=NULL)
       if(p->A[i]->n<Min)//ɾ����ؼ��ָ���С��Min
            AdjustBTree(p,i);  //����B��
    return find_flag;
  }
}

//��ӳ�Ƿ��ڽ��p���Ƿ���ҵ��ؼ���k
int FindBTNode(BSubTNode *p,int k,int &i)
{
    //���p�в��ҹؼ���kʧ��
    if(k<p->K[1])
    {
        i=0;
        return 0;
    }
    //��p����в���
    else{
        i=p->n;
        while(k<p->K[i]&&i>1)
            i--;
        //���p�в��ҹؼ���k�ɹ�
        if(k==p->K[i])
            return 1;
    }
}

//Ѱ�����ֵ������������С�Ĺؼ��֣�
void Substitution(BSubTNode *p,int i)
{

    BSubTNode *q;
    for(q=p->A[i];q->A[0]!=NULL;q=q->A[0]);
    p->K[i]=q->K[1];   //���ƹؼ���ֵ
}

//��p�����ɾ��K[i]�����ĺ���ָ��A[i]
void Remove(BSubTNode *p,int i)
{
	int j;
	for(j=i+1;j<=p->n;j++)
	 {
	 	p->K[j-1]=p->K[j];
	 	p->A[j-1]=p->A[j];
	 }
	 p->n--;
}

void AdjustBTree(BSubTNode *p,int i)
{
  if(i==0)  //ɾ����������ߵĹؼ���
   {
   	  if(p->A[1]->n>Min) MoveLeft(p,1); //�ҽ����Խ�
   	  else  //�ҽ�㲻����
   	    Combine(p,1);
   }
   else if(i==p->n)  // ɾ���������ұߵĹؼ���
   {
   	 if(p->A[i-1]->n>Min)  MoveRight(p,i);//������Խ�
   	 else  //���㲻����
   	    Combine(p,i);
	}
   else if(p->A[i-1]->n>Min)  // ɾ���Ĺؼ������в������㹻��
   {
      MoveRight(p,i);//������Խ�
   }
   else if(p->A[i+1]->n>Min)  // ɾ���Ĺؼ������в����ҽ�㹻��
   {
      MoveLeft(p,i+1);//������Խ�
   }
   else
      Combine(p,i); // ɾ���Ĺؼ������в������ҽ�㶼������
}

// ˫�׽��p�е����һ���ؼ��������ҽ��q��,������aq�е�
// ���һ���ؼ�������˫�׽��p��
void MoveRight(BSubTNode *p,int i)
{
int j;
    BSubTNode *q=p->A[i];
    BSubTNode *aq=p->A[i-1];

    for(j=q->n;j>0;j--){                       //�����ֵ�q�����йؼ�������ƶ�һλ
        q->K[j+1]=q->K[j];
        q->A[j+1]=q->A[j];
    }

    q->A[1]=q->A[0];                            //��˫�׽��p�ƶ��ؼ��ֵ����ֵ�q��
    q->K[1]=p->K[i];
    q->n++;

    p->K[i]=aq->K[aq->n];                  //�����ֵ�aq�����һ���ؼ����ƶ���˫�׽��p��
    p->A[i]->A[0]=aq->A[aq->n];
    aq->n--;
}

// ��˫�׽��p�еĵ�һ���ؼ�����������aq�У�����
// ���q�еĵ�һ���ؼ�������˫�׽��p��
void MoveLeft(BSubTNode *p,int i)
{
    int j;
    BSubTNode *aq=p->A[i-1];
    BSubTNode  *q=p->A[i];

    aq->n++;                                   //��˫�׽��p�еĹؼ����ƶ������ֵ�aq��
    aq->K[aq->n]=p->K[i];
    aq->A[aq->n]=p->A[i]->A[0];

    p->K[i]=q->K[1];                            //�����ֵ�q�еĹؼ����ƶ���˫�׽ڵ�p��
    q->A[0]=q->A[1];
    q->n--;

    for(j=1;j<=q->n;j++){                     //�����ֵ�q�����йؼ�����ǰ�ƶ�һλ
        q->K[j]=q->K[j+1];
        q->A[j]=q->A[j+1];
    }
}


// ˫�׽��p���ҽ��q�ϲ�������aq��������˫��
// ���p�е�ʣ��ؼ��ֵ�λ��
void Combine(BSubTNode *p,int i)
{

    int j;
    BSubTNode *q=p->A[i];
    BSubTNode *aq=p->A[i-1];

    aq->n++;                                  //��˫�׽��Ĺؼ���p->key[i]���뵽����aq
    aq->K[aq->n]=p->K[i];
    aq->A[aq->n]=q->A[0];

    for(j=1;j<=q->n;j++){                      //���ҽ��q�е����йؼ��ֲ��뵽����aq
        aq->n++;
        aq->K[aq->n]=q->K[j];
        aq->A[aq->n]=q->A[j];
    }

    for(j=i;j<p->n;j++){                       //��˫�׽��p�е�p->key[i]������йؼ�����ǰ�ƶ�һλ
        p->K[j]=p->K[j+1];
        p->A[j]=p->A[j+1];
    }
    p->n--;                                    //�޸�˫�׽��p��keynumֵ
    free(q);                                        //�ͷſ��ҽ��q�Ŀռ�
}
