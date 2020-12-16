/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> ch2str;
        unordered_map<string, char> str2ch;
        stringstream ss(s);
        string str;
        for(auto& ch : pattern){
            if(!(ss >> str)){
                return false;
            }
            if(ch2str.count(ch) && ch2str[ch] != str){
                return false;
            }
            if(str2ch.count(str) && str2ch[str] != ch){
                return false;
            }
            ch2str[ch] = str;
            str2ch[str] = ch;
        }
        return (ss >> str) ? false : true;
    }
};
// @lc code=end

