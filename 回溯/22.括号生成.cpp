/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
private:
    void backtrack(vector<string>& ans, string& cur, int left, int right, int n){
        if(cur.size() == 2 * n){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur.push_back('(');
            backtrack(ans, cur, left + 1, right, n);
            cur.pop_back();
        }
        if(right < left){
            cur.push_back(')');
            backtrack(ans, cur, left, right + 1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrack(ans, cur, 0, 0, n);
        return ans;
    }
};
// @lc code=end

