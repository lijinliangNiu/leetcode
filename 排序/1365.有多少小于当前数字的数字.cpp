/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> value_index;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            value_index.emplace_back(nums[i], i);
        }
        sort(value_index.begin(), value_index.end());

        //注意有相等的val
        vector<int> ans(n, 0);
        int pre = -1;//当前元素前边和它不等的那个index
        for (int i = 0; i < n; i++) {
            if (pre == -1 || value_index[i].first != value_index[i - 1].first) {
                pre = i;
            }
            ans[value_index[i].second] = pre;//如果和前边val一样，接着用pre
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101, 0);
        for(const auto& num : nums){
            count[num]++;
        }
        for(int i = 1; i <= 100; i++){
            count[i] += count[i - 1];
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            ans.push_back(nums[i] == 0 ? 0 : count[nums[i] - 1]);
        }
        return ans;
    }
};
// @lc code=end

