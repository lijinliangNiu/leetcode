/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()){
            return 0;
        }
        if(s.size() == 1){
            return 1;
        }
        int l = 0, ans = 0;
        unordered_map<char, int> last_pos;
        for(int r = 0; r < s.size(); r++){
            if(last_pos.count(s[r])){
                l = max(l, last_pos[s[r]]);
            }
            last_pos[s[r]] = r + 1;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end

