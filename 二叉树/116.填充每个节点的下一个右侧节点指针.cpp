/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        Node* cur = root;
        Node* left_most = root;//不断指向下一层
        while(cur->left != nullptr){
            cur->left->next = cur->right;
            if(cur->next != nullptr){
                cur->right->next = cur->next->left;
                cur = cur->next;
            }
            else{
                cur = left_most->left;
                left_most = cur;
            }
        }
        return root;
    }
};
// @lc code=end

