/*给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照逆序的方式存储的，
并且它们的每个节点只能存储一位数字。如果，我们将这两个数相加起来，则会返回一个新的链
表来表示它们的和。您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807*/

/**
 * Definition for singly-linked list.
 * #include <stdio.h>
 * #include <stdlib.h>
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *lc, *p, *q, *s;
    int i = 0, flag = 0;
    p = (struct ListNode*)malloc(sizeof(struct ListNode));
    while(l1 && l2)
    {
        p->val = (l1->val + l2->val + flag)% 10; 
        if(l1->val + l2->val + flag>= 10)  
            flag = 1; 
        else
            flag = 0;
        if(i==0)
            q = lc = p;
        else{
            q->next = p;
            q = p;
        }
        i++;
        l1 = l1->next;
        l2 = l2->next;
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
    }
    free(p);
    q->next = NULL;
    
    if(flag==0)
    {
        if(l1){
            q->next = l1;
            return lc;
        }
        if(l2){
            q->next = l2;
            return lc;
        }   
    }
    
    else{
        if(!l1 && !l2)
        {
            p = (struct ListNode*)malloc(sizeof(struct ListNode));
            p->val = 1;
            q->next = p;
            p->next = NULL;
        }
        if(l1)
        {
            q->next = l1;
			while(flag && l1)
			{
				if(l1->val+1==10)
				{
					l1->val = 0;
					s = l1;
					l1 = l1->next;
				}
				else
				{
					l1->val = l1->val + 1;
					flag = 0;
				}
			}
			if(flag)
			{
				p = (struct ListNode*)malloc(sizeof(struct ListNode));
                p->val = 1;
                s->next = p;
                p->next = NULL;
			} 
            
        }
        if(l2)
        {
            q->next = l2;
			while(flag && l2)
			{
				if(l2->val+1==10)
				{
					l2->val = 0;
					s = l2;
					l2 = l2->next;
				}
				else
				{
					l2->val = l2->val + 1;
					flag = 0;
				}
			}
			if(flag)
			{
				p = (struct ListNode*)malloc(sizeof(struct ListNode));
                p->val = 1;
                s->next = p;
                p->next = NULL;
			} 
        }
    }
    return lc;
}

//int main()
//{
//	struct ListNode a,b,c;
//	struct ListNode *p;
//	a.val = 1;
//	a.next = NULL;
//	b.val = c.val = 9;
//	b.next = &c;
//	c.next = NULL;
//	p = addTwoNumbers(&a,&b);
//	for(;p!=NULL;p=p->next) 
//		printf("%d\n",p->val);
//}
