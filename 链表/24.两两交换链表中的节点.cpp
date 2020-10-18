/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy_head = new ListNode(0, head);
        ListNode* temp = dummy_head;
        while(temp->next != nullptr && temp->next->next != nullptr){
            ListNode* p1 = temp->next;
            ListNode* p2 = temp->next->next;
            p1->next = p2->next;
            p2->next = p1;
            temp->next = p2;

            temp = p1;
        }
        return dummy_head->next;
    }
};
// @lc code=end

