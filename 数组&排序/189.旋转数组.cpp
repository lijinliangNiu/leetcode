/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for(int start = 0, count = 0; count < nums.size(); start++){
            int start_back = start;
            while (true){
                int next = (start + k) % nums.size();
                swap(nums[next], nums[start_back]);
                count++;
                start = next;
                if(start_back == start){
                    break;
                }
            }
        }
    }
};
// @lc code=end

