/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        int ans = 0;
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
                ans += node->left->val;
            }
            if(node->right != nullptr){
                stk.push(node->right);
            }
            if(node->left != nullptr){
                stk.push(node->left);
            }
        }
        return ans;
    }
};
// @lc code=end

