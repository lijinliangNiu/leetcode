/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        int left = 0, right = A.size() - 1;
        for(int i = A.size() - 1; left <= right; i--){
            if(A[left] * A[left] > A[right] * A[right]){
                ans[i] = A[left] * A[left];
                left++;
            }
            else{
                ans[i] = A[right] * A[right];
                right--; 
            }
        }
        return ans;
    }
};
// @lc code=end

