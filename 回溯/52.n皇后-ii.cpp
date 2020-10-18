/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
private:
    int solve(int n, int row, int colomn, int left_diag, int right_diag) {
        if (row == n) {
            return 1;
        } 
        else {
            int count = 0;
            //位为1表示可放置的列
            int available_pos = ((1 << n) - 1) & (~(colomn | left_diag | right_diag));
            while (available_pos != 0) {
                int pos = available_pos & (-available_pos); //最低位的1的位置
                available_pos &= available_pos - 1; //最低位的1置成0
                count += solve(n, row + 1, colomn | pos, (left_diag | pos) >> 1, (right_diag | pos) << 1);
            }
            return count;
        }
    }
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }
};
// @lc code=end

