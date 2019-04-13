#include "Predefine.h"
extern OLink init(FILE *file);
extern int insert(OLink h, int i, int j, ElemTp data);
extern void print(OLink h,FILE *fp);
extern int reverse(OLink h);
// ����������ִ�����в���
void operat()
{
    FILE *file = NULL;
    // ���ļ��������ʧ���˳�����
    if((file = fopen("origin_data.txt","r"))==NULL)
    {
        printf("can not open the file!\n");
        exit(0);
    }
    OLink h = init(file);  // ���ļ��������ݳ�ʼ����������

    int count = h->data; // �洢������Ԫ�ط���ĸ���
    /***************************************************
     ����һ�δ���Ҳ�ɸ�Ϊ��
     OLink s;
     while(count)
     {
         fscanf(file,"%d%d%d",&s->i,&s->j,&s->data);
         insert(h,s); // int insert(OLink h, OLink s);
         --count;
     }
     �����˵�������٣��ɶ���ǿ
     **************************************************/
    int i, j;
    ElemTp data;
    while(count)
    {
        // ���ļ������С��С��Լ��������ݽڵ�����
        fscanf(file,"%d%d%d",&i,&j,&data);
        insert(h,i,j,data);
        --count; // �����count--Ч�ʽϸ�
    }
    fclose(file);  // �ر��ļ�

    // ���ļ��������ʧ���˳�����
    if((file = fopen("reverse_data.txt","w"))==NULL)
    {
        printf("can not open the file!\n");
        exit(0);
    }
    print(h,file);
    fclose(file);  // �ر��ļ�
}
