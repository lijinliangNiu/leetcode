/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        // 前一天的状态
        int dp0 = 0;// 未进行交易
        int dp1 = -prices[0]; // 买入1次
        // 没有的状态，而且要防止溢出
        int dp2 = INT_MIN / 2;// 完成1次
        int dp3 = INT_MIN / 2;// 买入2次
        int dp4 = INT_MIN / 2;// 完成2次

        for(int i = 1; i < prices.size(); i++){
            int newdp1 = max(dp1, dp0 - prices[i]);
            int newdp2 = max(dp2, dp1 + prices[i]);
            int newdp3 = max(dp3, dp2 - prices[i]);
            int newdp4 = max(dp4, dp3 + prices[i]);
            dp1 = newdp1;
            dp2 = newdp2;
            dp3 = newdp3;
            dp4 = newdp4;
        }
        return max(max(dp0, dp2), dp4);
    }
};
// @lc code=end

