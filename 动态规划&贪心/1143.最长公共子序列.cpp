/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty() || text2.empty()){
            return 0;
        }
        vector<int> dp(text2.size() + 1);
        for(auto ch1 : text1){
            int pre = 0; // dp[i - 1][j - 1]
            for(int j = 1; j <= text2.size(); j++){
                int tmp = dp[j];
                if(ch1 == text2[j - 1]){
                    dp[j] = last + 1;
                }
                else{
                    dp[j] = max(dp[j], dp[j - 1]);// dp[i - 1][j] dp[i][j - 1]
                }
                pre = tmp;
            }
        }
        return dp.back();
    }
};
// @lc code=end

