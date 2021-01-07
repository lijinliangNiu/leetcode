/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int i) {
        int size = isConnected.size();
        for (int j = 0; j < size; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int province_size = isConnected.size();
        vector<int> visited(province_size);
        int ans = 0;
        for (int i = 0; i < province_size; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int province_size = isConnected.size();
        vector<int> visited(province_size, 0);
        queue<int> q;
        int ans = 0;
        for(int i = 0; i < province_size; i++){
            if(visited[i] == 0){
                q.push(i);
                while(!q.empty()){
                    int j = q.front();
                    q.pop();
                    visited[j] = 1;
                    for(int k = 0; k < province_size; k++){
                        if(isConnected[j][k] == 1 && visited[k] == 0){
                            q.push(k);
                        }
                    }
                }
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end