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

        //这个字符是不是有了
        set<char> added_char;
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            //没有就往里放
            if(added_char.find(s[i]) == added_char.end()){
                //小的踢掉大的
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

