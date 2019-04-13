#include "Predefine.h"
// ���ڴ��ַ��ļ��������ݣ�������ϡ������ʮ������ṹ
OLink init(FILE *file)
{
    OLink h = new OLNode;     // ������ͷ���
    // ���ļ������С��С��Լ��������ݽڵ���
    fscanf(file,"%d%d%d",&h->i,&h->j,&h->data);

    // ���½�����ͷ�ڵ�����
    OLink row = h->down = new OLNode[h->i];
    if(!row) return NULL;    // ����NULL��ʾ����ʧ��
    for(int i=0; i<h->i; i++)
    {
        // λ��Ϊ��i,-1)
        row[i].i = i;
        row[i].j = -1;
        row[i].right = &row[i]; // ����ѭ������
    }
    // ���½�����ͷ�ڵ�����
    OLink col = h->right = new OLNode[h->j];
    if(!col) return NULL;   // ����NULL��ʾ����ʧ��
    for(int j=0;j<h->j;j++)
    {
        // λ��Ϊ(-1,j)
        col[j].i = -1;
        col[j].j = j;
        col[j].down = &col[j];  // ����ѭ������
    }
    return h;
}
