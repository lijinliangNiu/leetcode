/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[0]){
                if(target > nums[mid]){
                    l = mid + 1;
                }
                else if(target < nums[mid] && target >= nums[0]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(target < nums[mid]){
                    r = mid - 1;
                }
                else if(target > nums[mid] && target <= nums[nums.size() - 1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

