/* 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 示例：
 给定一个链表: 1->2->3->4->5, 和 n = 2.
 当删除了倒数第二个节点后，链表变为 1->2->3->5. */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> tmp; // 存储链表的指针
        ListNode *ptr = head;       // ListNode指针指向链表头结点
        // 将链表的所有节点指针存到vector容器
        while(ptr)
        {
            tmp.push_back(ptr);
            ptr = ptr->next;
        }
        // 删除第一个节点
        if(n==tmp.size())
            head = head->next;
        // 删除其他节点（除第一个外的）
        else  
            tmp.at(tmp.size()-n-1)->next = tmp.at(tmp.size()-n)->next;
        return head;
    }
};