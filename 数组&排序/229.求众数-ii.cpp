/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 不超过2个
        int candidate1 = nums[0];
        int candidate2 = nums[0];
        int count1 = 0;
        int count2 = 0;
        for(int& num: nums){
            if(num == candidate1){
                count1++;
            }
            else if(num == candidate2){
                count2++;
            }
            else if(count1 == 0){
                candidate1 = num;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = num;
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int& num: nums){
            if(num == candidate1){
                count1++;
            }
            if(num == candidate2){
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > nums.size() / 3){
            ans.emplace_back(candidate1);
        }
        if(count2 > nums.size() / 3 && candidate1 != candidate2){
            ans.emplace_back(candidate2);
        }
        return ans;
    }
};
// @lc code=end

