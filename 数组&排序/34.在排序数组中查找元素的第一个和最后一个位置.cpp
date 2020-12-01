/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
private:
    int lower_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(target <= nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }    
    int upper_bound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(target < nums[mid]){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }  
        }
        return left;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, target);
        int right = upper_bound(nums, target);
        if(left == right){
            return {-1, -1};
        }
        return {left, right - 1};
    }
};
// @lc code=end

