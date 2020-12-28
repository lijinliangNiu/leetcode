/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2 || k == 0){
            return 0;
        }
        int n = prices.size();
        k = min(k, n / 2);
        //我没拆动
        vector<int> dp(2 * k + 1, INT_MIN / 2);
        dp[0] = 0;
        dp[1] = - prices[0];
        for(int i = 1; i < prices.size(); i++){
            vector<int> newdp(2 * k + 1, INT_MIN / 2);
            newdp[0] = 0;
            for(int j = 1; j < newdp.size(); j++){
                if(j % 2 == 0){
                    newdp[j] = max(dp[j], dp[j - 1] + prices[i]);
                }
                else{
                    newdp[j] = max(dp[j], dp[j - 1] - prices[i]);
                }
            }
            copy(newdp.begin(), newdp.end(), dp.begin());
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

