/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int n = s.size();
        int count = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i - 1]){
                count++;
            }
            else{
                if(count >= 3){
                    ans.push_back({i - count, i - 1});
                }
                count = 1;
            }
        }
        if(count >= 3){
            ans.push_back({n - count, n - 1});
        }
        return ans;
    }
};
// @lc code=end

