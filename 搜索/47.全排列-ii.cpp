/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int pos){
        if(pos == nums.size() - 1){
            ans.push_back(nums);
        }
        else{
            for(int i = pos; i < nums.size(); i++){
                bool same_number = false;
                for(int j = pos; j < i; j++){
                    if(nums[j] == nums[i]){
                        same_number = true;
                    }
                }
                if(!same_number){
                    swap(nums[pos], nums[i]);
                    dfs(nums, pos + 1);
                    swap(nums[pos], nums[i]);
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};
// @lc code=end

