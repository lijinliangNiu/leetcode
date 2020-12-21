/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for(char& ch: s){
            ans ^= ch;
        }
        for(char& ch: t){
            ans ^= ch;
        }
        return ans;
    }
};
// @lc code=end

