/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int even_index = 0;
        int odd_index = 1;
        while(even_index < A.size()){
            if(A[even_index] % 2 == 1){//该放偶数的位置放了奇数
                while(A[odd_index] % 2 == 1){//就找奇数位置上的偶数
                    odd_index += 2;
                }
                swap(A[even_index], A[odd_index]);
            }
            even_index += 2;
        }
        return A;
    }
};
// @lc code=end

