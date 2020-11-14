/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size() - 1;
        for(int i = 0; i <= n;){
            if(nums[i] == val){
                nums[i] = nums[n--];
            }
            else{
                i++;
            }
        }
        return n + 1;
    }
};
// @lc code=end

