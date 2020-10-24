/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> max_index;
        for(int i = 0; i < S.size(); i++){
            max_index[S[i]] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < S.size(); i++){
            end = max(max_index[S[i]], end);
            if(i == end){
                ans.emplace_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

