/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0, j = 0; i < g.size() && j < s.size();){
            if(g[i] <= s[j]){
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};
// @lc code=end

