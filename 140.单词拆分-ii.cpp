/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
private:
    unordered_map<int, vector<string>> ans;//哈希表存储每个下标和从该下标开始的部分可以组成的句子
    unordered_set<string> wordSet;//哈希集合存储单词列表，优化查询单词是在合法的时间

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }

    void backtrack(const string& s, int index) {
        if (ans.count(index) == 0) {
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); ++i) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word) != 0) {
                    backtrack(s, i);
                    for (const string& sentence: ans[i]) {
                        ans[index].push_back(sentence.empty() ? word : word + " " + sentence);
                    }
                }
            }
        }
    }
};
// @lc code=end

