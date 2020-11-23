/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int min_price = prices[0], max_profit = 0;
        for(int price: prices){
            max_profit = max(max_profit, price - min_price);
            min_price = min(price, min_price);
        }
        return max_profit;
    }
};
// @lc code=end

