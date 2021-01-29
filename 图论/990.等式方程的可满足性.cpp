/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 */

// @lc code=start
class Solution {
private:
    vector<int> parent = vector<int>(26);
    void init(){
        //赋值为0, 1, 2, ...
        iota(parent.begin(), parent.end(), 0);
    }
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
    bool equationsPossible(vector<string>& equations) {
        init();
        for(string& equation : equations){
            if(equation[1] == '='){
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                join(a, b);
            }
        }
        for(string& equation : equations){
            if(equation[1] == '!'){
                int a = equation[0] - 'a';
                int b = equation[3] - 'a';
                if(find(a) == find(b)){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

