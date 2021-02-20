/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto& num : nums){
            mp[num]++;
        }
        for(auto& i : mp){
            if(mp.count(i.first + 1)){
                ans = max(ans, i.second + mp[i.first + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end

