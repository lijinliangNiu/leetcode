/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0){
            return false;
        }
        int i = 0;
        int j = sqrt(c);

        while(i <= j){
            if(i * i == c - j * j){
                return true;
            }
            else if(c - j * j < i * i){
                j--;
            }
            else{
                i++;
            }
        }

        return false;
    }
};
// @lc code=end

