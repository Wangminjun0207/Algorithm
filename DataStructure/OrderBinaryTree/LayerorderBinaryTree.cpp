#include "Predefine.h"
#include "QueuePredefine.h"
extern int initQueue(BiTreeQueue bt_queue);
extern int enQueue(const BiTreeQueue Q,BiTree bt);
extern int isEmpty(const BiTreeQueue Q);
extern BiTree delQueue(const BiTreeQueue Q);
extern void visit(const BiTree bt);

// 层次遍历二叉树
int LayerTraval(BiTree bt)
{
	if(bt==NULL)
	{
		return 0;
	}
	BiTreeQueue Q = new BiTreeNodeQueue;
	initQueue(Q);
	enQueue(Q,bt);
	while(!isEmpty(Q))
	{
	    bt = delQueue(Q); // 队头元素出队
	    visit(bt);
	    if(bt->lelf_child)
        {
            enQueue(Q, bt->lelf_child);
        }
        if(bt->right_child)
        {
            enQueue(Q, bt->right_child);
        }
	}
	return 0;
}
