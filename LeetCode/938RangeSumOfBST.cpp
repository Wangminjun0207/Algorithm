/*
给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
二叉搜索树保证具有唯一的值。

示例 1：

输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
输出：32
示例 2：

输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
输出：23
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(NULL==root) return 0; // 空树
        int sum = 0;             // 返回L和R之间的和
        if(L>R) sum = 0;         // 范围不存在
        else if(L==R) sum = L;   // 范围只包含一个元素
        else{                    // 范围包含多个元素
            queue<TreeNode *> Queue;
            Queue.push(root);    // 根节点入队
            while(Queue.size())
            {
                TreeNode* temp = Queue.front();
                Queue.pop();
                if(temp->val>=L && temp->val<=R)
                {
                    sum += temp->val;
                }
                if(temp->left && temp->val>=L)
                {
                    Queue.push(temp->left);
                }
                if(temp->right && temp->val<=R)
                {
                    Queue.push(temp->right);
                }
            }
        }
        return sum;
    }
};