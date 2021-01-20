/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index;
        for(int i = 0; i < k; i++){
            while(!index.empty() && nums[i] > nums[index.back()]){
                index.pop_back();
            }
            index.emplace_back(i);
        }
        vector<int> ans;
        ans.emplace_back(nums[index.front()]);
        for(int i = k; i < nums.size(); i++){
            if(index.front() < i - k + 1){ // 超出队长的得出去
                index.pop_front();
            }
            while(!index.empty() && nums[i] > nums[index.back()]){ // 后来的大的把前边小的都挤走
                index.pop_back();
            }
            index.emplace_back(i); // 所有新来的都进去
            ans.emplace_back(nums[index.front()]); // 队首是最大值
        }
        return ans;
    }
};
// @lc code=end

