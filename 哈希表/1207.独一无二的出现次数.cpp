/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occur_times;
        for(const auto& x : arr){
            occur_times[x]++;
        }
        unordered_set<int> occur_time_set;
        for(const auto& occur_time : occur_times){
            occur_time_set.insert(occur_time.second);
        }
        return occur_times.size() == occur_time_set.size();
    }
};
// @lc code=end

