/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void dfs(TreeNode* root, int& ans, int& pre){
        if(root == nullptr){
            return;
        }
        dfs(root->left, ans, pre);
        if(pre != -1){
            ans = min(ans, abs(root->val - pre));
        }
        pre = root->val;
        dfs(root->right, ans, pre);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX, pre = -1;
        dfs(root, ans, pre);
        return ans;
    }
};
// @lc code=end

