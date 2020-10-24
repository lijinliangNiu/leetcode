/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

// @lc code=start
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        //因为后边要+1所以用max-1
        vector<int> dp(T + 1, INT_MAX - 1);
        dp[0] = 0;
        //对每个可能的时间t和所有时间段，如果t在时间段内，进行状态转移
        for(int i = 1; i <= T; i++){
            for(const auto& clip : clips){
                if(clip[0] < i && i <= clip[1]){
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {    
        //对于所有左端点相同的区间，其右越远越有利，且最佳方案中不可能出现两个左端点相同的区间。
        //对于每一个位置，记录其可达的最远位置。
        vector<int> max_reach(T);
        for(const auto& clip : clips){
            if(clip[0] < T){
                max_reach[clip[0]] = max(max_reach[clip[0]], clip[1]);
            }
        }
        int ans = 0;
        //reach：当前位置可到达的最远位置
        //pre_reach：上一个被使用的区间到达的位置
        int reach = 0, pre_reach = 0;
        //枚举每个位置
        for(int i = 0; i < T; i++){
            reach = max(reach, max_reach[i]);
            if(i == reach){
                return -1;
            }
            if(i == pre_reach){
                ans++;
                pre_reach = reach;
            }
        }
        return ans;
    }
};
// @lc code=end

