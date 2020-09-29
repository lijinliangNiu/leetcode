/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> stk;
        stk.emplace(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            ans.emplace_back(node->val);
            if (node->left != nullptr) {
                stk.emplace(node->left);
            }
            if (node->right != nullptr) {
                stk.emplace(node->right);
            }
        }
        reverse(ans.begin(), ans.end());  //中右左反转即为后序
        return ans;
    }
};

//不用翻转
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> ans;

        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;//指向前一节点，标记右子是否被访问
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            if (cur != nullptr) {
                stk.emplace(cur);
                cur = cur->left;
            } 
            else {
                cur = stk.top();
                if (cur->right == nullptr || cur->right == pre) {//right被访问过才该访问这个节点
                    ans.emplace_back(cur->val);
                    stk.pop();
                    pre = cur;
                    cur = nullptr;
                } 
                else {
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
