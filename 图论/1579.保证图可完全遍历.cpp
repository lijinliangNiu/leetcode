/*
 * @lc app=leetcode.cn id=1579 lang=cpp
 *
 * [1579] 保证图可完全遍历
 */

// @lc code=start
class UnionSet {
public:
    vector<int> parent;
    vector<int> rank;
    int component_num; // 连通分量数
public:
    UnionSet(int n): component_num(n), parent(n), rank(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    // bool判断边是否有用（减少了连通分量）
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return false;
        }
        // 小的挂在大的下
        if(rank[a] < rank[b]){
            swap(a, b);
        }
        rank[a] += rank[b];
        parent[b] = a;
        component_num--;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionSet unionset_a(n), unionset_b(n);
        for(auto& edge: edges){// 节点编号改为从 0 开始
            edge[1]--;
            edge[2]--;
        }
        int ans = 0;

        // 公共边
        for (const auto& edge: edges) {
            if (edge[0] == 3) {
                if(!unionset_a.join(edge[1], edge[2])){
                    ans++;
                }
                else{
                    unionset_b.join(edge[1], edge[2]);
                }
            }
        }

        // 独占边
        for (const auto& edge: edges) {
            if (edge[0] == 1) {
                // Alice 独占边
                if (!unionset_a.join(edge[1], edge[2])) {
                    ans++;
                }
            }
            else if (edge[0] == 2) {
                // Bob 独占边
                if (!unionset_b.join(edge[1], edge[2])) {
                    ans++;
                }
            }
        }

        if (unionset_a.component_num != 1 || unionset_b.component_num != 1) {
            return -1;
        }
        return ans;
    }
};
// @lc code=end

