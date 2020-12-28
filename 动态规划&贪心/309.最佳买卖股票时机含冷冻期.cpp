/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int dp0 = -prices[0];// 手上持有股票
        int dp1 = 0;// 手上不持有股票，次日冷冻期(今天卖出了)
        int dp2 = 0; // 手上不持有股票，次日不在冷冻期
        for(int i = 1; i < prices.size(); i++){
            int newdp0 = max(dp0, dp2 - prices[i]);
            int newdp1 = dp0 + prices[i];
            int newdp2 = max(dp2, dp1);//继续不持有or度过冷冻期
            dp0 = newdp0;
            dp1 = newdp1;
            dp2 = newdp2;
        }
        return max(dp1, dp2);
    }
};
// @lc code=end

