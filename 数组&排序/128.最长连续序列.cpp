/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(const int& num : nums){
            num_set.insert(num);
        }
        int ans = 0;
        for(const int& num : num_set){
            if(!num_set.count(num - 1)){// can be begin
                int cur = num;
                int cur_ans = 1;

                while(num_set.count(cur + 1)){
                    cur += 1;
                    cur_ans += 1;
                }
                ans = max(ans, cur_ans);
            }
        }
        return ans;           
    }
};
// @lc code=end

