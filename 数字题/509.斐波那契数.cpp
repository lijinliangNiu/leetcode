/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> matrix_pow(vector<vector<int>>& a, int n) {
        vector<vector<int>> ans{{1, 0}, {0, 1}};
        while(n > 0){
            if(n & 1){
                ans = matrix_multiply(ans, a);
            }
            n >>= 1;
            a = matrix_multiply(a, a);
        }
        return ans;
    }

    vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b){
        vector<vector<int>> ans{{0, 0}, {0, 0}};
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return ans;
    }
public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<int>> q{{1, 1}, {1, 0}};
        vector<vector<int>> res = matrix_pow(q, n - 1);
        return res[0][0];
    }
};
// @lc code=end

