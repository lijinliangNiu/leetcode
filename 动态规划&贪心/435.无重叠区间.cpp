/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        // 右排序
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int ans = 0;
        int cur = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[cur][1]){
                ans++;
            }
            else{
                cur = i;
            }
        }
        return ans;
    }
};
// @lc code=end

