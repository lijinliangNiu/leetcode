/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
private:
    //i: nums1的起始位置 j: nums2的起始位置
    int find_kth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(i >= nums1.size()){
            return nums2[j + k - 1];
        }
        if(j >= nums2.size()){
            return nums1[i + k - 1];
        }
        if(k == 1){
            return min(nums1[i], nums2[j]);
        }
        //第k / 2小的数字，没有就置最大来删掉另一个数组的前k / 2
        int min_val1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int min_val2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        //不断删掉k / 2个元素
        if(min_val1 < min_val2){
            return find_kth(nums1, i + k / 2, nums2, j, k - k / 2);
        }
        else{
            return find_kth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if((m + n) % 2 == 0){
            int left = find_kth(nums1, 0, nums2, 0, (m + n) / 2);
            int right = find_kth(nums1, 0, nums2, 0, (m + n) / 2 + 1);
            return (left + right) / 2.0;
        }
        else{
            return find_kth(nums1, 0, nums2, 0, (m + n) / 2 + 1);
        }
    }
};
// @lc code=end

