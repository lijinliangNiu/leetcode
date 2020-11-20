/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //one for iteration, one for change
        int left = 0, right = 0;
        for(; right < nums.size(); right++){
            //when meet non_zero, replace it
            if(nums[right] != 0){
                swap(nums[right], nums[left]);
                left++;
            }
        }
    }
};
// @lc code=end

