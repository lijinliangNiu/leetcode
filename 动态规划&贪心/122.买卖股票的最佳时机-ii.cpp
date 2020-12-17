/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0 = 0, dp1 = -prices[0];//这一天交易后没有/有股票
        for (int i = 1; i < prices.size(); ++i) {
            tie(dp0, dp1) = pair(max(dp0, dp1 + prices[i]), max(dp1, dp0 - prices[i]));
        }
        return dp0;
    }
};
// @lc code=end

