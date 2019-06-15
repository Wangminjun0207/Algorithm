#include "Predefine.h"
extern int InsertAVL(BSTree &T,ElemType e,bool &taller);
// ½¨Ê÷
int CreateBST(BSTree &T,int n)
{
       T=NULL;
       bool taller=0;
       int k,i;
       for(i=1;i<=n;i++)
       {
           std::cin>>k;
           InsertAVL(T,k,taller);
       }
       return 1;
}
