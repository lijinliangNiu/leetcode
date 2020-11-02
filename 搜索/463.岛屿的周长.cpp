/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
private:
    constexpr static int dx[4] = {0, 1, 0, -1};
    constexpr static int dy[4] = {1, 0, -1, 0};
    int dfs(int x, int y, vector<vector<int>> &grid) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0) {
            return 1;
        }
        if (grid[x][y] == 2) {
            return 0;
        }
        //其余都说是合法1
        grid[x][y] = 2;//visited
        int ans = 0;
        for (int i = 0; i < 4; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            ans += dfs(tx, ty, grid);
        }
        return ans;
    }
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    ans += dfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

