/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};
// @lc code=end

