/*
 * @lc app=leetcode.cn id=1030 lang=cpp
 *
 * [1030] 距离顺序排列矩阵单元格
 */

// @lc code=start
class Solution {
private:
    const int dr[4] = {1, 1, -1, -1};//上右下左
    const int dc[4] = {1, -1, -1, 1};
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int max_dist = max(r0, R - 1 - r0) + max(c0, C - 1 - c0);
        vector<vector<int>> ans;
        ans.push_back({r0, c0});
        int row = r0, col = c0;
        for(int dist = 1; dist <= max_dist; dist++){
            row--;//往上移一格
            for(int i = 0; i < 4; i++){
                while((i % 2 == 0 && row != r0) || (i % 2 != 0 && col != c0)){//右下、左上移动到r0，左下、右上移动到c0
                    if(row >= 0 && row < R && col >= 0 && col < C){
                        ans.push_back({row, col});
                    }                    
                    row += dr[i];
                    col += dc[i];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

