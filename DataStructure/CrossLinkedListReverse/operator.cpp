#include "Predefine.h"
extern OLink init(FILE *file);
extern int insert(OLink h, int i, int j, ElemTp data);
extern void print(OLink h,FILE *fp);
extern int reverse(OLink h);
// 代替主函数执行所有操作
void operat()
{
    FILE *file = NULL;
    // 打开文件，如果打开失败退出程序
    if((file = fopen("origin_data.txt","r"))==NULL)
    {
        printf("can not open the file!\n");
        exit(0);
    }
    OLink h = init(file);  // 从文件读入数据初始化矩阵链表

    int count = h->data; // 存储矩阵中元素非零的个数
    /***************************************************
     下面一段代码也可改为：
     OLink s;
     while(count)
     {
         fscanf(file,"%d%d%d",&s->i,&s->j,&s->data);
         insert(h,s); // int insert(OLink h, OLink s);
         --count;
     }
     相对来说代码量少，可读性强
     **************************************************/
    int i, j;
    ElemTp data;
    while(count)
    {
        // 从文件读入行、列、以及非零数据节点数据
        fscanf(file,"%d%d%d",&i,&j,&data);
        insert(h,i,j,data);
        --count; // 相对于count--效率较高
    }
    fclose(file);  // 关闭文件

    // 打开文件，如果打开失败退出程序
    if((file = fopen("reverse_data.txt","w"))==NULL)
    {
        printf("can not open the file!\n");
        exit(0);
    }
    print(h,file);
    fclose(file);  // 关闭文件
}
