/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
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
private:
    // 迭代
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (u == nullptr && v == nullptr){
                continue;
            }
            else if ((u == nullptr || v == nullptr) || (u->val != v->val)) {
                return false;
            }

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }
    // 递归
    bool check(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if(p == nullptr || q == nullptr){
            return false;
        }
        else{
            return (p->val == q->val) && check(p->left, q->right) && check(p->right, q->left);
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
// @lc code=end

