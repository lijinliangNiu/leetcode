/*
 * @lc app=leetcode.cn id=1675 lang=cpp
 *
 * [1675] 数组的最小偏移量
 */

// @lc code=start
class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int mi = INT_MAX;
        priority_queue<int> q;
        for(int i = 0; i < a.size(); i++){
            if(a[i] & 1){
                a[i] *= 2;
            }
            q.push(a[i]);
            mi = min(mi, a[i]);
        }
        int ans = INT_MAX;
        while(true){
            int cur_max = q.top();
            q.pop();
            ans = min(ans, cur_max - mi);
            if(cur_max & 1){
                break;
            }
            mi = min(mi, cur_max / 2);
            q.push(cur_max / 2);
        }
        return ans;
    }
};
// @lc code=end

