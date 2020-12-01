/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
class Solution {   
private: 
    int count_reverse_pairs(vector<int>& nums, int left, int right){//统计两个数组的翻转对
        int ans = 0;
        int mid = left + (right - left) / 2;
        int j = mid + 1;
        for(int i = left; i <= mid; i++){
            while (j <= right && (long long)nums[i] > 2 * (long long)nums[j]) {
                j++;
            }
            ans += (j - mid - 1);
        }
        return ans;
    }

    int reverse_pairs(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        } 
        else {
            int mid = left + (right - left) / 2;
            int ans = reverse_pairs(nums, left, mid) + reverse_pairs(nums, mid + 1, right) + count_reverse_pairs(nums, left, right);

            // 合并两个数组
            vector<int> sorted(right - left + 1);
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = nums[p2++];
                } 
                else if (p2 > right) {
                    sorted[p++] = nums[p1++];
                } 
                else {
                    if (nums[p1] < nums[p2]) {
                        sorted[p++] = nums[p1++];
                    } 
                    else {
                        sorted[p++] = nums[p2++];
                    }
                }
            }
            for (int i = 0; i < sorted.size(); i++) {
                nums[left + i] = sorted[i];
            }
            return ans;
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        return reverse_pairs(nums, 0, nums.size() - 1);
    }
};
// @lc code=end

