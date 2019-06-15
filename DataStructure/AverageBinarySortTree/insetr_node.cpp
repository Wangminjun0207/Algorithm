#include "Predefine.h"

//右旇
void R_Rotate(BSTree &p)
{
     BSTree lc;
     lc=p->lchild;
     p->lchild=lc->rchild;
     lc->rchild=p;
     p=lc;
}
//左旇
void L_Rotate(BSTree &p)
{
     BSTree rc;
     rc=p->rchild;
     p->rchild=rc->lchild;
     rc->lchild=p;
     p=rc;
}

//左平衡
void LeftBalance(BSTree &T)
{
     BSTree c,rd;
     c=T->lchild;
     switch(c->bf)
     {
     case LH:
          T->bf=c->bf=EH;
          R_Rotate(T);
          break;
     case RH:
          rd=c->rchild;
          switch(rd->bf)
          {
          case LH:T->bf=RH; c->bf=EH;break;
          case EH:T->bf=c->bf=EH; break;
          case RH:T->bf=EH;c->bf=LH;break;
          }
          rd->bf=EH;
          L_Rotate(T->lchild);
          R_Rotate(T);
     }
}
//右平衡
void RigthBalance(BSTree &T)
{
 BSTree rd,lc;
 rd=T->rchild;
 switch(rd->bf)
 {
               case RH:
                    T->bf=rd->bf=EH;
                    L_Rotate(T);
                    break;
               case LH:
                    lc=rd->lchild;
                    switch(lc->bf)
                    {
                    case RH:T->bf=LH;rd->bf=EH;break;
                    case EH:T->bf=rd->bf=EH;break;
                    case LH:T->bf=EH;rd->bf=RH;break;
                    }
                    lc->bf=EH;
                    R_Rotate(T->rchild);
                    L_Rotate(T);
 }
}
// 插入节点
int InsertAVL(BSTree &T,ElemType e,bool &taller)
{
       if(!T)
       {
             T=(BSTree)malloc(sizeof(BSTNode));
             T->data=e;
             T->lchild=T->rchild=NULL;
             T->bf=EH;
             taller=1;
       }
       else
       {
            if(EQ(e,T->data)) {taller=0;return 0;}//已经有结点了
            if(LT(e,T->data))
            {
                              if(!InsertAVL(T->lchild,e,taller))  return 0;//左子树的深度增加
                              if(taller)
                              switch(T->bf)
                              {
                                           case LH:
                                                LeftBalance(T);
                                                taller=0;
                                                break;
                                           case EH:
                                                T->bf=LH;
                                                taller=1;
                                                break;
                                           case RH:
                                                T->bf=EH;
                                                taller=0;
                                                break;
                              }
            }
            else
            {
                 if(!InsertAVL(T->rchild,e,taller))  return 0;//右子树的深度增加
                 if(taller)
                 switch(T->bf)
                 {
                              case LH:
                                   T->bf=EH;
                                   taller=0;
                                   break;
                              case EH:
                                   T->bf=RH;
                                   taller=1;
                              break;
                              case RH:
                                   RigthBalance(T);
                                   taller=0;
                                   break;
                 }
            }
       }
       return 1;
}
