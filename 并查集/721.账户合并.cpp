/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */

// @lc code=start
class Solution {
private:
    vector<int> parent;
    void init(int n){
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {   
        int n = accounts.size();
        init(n);
        unordered_map<string, int> email_to_id;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string email = accounts[i][j];
                if(!email_to_id.count(email)){
                    email_to_id[email] = i;
                }
                else{
                    join(i, email_to_id[email]);
                }
            }
        }
        unordered_map<int, vector<string>> id_to_email;
        for(auto& [email, id] : email_to_id){
            id_to_email[find(id)].emplace_back(email);
        }
        vector<vector<string>> ans;
        for(auto& [id, emails] : id_to_email){
            sort(emails.begin(), emails.end());
            vector<string> account;
            account.emplace_back(accounts[id][0]);
            account.insert(account.end(), emails.begin(), emails.end());
            ans.emplace_back(account);
        }
        return ans;
    }
};
// @lc code=end

