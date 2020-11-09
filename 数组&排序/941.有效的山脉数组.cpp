/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        for(; i + 1 < A.size() && A[i] < A[i + 1]; i++){
            ; 
        }
        if(i == 0 || i == A.size() - 1){
            return false;
        }
        for(; i + 1 < A.size() && A[i] > A[i + 1]; i++){
            ;
        }
        return i == A.size() - 1;
    }
};
// @lc code=end

