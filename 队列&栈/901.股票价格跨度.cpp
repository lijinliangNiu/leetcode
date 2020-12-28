/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
class StockSpanner {
public:
    stack<pair<int,int>> monoStack; //价格，连续日数

    StockSpanner() {
    }
    
    int next(int price) {
        pair<int, int> cur(price, 1);
        while(!monoStack.empty() && monoStack.top().first <= price){
            auto tmp = monoStack.top();
            cur.second += tmp.second;
            monoStack.pop();
        }
        monoStack.push(cur);
        return cur.second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

