/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp0 = 0, dp1 = -prices[0];
        for(int i = 1; i < prices.size(); i++){
            tie(dp0, dp1) = pair(max(dp0, dp1 + prices[i] - fee), max(dp1, dp0 - prices[i]));
        }
        return dp0;
    }
};
// @lc code=end

