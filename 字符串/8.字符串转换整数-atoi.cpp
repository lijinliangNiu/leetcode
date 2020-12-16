/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Automaton{
private:
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    int get_next_state(char c) {
        if (isspace(c)) {
            return 0;
        }
        else if (c == '+' or c == '-') {
            return 1;
        }
        else if (isdigit(c)) {
            return 2;
        }
        else{
            return 3;   
        }
    }
public:
    int sign = 1;
    long long ans = 0;
    
    void get(char c){
        state = table[state][get_next_state(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = (sign == 1) ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = (c == '+') ? 1 : -1;
    }
}
class Solution {
public:
    int myAtoi(string s) {
        Automaton automaton;
        for(auto& ch: s){
            automaton.get(ch);
        }
        return automaton.sign * automaton.ans;
    }
};
// @lc code=end

