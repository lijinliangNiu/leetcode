/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int& stone: stones){
            q.push(stone);
        }
        while(q.size() > 1){
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if(x != y){
                q.push(x - y);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};
// @lc code=end

