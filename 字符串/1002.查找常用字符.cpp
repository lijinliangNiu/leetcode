/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> min_freq;
        for(const auto& ch : A[0]){
            min_freq[ch]++;
        }
        for(int i = 1; i < A.size(); i++){
            unordered_map<char, int> freq;
            for(const auto& ch : A[i]){
                freq[ch]++;
            }
            for(const auto& itr : min_freq){
                if(freq.count(itr.first) != 0){
                    min_freq[itr.first] = min(freq[itr.first], itr.second);
                }
                else{
                    min_freq[itr.first] = 0;
                }
            }
        }

        vector<string> ans;
        for(const auto& itr : min_freq){
            for(int i = 0; i < itr.second; i++){
                ans.emplace_back(1, itr.first);
            }
        }
        return ans;
    }
};
// @lc code=end

