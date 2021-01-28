/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> hash(100);
        int ans = 0;
        for(auto& dominoe: dominoes){
            int key = 0;
            if(dominoe[0] < dominoe[1]){
                key = dominoe[0] * 10 + dominoe[1];
            }
            else{
                key = dominoe[1] * 10 + dominoe[0];
            }
            ans += hash[key];
            hash[key]++;    
        }
        return ans;
    }
};
// @lc code=end

