#include "Predefine.h"
// ��ʼ��ѭ������
int initQueue(BiTreeQueue bt_queue)
{
    bt_queue->Node = new BiTreeNode[30];
    bt_queue->f = bt_queue->r = -1;
    return 1; // ���г�ʼ���ɹ�����1
}
