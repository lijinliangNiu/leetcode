/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            int left = intervals[i][0], right = intervals[i][1];
            if(ans.back()[1] >= left){
                ans.back()[1] = max(ans.back()[1], right);
            }
            else{
                ans.push_back({left, right});
            }
        }
        return ans;
    }
};
// @lc code=end

