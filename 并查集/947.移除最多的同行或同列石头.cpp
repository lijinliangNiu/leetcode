/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
private:
    int parent[20001];
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);
        parent[b_parent] = a_parent;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0; i < stones.size(); i++){
            parent[stones[i][0]] = stones[i][0];
            parent[stones[i][1] + 10000] = stones[i][1] + 10000;
        }
        for(int i = 0; i < stones.size(); i++){
            // 行和列串在一起，是一个连通分量
            join(stones[i][0], stones[i][1] + 10000);
        }
        set<int> ans;
        for(int i = 0; i < stones.size(); i++){
            ans.insert(find(stones[i][0]));
        }
        return stones.size() - ans.size();
    }
};
// @lc code=end

