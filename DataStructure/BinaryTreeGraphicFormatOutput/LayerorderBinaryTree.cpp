#include "Predefine.h"
extern int initQueue(BiTreeQueue bt_queue);
extern int enQueue(const BiTreeQueue Q,BiTree bt);
extern int isEmpty(const BiTreeQueue Q);
extern BiTree delQueue(const BiTreeQueue Q);
extern void visit(const BiTree bt);
extern std::vector<ElemTp> List;
// 层次遍历二叉树，求得按照层次存放的满二叉树数组
int LayerTraval(BiTree bt)
{
	if(bt==NULL)
	{
		return 0;
	}
	BiTreeQueue Q = new BiTreeNodeQueue;
	initQueue(Q);
	enQueue(Q,bt);
	List.insert(List.end(),bt->data); // 按照层次顺序存放在vector容器中
	while(!isEmpty(Q))
	{
	    bt = delQueue(Q); // 队头元素出队
	    // 如果取出的节点是占位符，则容器中进入两个占位符儿子节点
	    if(bt->data=='#')
        {
            List.insert(List.end(),'#');
            List.insert(List.end(),'#');
            continue;
        }
	    if(bt->lelf_child)
        {
            enQueue(Q, bt->lelf_child);
            // 左儿子进入容器
            List.insert(List.end(),bt->lelf_child->data);
        }
        else{
            // 队列中进入占位符节点，并且容器中进两个占位符
            BiTree node = new BiTreeNode;
            node->data = '#';
            enQueue(Q, node);
            List.insert(List.end(),'#');
        }
        if(bt->right_child)
        {
            enQueue(Q, bt->right_child);
            // 右儿子进入容器
            List.insert(List.end(),bt->right_child->data);
        }
        else{
            // 队列中进入占位符节点，并且容器中进两个占位符
            BiTree node = new BiTreeNode;
            node->data = '#';
            enQueue(Q, node);
            List.insert(List.end(),'#');
        }
	}
	return 0;
}
