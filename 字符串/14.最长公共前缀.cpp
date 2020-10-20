/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
   public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        const auto [min_s, max_s] = minmax_element(strs.begin(), strs.end());
        for (int i = 0; i < min_s->size(); i++) {
            if (min_s->at(i) != max_s->at(i)) {
                return min_s->substr(0, i);
            }
        }
        return *min_s;
    }
};
// @lc code=end
