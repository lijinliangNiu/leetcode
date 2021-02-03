/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) {
            return 0;
        }
        int ans = 0;
        int len = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i - 1]){
                len++;
            }
            else {
                ans = max(ans, len);
                len = 1;
            }
        }
        ans = max(ans, len);
        return ans;
    }
};
// @lc code=end

