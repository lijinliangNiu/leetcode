/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int ans = m * (1 << (n - 1));//每行第一个都是1 

        for(int j = 1; j < n; j++){
            int one_num = 0;
            for(int i = 0; i < m; i++){
                if(A[i][0] == 1){
                    one_num += A[i][j];
                }
                else{
                    one_num += (1 - A[i][j]);
                }
            }
            one_num = max(one_num, m - one_num);
            ans += one_num * (1 << (n - j - 1));
        }
        return ans;
    }
};
// @lc code=end

