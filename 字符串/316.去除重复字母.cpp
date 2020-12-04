/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.empty()){
            return "";
        }
        unordered_map<char, int> last_index;
        for(int i = 0; i < s.size(); i++){
            last_index[s[i]] = i;
        }

        //已经到了正确位置的字符
        set<char> added_char;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            //到了正确位置的字符，其后的字符都不小于它，
            //再来该字符肯定踢不掉它
            if(added_char.find(s[i]) == added_char.end()){
                while(!ans.empty() && ans.back() > s[i] && last_index[ans.back()] > i){
                    added_char.erase(ans.back());
                    ans.pop_back();
                }
                ans.push_back(s[i]);
                added_char.insert(s[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

