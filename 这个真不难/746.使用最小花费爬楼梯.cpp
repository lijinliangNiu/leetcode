/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prepre = 0, pre = 0;
        for(int i = 2; i <= cost.size(); i++){
            int cur = min(pre + cost[i - 1], prepre + cost[i - 2]);
            prepre = pre;
            pre = cur;
        }
        return pre;
    }
};
// @lc code=end

