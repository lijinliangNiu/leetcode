/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
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
    int ans;
    void dfs(TreeNode* root, int sum){
        if(root == nullptr){
            return;
        }
        sum = sum * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans += sum;
        }
        if(root->left != nullptr){
            dfs(root->left, sum);
        }
        if(root->right != nullptr){
            dfs(root->right, sum);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

