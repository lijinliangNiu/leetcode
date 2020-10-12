/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> match_map = { {'}', '{'}, {']', '['}, {')', '('}};
        stack<char> stk;
        for(auto& ch : s){
            if(ch == '{' || ch == '[' || ch == '('){
                stk.push(ch);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                if(stk.top() != match_map[ch]){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end

