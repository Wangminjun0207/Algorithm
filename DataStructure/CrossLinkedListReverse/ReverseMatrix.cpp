#include "Predefine.h"
extern OLink delNode(OLink h);
extern int insert_RevMatrix(OLink row, OLink col, OLink s);
// ʮ������洢��ϡ�����ת��
OLink reverse(OLink h)
{
    // ���½�����ͷ�ڵ�����
    OLink row = new OLNode[h->j];//ת��֮����������ԭ��������
    if(!row) return NULL;        // ����NULL��ʾ����ʧ��
    for(int i=0; i<h->j; i++)
    {
        // λ��Ϊ��i,-1)
        row[i].i = i;
        row[i].j = -1;
        row[i].right = &row[i]; // ����ѭ������
    }
    // ���½�����ͷ�ڵ�����
    OLink col = new OLNode[h->i];//ת��֮����������ԭ��������
    if(!col) return NULL;       // ����NULL��ʾ����ʧ��
    for(int j=0;j<h->i;j++)
    {
        // λ��Ϊ(-1,j)
        col[j].i = -1;
        col[j].j = j;
        col[j].down = &col[j];  // ����ѭ������
    }
    int count = h->data; // �洢������Ԫ�ط���ĸ���
    OLink s;
    int temp;
    while(count)
    {
        s = delNode(h);
        // ����˳���ཻ��
        temp = s->i;
        s->i = s->j;
        s->j = temp;;
        insert_RevMatrix(row, col, s);// ��ת�������в���s�ڵ�
        --count;
    }
    // ����˳���ཻ��
    temp = h->i;
    h->i = h->j;
    h->j = temp;
    delete []h->down;      // �ͷ�ԭ�������������
    delete []h->right;     // �ͷ�ԭ�������������
    h->down = row;         // ��ͷ���downָ���¾����������
    h->right = col;        // ��ͷ���rightָ���¾����������
    return h;
}
