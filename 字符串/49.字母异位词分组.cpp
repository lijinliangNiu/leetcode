/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
            //累加，有个lambda函数
            //lambda：累加和，待累加数
            return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                //一个可以用的hash combine方法
                return (acc << 1) ^ fn(num);
            });
        };

        unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
        for(string& str: strs){
            array<int, 26> counts{};
            for(char& ch: str){
                counts[ch - 'a']++;
            }
            mp[counts].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto& it: mp) {
            ans.emplace_back(it.second);
        }
        return ans;
    }
};
// @lc code=end

