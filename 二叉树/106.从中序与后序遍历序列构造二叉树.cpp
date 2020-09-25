/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
/*
和105中中序前序不同的是，后序可以利用先右后左以及一个int变量省去一大部分参数
*/
class Solution {
   private:
    int postorder_root_index;
    unordered_map<int, int> val2Index;

    TreeNode* buildTree(const vector<int>& inorder,
                        const vector<int>& postorder, int inorder_left,
                        int inorder_right) {
        if (inorder_left > inorder_right) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[postorder_root_index]);

        int inorder_root_index = val2Index[root->val];

        postorder_root_index--;
        root->right = buildTree(inorder, postorder, inorder_root_index + 1,
                                inorder_right);
        root->left =
            buildTree(inorder, postorder, inorder_left, inorder_root_index - 1);
        return root;
    }

   public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_root_index = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            val2Index[inorder[i]] = i;
        }
        return buildTree(inorder, postorder, 0, inorder.size() - 1);
    }
};
// @lc code=end
