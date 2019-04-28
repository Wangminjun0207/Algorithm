#include "Predefine.h"
// 初始化循环队列
int initQueue(BiTreeQueue bt_queue)
{
    bt_queue->Node = new BiTreeNode[30];
    bt_queue->f = bt_queue->r = -1;
    return 1; // 队列初始化成功返回1
}
