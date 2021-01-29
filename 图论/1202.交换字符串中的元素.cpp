/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Solution {
private:
    vector<int> parent;
    void init(int n){
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){
        if(parent[x] != x){
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        init(s.size());
        for (auto& it : pairs) {
            join(it[0], it[1]);
        }
        unordered_map<int, vector<int>> exchanege;
        for (int i = 0; i < s.length(); i++) {
            exchanege[find(i)].emplace_back(s[i]);
        }
        for (auto& [x, vec] : exchanege) {
            sort(vec.begin(), vec.end(), greater<int>());
        }
        for (int i = 0; i < s.length(); i++) {
            int x = find(i);
            s[i] = exchanege[x].back();
            exchanege[x].pop_back();
        }
        return s;
    }
};
// @lc code=end

