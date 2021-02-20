/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num : nums){
            if(num_set.count(num)){
                return true;
            }
            num_set.insert(num);
        }
        return false;
    }
};
// @lc code=end

