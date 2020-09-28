/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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
    void handle(Node* &last, Node* &p, Node* &nextStart) {
        if (last != nullptr) {
            last->next = p;
        } 
        if (nextStart == nullptr) {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if(root == nullptr){
            return nullptr;
        }
        Node* start = root;
        while(start != nullptr){
            Node* last_node = nullptr;
            Node* next_start = nullptr;
            for(Node* p = start; p != nullptr; p = p->next){
                if(p->left != nullptr){
                    handle(last_node, p->left, next_start);
                }
                if(p->right != nullptr){
                    handle(last_node, p->right, next_start);
                }
                start = next_start;
            }
        }
        return root;
    }
};
// @lc code=end

