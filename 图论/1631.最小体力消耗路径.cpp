/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */

// @lc code=start

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    class Edge{
    public:
        int x, y, dist;
        Edge(int x, int y, int dist): x(x), y(y), dist(dist){}
        // 默认大顶，根据<判断前后，这样小的会排在前边
        bool operator< (const Edge& edge) const{
            return dist > edge.dist;
        }
    };
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<Edge> q;
        q.emplace(0, 0, 0);
        vector<vector<int>> visted(m, vector<int>(n));
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        ans[0][0] = 0;

        while(!q.empty()){
            auto [x, y, dist] = q.top();
            q.pop();
            if(visted[x][y]){
                continue;
            }
            visted[x][y] = 1;
            ans[x][y] = dist;
            for(int i = 0; i < 4; i++){
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visted[nx][ny]){
                    q.emplace(nx, ny, max(dist, abs(heights[x][y] - heights[nx][ny])));
                }
            }
        }
        return ans[m - 1][n - 1];
    }
};
// @lc code=end

