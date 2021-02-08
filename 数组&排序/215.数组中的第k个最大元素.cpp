/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
private:
    mt19937 gen{random_device{}()};
    int random_select(vector<int>& arr, int left, int right, int k){
        swap(arr[right], arr[uniform_int_distribution<int>{left, right}(gen)]);//arr[r]就是pivot
        int i = left; //待交换位置
        for(int j = left; j < right; j++){
            if(arr[j] <= arr[right]){
                swap(arr[i++], arr[j]);
            }
        }
        swap(arr[i], arr[right]);//pivot归位
        int less_num = i - left + 1;
        if(less_num == k){
            return arr[i];
        }
        else if(less_num > k){
            return random_select(arr, left, i - 1, k);
        }
        else{
            return random_select(arr, i + 1, right, k - less_num);
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return random_select(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
};
// @lc code=end

