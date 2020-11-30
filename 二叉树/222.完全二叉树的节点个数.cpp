/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int cal_depth(TreeNode* root) {
        int depth = 0;
        while (root != nullptr) {
            depth++;
            root = root->left;
        }
        return depth;
    }
    //完全树，序号的二进制，除了第一位，可以指示路径，0左1右
    bool exists(TreeNode* root, int mid, int mask) {
        while (mask != 0) {//
            if((mask & mid) == 0){//记得加括号
                root = root->left;
            }
            else{
                root = root->right;
            }
            mask >>= 1;
        }
        return root != nullptr;
    }
public:
    int countNodes(TreeNode* root) {
        int depth = cal_depth(root);
        if (depth <= 1){
            return depth;
        }
        int low = 1 << (depth - 1), high = (1 << depth) - 1;
        while (low <= high) {
            int mid = low + (high - low + 1) / 2;
            if (exists(root, mid, 1 << (depth - 2))){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return high; 
    }
};
// @lc code=end

