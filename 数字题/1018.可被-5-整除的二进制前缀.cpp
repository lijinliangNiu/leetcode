/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int prefix = 0;
        for(int i = 0; i < A.size(); i++){
            //mod的公式
            prefix = ((prefix << 1) + A[i]) % 5;
            ans.emplace_back(prefix == 0);
        }
        return ans;
    }
};
// @lc code=end

