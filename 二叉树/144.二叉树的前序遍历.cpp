/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            if(node->right != nullptr){
                stk.emplace(node->right);
            }
            if(node->left != nullptr){
                stk.emplace(node->left);
            }
        }
        return ans;
    }
};
// @lc code=end

