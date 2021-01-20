/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
class UnionSet {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionSet(int n){
        rank = vector<int>(n, 1);
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool join(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);
        if(a_parent == b_parent){
            return false;
        }
        if(rank[a_parent] < rank[b_parent]){
            swap(a_parent, b_parent);
        }
        rank[a_parent] += rank[b_parent];
        parent[b_parent] = a_parent;
        return true;
    }
};

struct Edge {
    int len, x, y;
    Edge(int len, int x, int y) : len(len), x(x), y(y) {
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int x, int y){
            return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
        };
        vector<Edge> edges;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges.emplace_back(dist(i, j), i, j);
            }
        }
        sort(edges.begin(), edges.end(), [&](Edge a, Edge b){ return a.len < b.len; });
        int n = points.size();
        UnionSet unionSet(n);
        int ans = 0, num = 0;
        for (auto& [len, x, y] : edges) {
            if (unionSet.join(x, y)) {
                ans += len;
                num++;
                if (num == n - 1) {
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

