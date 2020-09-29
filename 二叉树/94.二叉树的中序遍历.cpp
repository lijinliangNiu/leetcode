/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur != nullptr || !stk.empty()){
            if(cur != nullptr){
                stk.emplace(cur);
                cur = cur->left; //左
            }
            else{
                cur = stk.top();
                stk.pop();
                ans.emplace_back(cur->val); //中
                cur = cur->right;//右
            }
        }
        return ans;
    }
};
// @lc code=end

