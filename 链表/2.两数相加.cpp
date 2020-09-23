/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* p = ans;
        bool carry = false;
        while(l1 != nullptr && l2 != nullptr){
            int sum = l1->val + l2->val;
            if(carry){
                sum++;
            }
            if(sum >= 10){
                carry = true;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = false;
                p->next = new ListNode(sum);
            }
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr){
            int sum = l1->val;
            if(carry){
                sum++;
            }
            if(sum >= 10){
                carry = true;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = false;
                p->next = new ListNode(sum);
            }
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != nullptr){
            int sum = l2->val;
            if(carry){
                sum++;
            }
            if(sum >= 10){
                carry = true;
                p->next = new ListNode(sum % 10);
            }
            else{
                carry = false;
                p->next = new ListNode(sum);
            }
            p = p->next;
            l2 = l2->next;
        }
        if(carry){
            p->next = new ListNode(1);
        }
        return ans->next;
    }
};
// @lc code=end

