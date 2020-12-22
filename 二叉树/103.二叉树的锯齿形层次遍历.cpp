/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;
        
        while(!q.empty()){
            deque<int> level_deque;
            int level_size = q.size();
            for(int i = 0; i < level_size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(left){
                    level_deque.push_back(node->val);
                }
                else{
                    level_deque.push_front(node->val);
                }

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            ans.emplace_back(vector<int>{level_deque.begin(), level_deque.end()});
            left = !left;
        }
        return ans;
    }
};
// @lc code=end

