/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        // 2 比 5 多，统计因子中 5 的个数
        // n / 5 + n / 25 + n / 125 + ...
        int ans = 0;
        while(n >= 5){
            ans += (n / 5);
            n /= 5;
        }
        return ans;
    }
};
// @lc code=end

