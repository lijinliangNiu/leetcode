/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        //不可能在降序部分进行交换
        for(; i >= 0 && nums[i] >= nums[i + 1]; i--){//从后向前，找到第一个跳出降序的
        }
        if(i >= 0){
            //在降序部分找最小的比小值大的
            int j = nums.size() - 1;
            for(; j >= i && nums[j] <= nums[i]; j--){
            }
            swap(nums[i], nums[j]);
        }
        //这部分变成升序会最小，由于原先是降序，直接反转
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

