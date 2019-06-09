#include "Predefine.h"

int FindBTNode(BSubTNode *p,int k,int &i);
void Substitution(BSubTNode *p,int i);
void Remove(BSubTNode *p,int i);
void AdjustBTree(BSubTNode *p,int i);
void MoveLeft(BSubTNode *p,int i);
void Combine(BSubTNode *p,int i);
void MoveRight(BSubTNode *p,int i);

//在结点p中查找并删除关键字k
int BTNodeDelete(BSubTNode *p,int k)
{
    int i;
    int find_flag; //查找标志
    if(p==NULL)
    return 0;
    else
    {
        find_flag=FindBTNode(p,k,i);  //返回查找结果
        if(find_flag==1) //查找成功
        {
            if(p->A[i-1]!=NULL)
            { //删除的是非叶子结点
                Substitution(p,i);  //寻找相邻关键字 （右子树中最小的关键字）
                BTNodeDelete(p->A[i],p->K[i]);
            }
            else
                Remove(p,i); //从结点p中位置i处删除关键字
    }
    else
        find_flag=BTNodeDelete(p->A[i],k); //沿孩子结点递归查找并删除关键字k
    if(p->A[i]!=NULL)
       if(p->A[i]->n<Min)//删除后关键字个数小于Min
            AdjustBTree(p,i);  //调整B树
    return find_flag;
  }
}

//反映是否在结点p中是否查找到关键字k
int FindBTNode(BSubTNode *p,int k,int &i)
{
    //结点p中查找关键字k失败
    if(k<p->K[1])
    {
        i=0;
        return 0;
    }
    //在p结点中查找
    else{
        i=p->n;
        while(k<p->K[i]&&i>1)
            i--;
        //结点p中查找关键字k成功
        if(k==p->K[i])
            return 1;
    }
}

//寻找替代值（右子树中最小的关键字）
void Substitution(BSubTNode *p,int i)
{

    BSubTNode *q;
    for(q=p->A[i];q->A[0]!=NULL;q=q->A[0]);
    p->K[i]=q->K[1];   //复制关键字值
}

//从p结点中删除K[i]和他的孩子指针A[i]
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
  if(i==0)  //删除的是最左边的关键字
   {
   	  if(p->A[1]->n>Min) MoveLeft(p,1); //右结点可以借
   	  else  //右结点不够借
   	    Combine(p,1);
   }
   else if(i==p->n)  // 删除的是最右边的关键字
   {
   	 if(p->A[i-1]->n>Min)  MoveRight(p,i);//左结点可以借
   	 else  //左结点不够借
   	    Combine(p,i);
	}
   else if(p->A[i-1]->n>Min)  // 删除的关键字在中部且左结点够借
   {
      MoveRight(p,i);//左结点可以借
   }
   else if(p->A[i+1]->n>Min)  // 删除的关键字在中部且右结点够借
   {
      MoveLeft(p,i+1);//左结点可以借
   }
   else
      Combine(p,i); // 删除的关键字在中部且左右结点都不够借
}

// 双亲结点p中的最后一个关键字移入右结点q中,将左结点aq中的
// 最后一个关键字移入双亲结点p中
void MoveRight(BSubTNode *p,int i)
{
int j;
    BSubTNode *q=p->A[i];
    BSubTNode *aq=p->A[i-1];

    for(j=q->n;j>0;j--){                       //将右兄弟q中所有关键字向后移动一位
        q->K[j+1]=q->K[j];
        q->A[j+1]=q->A[j];
    }

    q->A[1]=q->A[0];                            //从双亲结点p移动关键字到右兄弟q中
    q->K[1]=p->K[i];
    q->n++;

    p->K[i]=aq->K[aq->n];                  //将左兄弟aq中最后一个关键字移动到双亲结点p中
    p->A[i]->A[0]=aq->A[aq->n];
    aq->n--;
}

// 将双亲结点p中的第一个关键字移入左结点aq中，将右
// 结点q中的第一个关键字移入双亲结点p中
void MoveLeft(BSubTNode *p,int i)
{
    int j;
    BSubTNode *aq=p->A[i-1];
    BSubTNode  *q=p->A[i];

    aq->n++;                                   //把双亲结点p中的关键字移动到左兄弟aq中
    aq->K[aq->n]=p->K[i];
    aq->A[aq->n]=p->A[i]->A[0];

    p->K[i]=q->K[1];                            //把右兄弟q中的关键字移动到双亲节点p中
    q->A[0]=q->A[1];
    q->n--;

    for(j=1;j<=q->n;j++){                     //将右兄弟q中所有关键字向前移动一位
        q->K[j]=q->K[j+1];
        q->A[j]=q->A[j+1];
    }
}


// 双亲结点p、右结点q合并入左结点aq，并调整双亲
// 结点p中的剩余关键字的位置
void Combine(BSubTNode *p,int i)
{

    int j;
    BSubTNode *q=p->A[i];
    BSubTNode *aq=p->A[i-1];

    aq->n++;                                  //将双亲结点的关键字p->key[i]插入到左结点aq
    aq->K[aq->n]=p->K[i];
    aq->A[aq->n]=q->A[0];

    for(j=1;j<=q->n;j++){                      //将右结点q中的所有关键字插入到左结点aq
        aq->n++;
        aq->K[aq->n]=q->K[j];
        aq->A[aq->n]=q->A[j];
    }

    for(j=i;j<p->n;j++){                       //将双亲结点p中的p->key[i]后的所有关键字向前移动一位
        p->K[j]=p->K[j+1];
        p->A[j]=p->A[j+1];
    }
    p->n--;                                    //修改双亲结点p的keynum值
    free(q);                                        //释放空右结点q的空间
}
