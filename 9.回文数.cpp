/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x != 0 && x % 10 == 0)){
            return false;
        }
        int revert_num = 0;
        for(; x > revert_num; x /= 10){
            revert_num = revert_num * 10 + x % 10;
        }
        return x == revert_num || x == revert_num / 10; 
    }
};
// @lc code=end

