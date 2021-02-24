/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(pre != tail){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        while (head != nullptr) {
            ListNode* head = pre->next;
            ListNode* tail = head;
            for (int i = 1; i < k; i++) {
                if (tail == nullptr) {
                    return dummy->next;
                }
                tail = tail->next;
            }
            if(tail == nullptr){
                return dummy->next;
            }
            ListNode* temp = tail->next;
            tie(head, tail) = myReverse(head, tail);
            pre->next = head;
            tail->next = temp;
            pre = tail;
        }

        return dummy->next;
    }
};
// @lc code=end

