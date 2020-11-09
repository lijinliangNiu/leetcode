/*
 * @lc app=leetcode.cn id=1356 lang=cpp
 *
 * [1356] 根据数字二进制下 1 的数目排序
 */

// @lc code=start
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> one_num(10001, 0);
        for(int i = 1; i <= 10000; i++){
            one_num[i] = one_num[i >> 1] + (i & 1);
        }
        sort(arr.begin(), arr.end(), [&](int x, int y){
            if(one_num[x] < one_num[y]){
                return true;
            }
            if(one_num[x] > one_num[y]){
                return false;
            }
            return x < y;
        });
        return arr;
    }
};
// @lc code=end

