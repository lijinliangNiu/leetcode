/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty() || word2.empty()){
            return word1.size() + word2.size();
        }

        vector<int> dp(word2.size() + 1);
        iota(dp.begin(), dp.end(), 0);

        for(int i = 1; i <= word1.size(); i++){
            int pre = dp[0]; // [i - 1][j - 1]
            dp[0] = i;
            for(int j = 1; j <= word2.size(); j++){
                int temp = dp[j];
                if(word1[i - 1] == word2[j - 1]){
                    dp[j] = pre; // [i - 1][j - 1]
                }
                else{
                    // [i][j - 1] [i - 1][j]
                    dp[j] = min(min(dp[j - 1], dp[j]), pre) + 1;
                }
                pre = temp;
            }
        }
        return dp.back();
    }
};
// @lc code=end

