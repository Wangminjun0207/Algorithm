#include "Predefine.h"
// 输出十字链表存储元素到文件
void print(OLink h,FILE *fp)
{
   int col;
   OLink p;
   fprintf(fp,"%d %d %d\n",h->i,h->j,h->data);
   for(col=0;col<h->i;++col)
   {
        p = h->down[col].right;
        while(p!=&h->down[col])
        {
            fprintf(fp,"%d %d %d\n",p->i,p->j,p->data);
            p = p->right;
        }
   }
   fprintf(fp,"FUNCTION:%s\nDATE:%s\nTIME:%s\n"\
           ,__FUNCTION__,__DATE__,__TIME__);
}
