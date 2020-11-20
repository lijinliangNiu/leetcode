/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;//方便在head前插入

        ListNode* sorted = head;
        for(ListNode* cur = head->next; cur != nullptr; cur = sorted->next){
            if(cur->val >= sorted->val){
                sorted = sorted->next;//已排序的部分不断增长
            } 
            else{//cur要插入到排序部分，需找到其插入位置pre，pre后边插入cur
                ListNode* pre = dummy_head;
                while(cur->val >= pre->next->val){
                    pre = pre->next;
                }
                sorted->next = cur->next;//断开cur
                cur->next = pre->next;
                pre->next = cur;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

