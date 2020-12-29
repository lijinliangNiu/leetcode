/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long x = 1; // 当前覆盖区间[1, 1)
        int index = 0;
        while(x <= n){
            if(index < nums.size() && nums[index] <= x){
                x += nums[index++];// 比当前区间小的可以扩展
            }
            else{// 比当前区间大的，添加x，然后这样扩展
                x += x;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

