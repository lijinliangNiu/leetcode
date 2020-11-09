/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
class Solution {
private:
    mt19937 gen{random_device{}()};
    void random_select(vector<vector<int>>& points, int left, int right, int K) {
        int pivot = uniform_int_distribution<int>{left, right}(gen);
        int pivot_val = points[pivot][0] * points[pivot][0] + points[pivot][1] * points[pivot][1];
        swap(points[right], points[pivot]);
        int i = left;
        for (int j = left; j < right; j++) {
            int dist = points[j][0] * points[j][0] + points[j][1] * points[j][1];
            if (dist <= pivot_val) {
                swap(points[i++], points[j]);
            }
        }
        swap(points[i], points[right]);
        int less_num = i - left + 1;
        if (K < less_num) {
            random_select(points, left, i - 1, K);
        }
        else if (K > less_num) {
            random_select(points, i + 1, right, K - less_num);
        }
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        random_select(points, 0, points.size() - 1, K);
        return {points.begin(), points.begin() + K};
    }
};
// @lc code=end

