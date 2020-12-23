/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
private:
    vector<string> ans;
    string current;
    unordered_map<char, string> phone_map{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void backtrack(const string& digits, int index){
        if(index == digits.size()){
            ans.emplace_back(current);
        }
        else{
            const string& letters = phone_map[digits[index]];
            for(auto& ch: letters){
                current.push_back(ch);
                backtrack(digits, index + 1);
                current.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        backtrack(digits, 0);
        return ans;
    }
};
// @lc code=end

