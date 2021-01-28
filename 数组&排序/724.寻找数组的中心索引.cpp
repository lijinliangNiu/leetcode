/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(2 * sum + nums[i] == total){
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
// @lc code=end

