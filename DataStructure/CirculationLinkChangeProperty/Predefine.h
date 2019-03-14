typedef struct node
{
    int nNumber;
    struct node *prior;
    struct node *next;
}Node, *NodePtr;
