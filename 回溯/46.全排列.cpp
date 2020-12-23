/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int index, int length){
        if(index == length){
            ans.emplace_back(nums);
        }
        else{
            for(int i = index; i < length; i++){
                swap(nums[index], nums[i]);
                backtrack(nums, index + 1, length);
                swap(nums[index], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0, nums.size());
        return ans;
    }
};
// @lc code=end

