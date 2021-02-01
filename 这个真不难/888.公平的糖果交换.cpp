/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int A_sum = accumulate(A.begin(), A.end(), 0);
        int B_sum = accumulate(B.begin(), B.end(), 0);
        int delta = (A_sum - B_sum) / 2;
        unordered_set<int> A_map(A.begin(), A.end());
        for(auto& b : B){
            int a = b + delta;
            if(A_map.count(a)){
                return {a, b};
            }
        }
        return {};
    }
};
// @lc code=end

