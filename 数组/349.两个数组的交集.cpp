/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        for(int i = 0, j = 0; i < nums1.size() && j < nums2.size();){
            int num1 = nums1[i], num2 = nums2[j];
            if(num1 == num2){
                if(ans.empty() || num1 != ans.back()){
                    ans.emplace_back(num1);
                }
                i++;
                j++;
            }
            else if(num1 < num2){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};
// @lc code=end

