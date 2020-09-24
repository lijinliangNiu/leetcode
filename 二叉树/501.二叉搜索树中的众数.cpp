/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
//BST的中序遍历是一个非递减的有序序列
/*
Morris中序遍历(无递归栈)
*/
class Solution {
private:
    int base, count, maxCount;
    vector<int> ans;
    void update(int x){//遍历方法
        if(x == base){
            count++;
        }
        else{
            count = 1;
            base = x;
        }
        if(count == maxCount){
            ans.emplace_back(base);
        }
        if(count > maxCount){
            maxCount = count;
            ans = {base};
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left == nullptr) { // 当前节点没有左子树，则遍历这个点，然后到当前节点的右子树
                update(cur->val);
                cur = cur->right;
                continue;
            }
            TreeNode* pre = cur->left;// 当前节点有左子树，那么它的前驱一定在左子树上
            while (pre->right != nullptr && pre->right != cur) {// 我们可以在左子树上一直向右，找到当前点的前驱
                pre = pre->right;
            }
            if (pre->right == nullptr) {//前驱没有右子树，为了在遍历完前驱后能找到前驱节点的后继，将前驱的right指向当前节点
                pre->right = cur;
                cur = cur->left;
            } 
            else {// 如果前驱的右子树为当前（不空肯定是当前），说明前驱已遍历并修改了right，将前驱的right置空，遍历当前，然后跳转到当前的右子树
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

