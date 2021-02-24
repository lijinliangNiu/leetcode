/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre_start = dummy;
        for(int i = 1; i < m; i++){
            pre_start = pre_start->next;
        }
        ListNode* start = pre_start->next;

        ListNode* pre = nullptr;
        ListNode* cur = start;
        for(int i = 0; i <= n - m; i++){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        pre_start->next = pre;
        start->next = cur;
        return dummy->next;
    }
};
// @lc code=end

