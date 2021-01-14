/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 */

// @lc code=start
class UnionSet{
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight;

    // 路径压缩后更新权值
    string find(const string& x) {
        if(parent[x] != x){
            // x对parent的权重依赖于中间节点的权重
            string temp = find(parent[x]);
            // 让x权值是x除以其parent的值
            weight[x] *= weight[parent[x]];
            parent[x] = temp;
        }
        return parent[x];
    }
public:
    void join(const string& a, const string& b, double v) {
        if(!parent.count(a)){
            weight[a] = 1;
            parent[a] = a;
        }
        if(!parent.count(b)){
            weight[b] = 1;
            parent[b] = b;
        }
        string a_parent = find(a);
        string b_parent = find(b);
        parent[b_parent] = a_parent;
        // 这个式子举例比较快
        weight[b_parent] = weight[a] * v / weight[b];
    }
    double ask(const string& a, const string& b) {
        if (!parent.count(a) || !parent.count(b)) {
            return -1;
        }
        if(find(a) != find(b)){
            return -1;
        }
        return weight[b] / weight[a];
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionSet unionset;
        for (int i = 0; i < equations.size(); i++) {
            unionset.join(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for(auto& query : queries){
            ans.push_back(unionset.ask(query[0], query[1]));
        }
        return ans;
    }
};
// @lc code=end

