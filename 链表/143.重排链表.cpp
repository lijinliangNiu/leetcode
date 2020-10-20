/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
private:
    ListNode* get_mid_node(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverse_list(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr){
            return;
        }
        ListNode* l1 = head;
        ListNode* mid = get_mid_node(head);
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverse_list(l2);
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;

            l1->next = l2;
            l1 = l1_next;

            l2->next = l1;
            l2 = l2_next;
        }
    }
};
// @lc code=end

