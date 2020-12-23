/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val2index;
        for(int i = 0; i < nums.size(); i++){
            auto complement = val2index.find(target - nums[i]);
            if(complement != val2index.end()){
                return {complement->second, i};
            }
            val2index[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end