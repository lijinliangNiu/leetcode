/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 对于多数元素，投票后count肯定>0
        int ans = nums[0];
        int count = 0;
        for(int& num : nums){
            if(count == 0){
                ans = num;
                count = 1;
            }
            else{
                if(num == ans){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

