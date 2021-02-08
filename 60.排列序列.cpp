/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n);
        factorial[0] = 1;
        for (int i = 1; i < n; i++) {
            factorial[i] = i * factorial[i - 1];
        }
        k--; // f 和 nums 对应
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        string ans;
        for (int i = 1; i <= n; i++) {
            int order = k / factorial[n - i];
            ans.push_back(nums[order] + '0');
            for (int j = order; j < n - i; j++) {
                nums[j] = nums[j + 1];
            }
            k %= factorial[n - i];
        }
        return ans;
    }
};
// @lc code=end

