/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        for(; x != 0; x /= 10){
            int comp = x % 10;
            if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && comp >7)){
                return 0;
            }
            if(ans < INT_MIN / 10 || (ans == INT_MIN / 10 && comp < -8)){
                return 0;
            }
            ans = ans * 10 + comp;
        }
        return ans;
    }
};
// @lc code=end

