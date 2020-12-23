/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            return {};
        }
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int first = 0; first < nums.size(); first++){//固定第一个数，转化为求两数之和
            if(nums[first] > 0){//第一个数大于0，后面都是递增正数，不可能为零
                return ans;
            }
            if(first > 0 && nums[first] == nums[first - 1]){//去重：如果已选过
                continue;
            }
            int second = first + 1;
            int third = nums.size() - 1;
            while(second < third){//second要在third前边
                if(nums[first] + nums[second] + nums[third] > 0){
                    third--;
                }
                else if(nums[first] + nums[second] + nums[third] < 0){
                    second++;
                }
                else{
                    ans.push_back({nums[first], nums[second], nums[third]});
                    //左右指针内缩，继续寻找
                    second++;
                    third--;
                    // 去重：第二个数和第三个数不重复选取
                    while(second < third && nums[second] == nums[second - 1]){
                        second++;
                    }
                    while(second < third && nums[third] == nums[third + 1]){
                        third--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

