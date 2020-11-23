/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        //结果肯定为若干右端点的集合
        sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v){
            return u[1] < v[1];
        });
        int pos = points[0][1];
        int ans = 1;
        for(auto& point: points){
            if(point[0] > pos){//这根到不了的右端点最近的，且右端点更远的能被这根射中的肯定能被下一根射中
                pos = point[1];
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

