/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
   public:
    bool backspaceCompare(string S, string T) {
        for (int i = S.size() - 1, j = T.size() - 1; i >= 0 || j >= 0;
             i--, j--) {
            int skipS = 0;
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            int skipT = 0;
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            if((i >= 0 && j < 0) || (i < 0 && j >= 0)){//# is too many
                return false;
            }
            else if(i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } 
        }
        return true;
    }
};
// @lc code=end
